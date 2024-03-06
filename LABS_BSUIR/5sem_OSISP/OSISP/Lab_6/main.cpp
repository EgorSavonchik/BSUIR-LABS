#include <Windows.h>
#include <vector>
#include <iostream>
#include <syncstream>
#include <algorithm>
#include <string>
#include <iomanip>
#include <exception>
#include <chrono>
#include <sstream>



class MultiReaderSingleWriter
{
private:
    CRITICAL_SECTION m_csWrite;
    CRITICAL_SECTION m_csReaderCount;
    long m_cReaders;
    HANDLE m_hevReadersCleared;

public:
    MultiReaderSingleWriter()
    {
        m_cReaders = 0;
        InitializeCriticalSection(&m_csWrite);
        InitializeCriticalSection(&m_csReaderCount);
        m_hevReadersCleared = CreateEvent(NULL, TRUE, TRUE, NULL);
        //ResetEvent(m_hevReadersCleared);
    }

    ~MultiReaderSingleWriter()
    {
        WaitForSingleObject(m_hevReadersCleared, INFINITE);
        CloseHandle(m_hevReadersCleared);
        DeleteCriticalSection(&m_csWrite);
        DeleteCriticalSection(&m_csReaderCount);
    }


    void EnterReader(void)
    {
        EnterCriticalSection(&m_csWrite);
        EnterCriticalSection(&m_csReaderCount);
        if (++m_cReaders == 1)
            ResetEvent(m_hevReadersCleared);
        LeaveCriticalSection(&m_csReaderCount);
        LeaveCriticalSection(&m_csWrite);
    }

    void LeaveReader(void)
    {
        EnterCriticalSection(&m_csReaderCount);
        if (--m_cReaders == 0)
            SetEvent(m_hevReadersCleared);
        LeaveCriticalSection(&m_csReaderCount);
    }

    void EnterWriter(void)
    {
        EnterCriticalSection(&m_csWrite);
        WaitForSingleObject(m_hevReadersCleared, INFINITE);
    }

    void LeaveWriter(void)
    {
        LeaveCriticalSection(&m_csWrite);
    }
};

MultiReaderSingleWriter locker;

DWORD WINAPI read_func(LPVOID lpParam) {
    locker.EnterReader();
    for (int i = 0; i < 300; i++)
        std::cout << i << ' ';
    std::cout << '\n';
    locker.LeaveReader();

    return 0;
}

DWORD WINAPI write_func(LPVOID lpParam) {
    locker.EnterWriter();
    for (int i = 0; i < 26; i++)
        std::cout << char('a' + i) << ' ';
    std::cout << '\n';
    locker.LeaveWriter();

    return 0;
}

int main()
{

    //MRSW::write = write_func;
    //MRSW::start(3, 3);
    HANDLE writers[3], readers[3];

    for (int i = 0; i < 3; i++) {
        writers[i] = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)write_func,
            NULL, 0, NULL);
    }

    for (int i = 0; i < 3; i++) {
        readers[i] = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)read_func,
            NULL, 0, NULL);
    }



    WaitForMultipleObjects(3, writers, TRUE, INFINITE);
    WaitForMultipleObjects(3, readers, TRUE, INFINITE);
}

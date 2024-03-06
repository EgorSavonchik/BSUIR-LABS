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


HANDLE hMutex;
HANDLE mapping;


DWORD WINAPI proc(LPVOID lParam) {
    while (true) {
        WaitForSingleObject(hMutex, INFINITE);
        HANDLE hMapFile = OpenFileMapping(
            FILE_MAP_ALL_ACCESS,   // read/write access
            FALSE,                 // do not inherit the name
            L"Local\\MappingFile");

        LPCTSTR pBuf = (LPTSTR)MapViewOfFile(hMapFile, // handle to map object
            FILE_MAP_ALL_ACCESS,  // read/write permission
            0,
            0,
            256);

        std::string s((char*)pBuf);
        long long n;

        std::stringstream ss;
        ss << s;
        ss >> n;

        n *= 2;

        if (n > INT_MAX) {
            break;
        }

        CopyMemory((PVOID)pBuf, std::to_string(n).c_str(), 256);

        UnmapViewOfFile(pBuf);

        std::cout << "Proc " << GetCurrentThreadId() << ' ' << n << "\n";


        CloseHandle(hMapFile);
        Sleep(100);
        ReleaseMutex(hMutex);
    }

    return 0;
}



int main()
{
    srand(time(0));
    int n;

    mapping = CreateFileMapping(nullptr,
        nullptr,
        PAGE_READWRITE,
        0,
        256,
        L"Local\\MappingFile");

    if (!mapping) {
        std::cerr << "Error whilw creating mapping file: " << GetLastError();
        return 1;
    }

    hMutex = CreateMutex(NULL, FALSE, NULL);

    if (!hMutex) {
        CloseHandle(mapping);
        std::cerr << "Error whilw creating mutex: " << GetLastError();
        return 1;
    }

    std::cout << "Enter the number: ";
    std::cin >> n;

    LPCTSTR pBuf;
    pBuf = (LPTSTR)MapViewOfFile(mapping,   // handle to map object
        FILE_MAP_ALL_ACCESS, // read/write permission
        0,
        0,
        256);

    if (pBuf == NULL)
    {

        std::cerr << "Could not map view of file .\n" << GetLastError();

        CloseHandle(mapping);
        CloseHandle(hMutex);

        return 1;
    }

    CopyMemory((PVOID)pBuf, std::to_string(n).c_str(), 256);
    //_getch();

    UnmapViewOfFile(pBuf);

    HANDLE thHandles[2];

    unsigned long a = 1, b = 2;

    thHandles[0] = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)proc,
        NULL, 0, &a);

    thHandles[1] = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)proc,
        NULL, 0, &b);

    WaitForMultipleObjects(2, thHandles, TRUE, INFINITE);

    CloseHandle(thHandles[0]);
    CloseHandle(thHandles[1]);

    CloseHandle(hMutex);
}

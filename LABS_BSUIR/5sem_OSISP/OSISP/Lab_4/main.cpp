#include <iostream>
#include <Windows.h>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include <fstream>

struct _param {
    LPOVERLAPPED _overlapped;
    LPOVERLAPPED _woverlapped;
    int i;
};


HANDLE hFile;
HANDLE hMutex;
const std::string file_name{ "test.txt" };
std::vector<int> lines_size;
std::vector<std::vector<BYTE>> file_buf;
std::vector<int> offsets;
std::vector<OVERLAPPED> laped_vec;

int find_i(int offset) {
    return std::distance(offsets.begin(),
        std::find(offsets.begin(), offsets.end(), offset));
}

int get_offset(int line_num) {
    int offset = 0;

    for (int i = 0; i < line_num; i++) {
        offset += lines_size[i] + 3;
    }

    return offset;
}

VOID close_write(DWORD dwErrorCode, DWORD dwNumberOfBytesTransfered, LPOVERLAPPED lpOverlapped) {
    CloseHandle(lpOverlapped->hEvent);
}

VOID sort_nums(DWORD dwErrorCode, DWORD dwNumberOfBytesTransfered, LPOVERLAPPED lpOverlapped) {
    std::string line;
    std::stringstream cont;
    std::vector<int> nums;
    int offset = lpOverlapped->Offset;
    int i = find_i(offset);
    std::vector<BYTE> buf = file_buf[i];
    int num;

    for (auto x : buf) {
        line += x;
    }

    cont << line;
    line.clear();

    while (cont >> num) {
        nums.push_back(num);
    }

    std::sort(nums.begin(), nums.end());

    for (auto x : nums)
        line += std::to_string(x) + ' ';

    line.erase(line.cend() - 1);

    buf.clear();
    for (auto x : line) {
#ifdef _DEBUG
        std::cout << x;
#endif // DEBUG

        buf.push_back(x);
    }

#ifdef _DEBUG
    std::cout << '\n';
#endif // DEBUG


    CloseHandle(lpOverlapped->hEvent);

    OVERLAPPED oWrite{ 0 };
    oWrite.hEvent = CreateEvent(NULL, TRUE, FALSE, NULL);
    oWrite.Offset = get_offset(i);

    WriteFileEx(hFile, &buf[0], lines_size[i], &oWrite, close_write);

    SleepEx(0, TRUE);

    return;
}

void sort_async(int n, int k) {
    hFile = CreateFile(L"C:\\Users\\HP\\Desktop\\labs\\LABS_BSUIR\\5sem_OSISP\\OSISP\\Lab_4\\test.txt", GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, FILE_FLAG_OVERLAPPED /*| FILE_FLAG_NO_BUFFERING*/, NULL);

    if (hFile == INVALID_HANDLE_VALUE) {
        std::cout << "File error";
        return;
    }

    std::vector<_param> oFiles;

    for (int i = 0; i < n; i++) {
        OVERLAPPED oRead{ 0 };
        oRead.hEvent = CreateEvent(NULL, TRUE, FALSE, NULL);
        oRead.Offset = get_offset(i);
        offsets.push_back(oRead.Offset);

        laped_vec.push_back(oRead);
    }

    for (int i = 0; i < n; i++) {

        const BOOL res = ReadFileEx(hFile, &(file_buf[i][0]), lines_size[i],
            &laped_vec[i], (LPOVERLAPPED_COMPLETION_ROUTINE)sort_nums);
        auto error_code = GetLastError();
        int r = 1;
    }

    SleepEx(0, TRUE);

    return;
}

int main()
{
    srand(time(0));
    int n, k;

    std::cout << "Enter num of lines: ";
    std::cin >> n;
    std::cout << "Enter num of nums: ";
    std::cin >> k;

    std::ofstream out(file_name);

#ifdef _DEBUG
    std::cout << "Unsorted: " << '\n';
#endif

    for (int i = 0; i < n; i++) {
        int size = 0;

        for (int j = 0; j < k; j++) {
            int num = std::rand() % 100 + 1;
#ifdef _DEBUG
            std::cout << num << ' ';
#endif
            out << num << ' ';
            size += std::to_string(num).size() + 1;
        }
        out << '\n';
#ifdef _DEBUG
        std::cout << '\n';
#endif
        size--;
        file_buf.push_back(std::vector<BYTE>(size));
        lines_size.push_back(size);
    }

    out.close();

#ifdef _DEBUG
    std::cout << "\n\nSorted: " << '\n';
#endif

    sort_async(n, k);

    int r = 1;
}
#include <Windows.h>
#include <vector>
#include <iostream>
#include <syncstream>
#include <algorithm>
#include <string>
#include <iomanip>
#include <exception>
#include <chrono>

HANDLE hMutex;

struct param {
    param(int start, int end, std::vector<int>* v) : start(start), end(end), v(v) {}
    int start;
    int end;
    std::vector<int>* v;
};

struct merge_param {
    merge_param(int start, int mid, int end, std::vector<int>* v) :
        start(start), mid(mid), end(end), v(v) {}

    int start;
    int mid;
    int end;
    std::vector<int>* v;
};

DWORD WINAPI _merge(LPVOID lParam) {
    int start = ((merge_param*)lParam)->start;
    int mid = ((merge_param*)lParam)->mid;
    int end = ((merge_param*)lParam)->end;
    std::vector<int>* arr = ((merge_param*)lParam)->v;

    if (mid >= end || start >= end || start >= arr->size())
        return 0;

    std::vector<int> tmp;
    std::merge(arr->begin() + start, arr->begin() + mid,
        arr->begin() + mid, arr->begin() + end,
        std::back_inserter(tmp));

    for (int i = start; i < end; i++) {
        arr->at(i) = tmp[i - start];
    }

    return 0;
}

DWORD WINAPI _sort(LPVOID lParam) {
    int start = ((param*)lParam)->start;
    int end = ((param*)lParam)->end;
    std::vector<int>* arr = ((param*)lParam)->v;

    std::sort(arr->begin() + start, arr->begin() + end);

    WaitForSingleObject(hMutex, INFINITE);
    ReleaseMutex(hMutex);

    return 0;
}

void thread_sort(std::vector<int>& arr, int k) {
    int chunk_size = arr.size() / k;
    int thread_num = k;
    bool is_dec = true;

    if (chunk_size * k != arr.size()) {
        is_dec = false;
        thread_num++;
    }

    HANDLE thread_handle[64];
    hMutex = CreateMutex(NULL, FALSE, NULL);
    std::vector<param*> params;

    for (int i = 0; i < thread_num; i++) {
        if (i == thread_num - 1 && !is_dec) [[unlikely]] {
            param* pass_param = new param(i * chunk_size, arr.size(), &arr);
            params.push_back(pass_param);
            thread_handle[i] = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)_sort,
                (void*)pass_param, 0, NULL);
        }
        else [[likely]] {
            param* pass_param = new param(i * chunk_size, (i + 1) * chunk_size, &arr);
            params.push_back(pass_param);
            thread_handle[i] = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)_sort,
                (void*)pass_param, 0, NULL);
        }
    }

    WaitForMultipleObjects(thread_num, thread_handle, TRUE, INFINITE);

    for (int i = 0; i < thread_num; i++) {
        CloseHandle(thread_handle[i]);
        delete params[i];
    }

    CloseHandle(hMutex);
}

void _merge(std::vector<int>& arr, int k) {
    int chunk_size = arr.size() / k;
    int thread_num = k;
    bool is_dec = true;

    if (chunk_size * k != arr.size()) {
        is_dec = false;
        thread_num++;
    }

    HANDLE thread_handle[64];

    for (int step = chunk_size; step < arr.size(); step *= 2) {
        std::vector<merge_param*> params;
        for (int i = 0; i < floor(arr.size() / (double(chunk_size * 2.0))); i++) {
            int start = i * step * 2;
            int mid = start + step;
            int end = min(arr.size(), start + 2 * step);

            merge_param* param = new merge_param(start, mid, end, &arr);
            params.push_back(param);

            thread_handle[i] = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)_merge,
                (void*)param, 0, NULL);
        }

        WaitForMultipleObjects(floor(arr.size() / (double(chunk_size * 2.0))), thread_handle,
            TRUE, INFINITE);

        for (int i = 0; i < floor(arr.size() / (double(chunk_size * 2.0))); i++) {
            CloseHandle(thread_handle[i]);
            thread_handle[i] = NULL;
            delete params[i];
        }

        params.clear();
    }
}

int main()
{
    srand(time(0));

    int n, k;
    std::cout << "Enter size of arr: ";
    std::cin >> n;
    std::cout << "Enter num of threads: ";
    std::cin >> k;

    std::vector<int> arr(n);


    std::cout << "Unsorted: \n";

    for (auto& x : arr) {
        x = std::rand() % 100 + 1;
        std::cout << x << ' ';
    }
    std::cout << '\n';

    std::vector<int> tmp(arr);

    const auto start_thread = std::chrono::high_resolution_clock::now();
    thread_sort(arr, k);
    _merge(arr, k);
    const std::chrono::duration<double> diff_thread =
        std::chrono::high_resolution_clock::now() - start_thread;



    std::cout << '\n';
    std::cout << "Sorted: ";
    for (auto x : arr) {
        std::cout << x << ' ';
    }
    std::cout << '\n';

    const auto start_single = std::chrono::high_resolution_clock::now();
    std::sort(tmp.begin(), tmp.end());
    const std::chrono::duration<double> diff_single =
        std::chrono::high_resolution_clock::now() - start_single;

    std::cout << "Thread sort: " << std::fixed << std::setprecision(6) <<
        diff_thread.count() << '\n';
    std::cout << "Single sort: " << std::fixed << std::setprecision(6) <<
        diff_single.count() << '\n';
}

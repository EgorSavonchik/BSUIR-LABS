#include <windows.h>
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <fstream>
#include <vector>


HWND hwndEdit;
HWND hwndLabel;

std::vector<std::wstring> messages = {
    L"Ты не сможешь его закрыть",
    L"Невозможно",
    L"Без шансов",
    L"Диспетчер задач\n тебе не поможет",
};

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    switch (uMsg)
    {
    case WM_CREATE:
    {
        hwndEdit = CreateWindowEx(WS_EX_CLIENTEDGE, L"EDIT", L"", WS_CHILD | WS_VISIBLE | ES_AUTOHSCROLL,
            50, 50, 200, 30, hwnd, NULL, NULL, NULL);

        hwndLabel = CreateWindow(L"STATIC", messages[rand() % messages.size()].c_str(), WS_CHILD | WS_VISIBLE | SS_CENTER,
            50, 180, 200, 40, hwnd, NULL, NULL, NULL);

        std::wifstream file(L"file.txt");
        if (file.is_open()) {
            file.imbue(std::locale("ru_RU.utf8")); // Устанавливаем локаль

            std::wstring content((std::istreambuf_iterator<wchar_t>(file)),
                (std::istreambuf_iterator<wchar_t>()));

            SetWindowTextW(hwndEdit, content.c_str());
            file.close();
        }

        break;
    }
    case WM_COMMAND:

        break;

    case WM_KEYDOWN:
        if (wParam == VK_ESCAPE)
        {
            DeleteFile(L"file.txt");
            DestroyWindow(hwnd);
            PostMessage(hwnd, WM_DESTROY, 0, 0);
            //PostMessage(hwnd, WM_CLOSE, 0, 0); // Посылаем сообщение на закрытие окна
        }

        break;

    case WM_CLOSE:
    {
        std::wstring buffer(256, L'\0');
        SendMessage(hwndEdit, WM_GETTEXT, buffer.size(), (LPARAM)buffer.data());

        std::wofstream file(L"file.txt", std::ios::out | std::ios::binary);

        if (file.is_open())
        {
            file.imbue(std::locale("ru_RU.utf8")); // Устанавливаем локаль
            file << buffer;
            file.close();
        }


        const wchar_t *exePath = L"C:\\Users\\HP\\Desktop\\labs\\LABS_BSUIR\\5sem_OSISP\\OSISP\\x64\\Debug\\Lab_2.exe";

        // Запускаем новый процесс
        STARTUPINFO si = {};
        PROCESS_INFORMATION pi = {};

        CreateProcess(exePath, NULL, NULL, NULL, FALSE, 0, NULL, NULL, &si, &pi);

        CloseHandle(pi.hProcess);
        CloseHandle(pi.hThread);

        DestroyWindow(hwnd);

        break;
    }
        

    case WM_DESTROY:
        PostQuitMessage(0);
        break;

    default:
        return DefWindowProc(hwnd, uMsg, wParam, lParam);
    }
    return 0;
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
    std::srand(std::time(0) * 1000);

    // регистрация класса окна
    WNDCLASS wc = {};
    wc.lpfnWndProc = WindowProc;
    wc.hInstance = hInstance;
    wc.lpszClassName = L"SampleWindowClass";
    RegisterClass(&wc);

    // создание основного окна
    HWND hwnd = CreateWindowEx(0, L"SampleWindowClass", L"Бесконечный блокнот",
        WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT,
        300, 400, NULL, NULL, hInstance, NULL);

    // отображаем и обновляем окно
    ShowWindow(hwnd, nCmdShow);
    UpdateWindow(hwnd);

    // обработка сообщений
    MSG msg = {};
    while (GetMessage(&msg, NULL, 0, 0))
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return 0;
}

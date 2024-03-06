#include <windows.h>


HWND hwndEdit;
HWND hwndButton;
HWND hwndLabel;
HWND hwndList;
HWND hwndLabel2;
HWND hwndOnRadioButton;
HWND hwndOffRadioButton;
HWND hwndOnLabel;
HWND hwndOffLabel;



LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    switch (uMsg)
    {
        case WM_CREATE:
            hwndEdit = CreateWindowEx(WS_EX_CLIENTEDGE, L"EDIT", L"", WS_CHILD | WS_VISIBLE | ES_AUTOHSCROLL,
                50, 50, 200, 30, hwnd, NULL, NULL, NULL);

            hwndButton = CreateWindow(L"BUTTON", L"Выполнить", WS_CHILD | WS_VISIBLE,
                50, 150, 200, 30, hwnd, (HMENU)1, NULL, NULL);

            hwndLabel = CreateWindow(L"STATIC", L"Введите имя", WS_CHILD | WS_VISIBLE,
                50, 20, 200, 20, hwnd, NULL, NULL, NULL);
            hwndLabel2 = CreateWindow(L"STATIC", L"Список учащихся", WS_CHILD | WS_VISIBLE,
                50, 180, 200, 20, hwnd, NULL, NULL, NULL);

          //  hwndOnLabel = CreateWindow(L"STATIC", L"Добавить учащегося", WS_CHILD | WS_VISIBLE,
          //      50, 130, 100, 20, hwnd, NULL, NULL, NULL);
          //  hwndOffLabel = CreateWindow(L"STATIC", L"Закрыть", WS_CHILD | WS_VISIBLE,
          //      50, 150, 100, 20, hwnd, NULL, NULL, NULL);

            hwndOnRadioButton = CreateWindowW(
                L"BUTTON", L"Добавить учащегося",  
                WS_CHILD | WS_VISIBLE | BS_AUTORADIOBUTTON | WS_GROUP, 
                50, 100, 200, 20,  
                hwnd, (HMENU)3, NULL, NULL);  
            SendMessage(hwndOnRadioButton, BM_SETCHECK, BST_CHECKED, 0); // активирована по умолчанию

            hwndOffRadioButton = CreateWindowW(
                L"BUTTON", L"Удалить учащегося",
                WS_CHILD | WS_VISIBLE | BS_AUTORADIOBUTTON,
                50, 120, 200, 20,
                hwnd, (HMENU)4, NULL, NULL);

            hwndList = CreateWindowW(
                L"LISTBOX",   
                L"",         
                WS_CHILD | WS_VISIBLE | WS_BORDER | LBS_STANDARD, 
                50, 200, 200, 150, 
                hwnd,      
                (HMENU)2,   
                NULL,
                NULL
            );

            break;

        case WM_COMMAND:
            if (LOWORD(wParam) == 1) // обработка нажатия кнопки 
            {
                wchar_t buffer[256];
                GetWindowText(hwndEdit, buffer, 256);

                if (wcslen(buffer) == 0)
                {
                    MessageBox(hwnd, L"Вы ничего не ввели", L"Ошибка", MB_OK | MB_ICONERROR);
                }
                else if(SendMessage(hwndOnRadioButton, BM_GETCHECK, 0, 0) == BST_CHECKED)
                {
                    SendMessage(hwndList, LB_ADDSTRING, 0, (LPARAM)buffer);

                    wchar_t result[300];
                    wsprintf(result, L"%s добавлен", buffer);

                    // диалоговое окно с текстом из поля ввода
                    MessageBox(hwnd, result, L"Добавить учащегося", MB_OK | MB_ICONINFORMATION);
                }
                else if (SendMessage(hwndOnRadioButton, BM_GETCHECK, 0, 0) != BST_CHECKED)
                {
                    wchar_t buffer[256];
                    GetWindowText(hwndEdit, buffer, 256);

                    int index = SendMessage(hwndList, LB_FINDSTRING, -1, (LPARAM)buffer);

                    if (index != LB_ERR) {
                        // элемент найден, удаляем его
                        SendMessage(hwndList, LB_DELETESTRING, index, 0);
                    }
                    else {
                        // элемент не найден
                        MessageBox(hwnd, L"Элемент не найден", L"Ошибка", MB_OK | MB_ICONERROR);
                    }
                }

                SendMessage(hwndEdit, WM_SETTEXT, 0, (LPARAM)L"");
                break;
            }
        
            break;

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
    // регистрация класса окна
    WNDCLASS wc = {};
    wc.lpfnWndProc = WindowProc;
    wc.hInstance = hInstance;
    wc.lpszClassName = L"SampleWindowClass";
    RegisterClass(&wc);

    // создание основного окна
    HWND hwnd = CreateWindowEx(0, L"SampleWindowClass", L"Встречающая машина",
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

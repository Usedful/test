#include <windows.h>

#pragma comment(lib, "user32.lib")
#pragma comment(lib, "gdi32.lib")
#pragma comment(lib, "kernel32.lib")

LRESULT CALLBACK WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

HWND hEdit;

void create_calculator(HWND hWnd);

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd)
{
    static TCHAR szClassName[] = TEXT("The Standard Window");
    static TCHAR szTitleOfWindow[] = TEXT("Calculator");

    WNDCLASSEX wnd;
    MSG msg;

    HWND hWnd;

    wnd.cbSize = sizeof(WNDCLASSEX);
    wnd.cbClsExtra = 0;
    wnd.cbWndExtra = 0;
    wnd.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
    wnd.hCursor = LoadCursor(NULL, IDC_ARROW);
    wnd.hIcon = LoadIcon(NULL, IDI_APPLICATION);
    wnd.hIconSm = LoadIcon(NULL, IDI_APPLICATION);
    wnd.hInstance = hInstance;
    wnd.lpfnWndProc = WndProc;
    wnd.lpszClassName = szClassName;
    wnd.lpszMenuName = NULL;
    wnd.style = CS_HREDRAW | CS_VREDRAW;

    if(!RegisterClassEx(&wnd))
    {
        MessageBox(NULL, TEXT("Error in allocating window class"), TEXT("RegisterClassEx"), MB_TOPMOST | MB_ICONERROR);
        ExitProcess(EXIT_FAILURE);
    }

    hWnd = CreateWindowEx(WS_EX_APPWINDOW, szClassName, szTitleOfWindow, WS_OVERLAPPEDWINDOW,
                            CW_USEDEFAULT, CW_USEDEFAULT, 600, 600,
                            NULL, NULL, hInstance, NULL);

    if(hWnd == NULL)
    {
        MessageBox(NULL, TEXT("Error in creating window"), TEXT("CreateWindowEx"), MB_ICONERROR | MB_TOPMOST);
        ExitProcess(EXIT_FAILURE);
    }

    UpdateWindow(hWnd);
    ShowWindow(hWnd, nShowCmd);

    while(GetMessage(&msg, NULL, 0, 0))
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return (msg.wParam);
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    switch(uMsg)
    {
        case WM_COMMAND:
            switch(wParam)
            {
                case 1:
                    SetWindowText(hEdit, "1");
                    break;

                case 2:
                    SetWindowText(hEdit, "2");
                    break;

                case 3:
                    SetWindowText(hEdit, "3");
                    break;

                case 4:
                    SetWindowText(hEdit, "4");
                    break;

                case 5:
                    SetWindowText(hEdit, "5");
                    break;

                case 6:
                    SetWindowText(hEdit, "6");
                    break;

                case 7:
                    SetWindowText(hEdit, "7");
                    break;

                case 8:
                    SetWindowText(hEdit, "8");
                    break;

                case 9:
                    SetWindowText(hEdit, "9");
                    break;

                case 0:
                    SetWindowText(hEdit, "0");
                    break;
            }
            break;

        case WM_CREATE:
            create_calculator(hWnd);
            break;

        case WM_DESTROY:
            PostQuitMessage(0);
            break;
    }

    return (DefWindowProc(hWnd, uMsg, wParam, lParam));
}

void create_calculator(HWND hWnd)
{
    hEdit = CreateWindow("EDIT",
                                "",
                                WS_VISIBLE | WS_CHILD | WS_BORDER,
                                10, 10, 400, 30,
                                hWnd, NULL, NULL, NULL);

    CreateWindow("BUTTON",
                    "1",
                    WS_VISIBLE | WS_CHILD | WS_BORDER,
                    10, 42, 98, 30,
                    hWnd, (HMENU)1, NULL, NULL);

    CreateWindow("BUTTON",
                    "2",
                    WS_VISIBLE | WS_CHILD | WS_BORDER,
                    108, 42, 98, 30,
                    hWnd, (HMENU)2, NULL, NULL);

    CreateWindow("BUTTON",
                    "3",
                    WS_VISIBLE | WS_CHILD | WS_BORDER,
                    206, 42, 98, 30,
                    hWnd, (HMENU)3, NULL, NULL);

    CreateWindow("BUTTON",
                    "+",
                    WS_VISIBLE | WS_CHILD | WS_BORDER,
                    304, 42, 98, 30,
                    hWnd, NULL, NULL, NULL);

    CreateWindow("BUTTON",
                    "4",
                    WS_VISIBLE | WS_CHILD | WS_BORDER,
                    10, 72, 98, 30,
                    hWnd, (HMENU)4, NULL, NULL);

    CreateWindow("BUTTON",
                    "5",
                    WS_VISIBLE | WS_CHILD | WS_BORDER,
                    108, 72, 98, 30,
                    hWnd, (HMENU)5, NULL, NULL);

    CreateWindow("BUTTON",
                    "6",
                    WS_VISIBLE | WS_CHILD | WS_BORDER,
                    206, 72, 98, 30,
                    hWnd, (HMENU)6, NULL, NULL);

    CreateWindow("BUTTON",
                    "-",
                    WS_VISIBLE | WS_CHILD | WS_BORDER,
                    304, 72, 98, 30,
                    hWnd, NULL, NULL, NULL);

    CreateWindow("BUTTON",
                    "7",
                    WS_VISIBLE | WS_CHILD | WS_BORDER,
                    10, 102, 98, 30,
                    hWnd, (HMENU)7, NULL, NULL);

    CreateWindow("BUTTON",
                    "8",
                    WS_VISIBLE | WS_CHILD | WS_BORDER,
                    108, 102, 98, 30,
                    hWnd, (HMENU)8, NULL, NULL);

    CreateWindow("BUTTON",
                    "9",
                    WS_VISIBLE | WS_CHILD | WS_BORDER,
                    206, 102, 98, 30,
                    hWnd, (HMENU)9, NULL, NULL);

    CreateWindow("BUTTON",
                    "x",
                    WS_VISIBLE | WS_CHILD | WS_BORDER,
                    304, 102, 98, 30,
                    hWnd, NULL, NULL, NULL);

    CreateWindow("BUTTON",
                    "=",
                    WS_VISIBLE | WS_CHILD | WS_BORDER,
                    10, 132, 98, 30,
                    hWnd, NULL, NULL, NULL);
                
    CreateWindow("BUTTON",
                    "0",
                    WS_VISIBLE | WS_CHILD | WS_BORDER,
                    108, 132, 98, 30,
                    hWnd, (HMENU)0, NULL, NULL);

    CreateWindow("BUTTON",
                    "<-",
                    WS_VISIBLE | WS_CHILD | WS_BORDER,
                    206, 132, 98, 30,
                    hWnd, NULL, NULL, NULL);

    CreateWindow("BUTTON",
                    "/",
                    WS_VISIBLE | WS_CHILD | WS_BORDER,
                    304, 132, 98, 30,
                    hWnd, NULL, NULL, NULL);
}
#include <stdio.h>
#include <windows.h>

int GlobalRunning;

LRESULT CALLBACK Win32MainWindowCallback(HWND Window, UINT Message, WPARAM wParam, LPARAM lParam)
{
    LRESULT Result = 0;
    if (Message == WM_QUIT  ||
        Message == WM_CLOSE ||
        Message == WM_DESTROY)
    {
        GlobalRunning = 0;
    }
    else {
        Result = DefWindowProcA(Window, Message, wParam, lParam);
    }

    return Result;
}


int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd){


WNDCLASSEX wc;

wc.cbSize = sizeof(wc);
wc.style = CS_HREDRAW | CS_VREDRAW;
wc.lpfnWndProc = Win32MainWindowCallback;
wc.cbClsExtra = 0;
wc.cbWndExtra = 0;
wc.hInstance = hInstance;
wc.hIcon = LoadIcon(0, IDI_APPLICATION);
wc.hCursor = LoadCursor(0, IDC_ARROW);
wc.hbrBackground =  (HBRUSH)(NULL_BRUSH);
wc.lpszMenuName = 0;
wc.lpszClassName = "window";
wc.hIconSm = LoadIcon(0, IDI_APPLICATION);

if(!RegisterClassEx(&wc)){
  MessageBoxA(NULL, "Error! Could not register class!aaaaaaaaaaaaaaaaaaa", "Ebert", MB_ICONEXCLAMATION | MB_OK);

}
else if(RegisterClassEx(&wc)){
  MessageBoxA(NULL, "Error! Could not register class!", "Ebert", MB_ICONEXCLAMATION | MB_OK);
}

CreateWindowEx(WS_EX_OVERLAPPEDWINDOW, wc.lpszClassName, "game", WS_EX_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, NULL, NULL, hInstance, NULL);
if(!CreateWindowEx(WS_EX_OVERLAPPEDWINDOW, wc.lpszClassName, "game", WS_EX_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, NULL, NULL, hInstance, NULL)){
MessageBox(NULL, "Error! Could not create window!", "Ebert", MB_ICONEXCLAMATION | MB_OK);
}

ShowWindow(CreateWindowEx(WS_EX_OVERLAPPEDWINDOW, wc.lpszClassName, "game", WS_EX_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, NULL, NULL, hInstance, NULL), SW_SHOW);
UpdateWindow(CreateWindowEx(WS_EX_OVERLAPPEDWINDOW, wc.lpszClassName, "game", WS_EX_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, NULL, NULL, hInstance, NULL));

}

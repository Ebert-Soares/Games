#include <stdio.h>
#include <windows.h>


LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam){
    switch(msg)
    {
        case WM_CLOSE:
            DestroyWindow(hwnd);
        break;
        case WM_DESTROY:
            PostQuitMessage(0);
        break;
        default:

            return DefWindowProc(hwnd, msg, wParam, lParam);
    }
    return 0;
}



int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd){

HWND hwnd;
MSG Msg;
WNDCLASSEX wc;



wc.cbSize = sizeof(WNDCLASSEX);
wc.style = CS_HREDRAW | CS_VREDRAW;
wc.lpfnWndProc = WndProc;
wc.cbClsExtra = 0;
wc.cbWndExtra = 0;
wc.hInstance = hInstance;
wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);
wc.hCursor = LoadCursor(NULL, IDC_ARROW);
wc.hbrBackground =  (HBRUSH)(COLOR_WINDOW+1);
wc.lpszMenuName = NULL;
wc.lpszClassName = "window";
wc.hIconSm = LoadIcon(NULL, IDI_APPLICATION);

if(!RegisterClassEx(&wc)){
  MessageBoxA(NULL, "Error! Could not register class!aaaaaaaaaaaaaaaaaaa", "Ebert", MB_ICONEXCLAMATION | MB_OK);

}
else if(RegisterClassEx(&wc)){
  MessageBoxA(NULL, "Error! Could not register class!", "Ebert", MB_ICONEXCLAMATION | MB_OK);
}


CreateWindowEx(WS_EX_OVERLAPPEDWINDOW, wc.lpszClassName, "aaaaaaaaaaa", WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, NULL, NULL, hInstance, NULL);
if(!CreateWindowEx(WS_EX_OVERLAPPEDWINDOW, wc.lpszClassName, "aaaaaaaaaaa", WS_EX_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, NULL, NULL, hInstance, NULL)){
MessageBox(NULL, "Error! Could not create window!", "Ebert", MB_ICONEXCLAMATION | MB_OK);
}



ShowWindow(CreateWindowEx(WS_EX_OVERLAPPEDWINDOW, wc.lpszClassName, "game", WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, NULL, NULL, hInstance, NULL), SW_SHOW);
UpdateWindow(CreateWindowEx(WS_EX_OVERLAPPEDWINDOW, wc.lpszClassName, "game", WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, NULL, NULL, hInstance, NULL));

while(GetMessage(&Msg, NULL, 0, 0) > 0)
   {
       TranslateMessage(&Msg);
       DispatchMessage(&Msg);
   }
   return Msg.wParam;


}

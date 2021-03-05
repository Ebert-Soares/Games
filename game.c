#include <stdio.h>
#include <windows.h>

int GlobalRunning;

LRESULT CALLBACK WindowProc(hwnd, msg, wParam, lParam){

MSG Message = {0};
for(;;){

 while(PeekMessage(&Message, 0, 0, 0, PM_REMOVE)){
   TranslateMessage(&Message);
   DispatchMessage(&Message);
 }
if(Message.message == WM_QUIT){
  break;}
}
return Message.wParam;

}



int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd){


WNDCLASSEX wc;

wc.cbSize = sizeof(wc);
wc.style = CS_HREDRAW | CS_VREDRAW;
wc.lpfnWndProc = WindowProc;
wc.cbClsExtra = 0;
wc.cbWndExtra = 0;
wc.hInstance = hInstance;
wc.hIcon = LoadIcon(0, IDI_APPLICATION);
wc.hCursor = LoadCursor(0, IDC_ARROW);
wc.hbrBackground =  (HBRUSH)(WHITE_BRUSH);
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

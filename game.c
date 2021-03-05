#include <stdio.h>
#include <windows.h>


int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd){
  MessageBox(NULL, "Hello World", "Ebert", MB_ICONEXCLAMATION | MB_OK);
  return 0;

  typedef struct _WNDCLASSEX
  {
      UINT cbSize;
      UINT style;
      WNDPROC lpfnWndProc;
      int cbClsExtra;
      int cbWndExtra;
      HANDLE hInstance;
      HICON hIcon;
      HCURSOR hCursor;
      HBRUSH hbrBackground;
      LPCTSTR lpszMenuName;
      LPCTSTR lpszClassName;
      HICON hIconSm;
  } WNDCLASSEX;

WNDCLASSEX wc = {0};


wc.cbSize = sizeof(WNDCLASSEX);
wc.style = CS_HREDRAW | CS_VREDRAW;
wc.lpfnWndProc = mainWndProc;
wc.cbClsExtra = 0;
wc.cbWndExtra = 0;
wc.hInstance = dxApp->appInstance;
wc.hIcon = LoadIcon(0, IDI_APPLICATION);
wc.hCursor = LoadCursor(0, IDC_ARROW);
wc.hbrBackground = HBRUSH GetStockObject(NULL_BRUSH);



wc.hIconSm = LoadIcon(0, IDI_APPLICATION);

}

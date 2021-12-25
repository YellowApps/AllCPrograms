#include <windows.h>
#include <stdlib.h>

int CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
ATOM RegWndClass(HINSTANCE, LPCTSTR);

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow){

    RegWndClass(hInstance, "window");

    HWND wnd = CreateWindow("window", "", WS_OVERLAPPEDWINDOW | WS_VISIBLE, 300, 200, 160, 165, NULL, NULL, hInstance, NULL);

    CreateWindow("static", "Classic Theme for Windows 7", WS_CHILD | WS_VISIBLE, 20, 20, 100, 40, wnd, NULL, hInstance, NULL);

    HWND btn = CreateWindow("button", "Enable", WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, 35, 60, 70, 20, wnd, (HMENU)1, hInstance, NULL);

    HWND btn2 = CreateWindow("button", "Disable", WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, 35, 85, 70, 20, wnd, (HMENU)2, hInstance, NULL);

    ShowWindow(wnd, nCmdShow);

    MSG msg = {0};
    while(GetMessage(&msg, NULL, 0, 0) != 0){
      TranslateMessage(&msg);
      DispatchMessage(&msg);
    }

    return msg.wParam;
}

int CALLBACK WndProc(HWND wnd, UINT msg, WPARAM wParam, LPARAM lParam){
  switch(msg){
    case(WM_DESTROY):
      PostQuitMessage(0);
      break;
    case WM_COMMAND:
      if(LOWORD(wParam) == 1){
        system("sc stop themes");
      }else if(LOWORD(wParam) == 2){
        system("sc start themes");
      }
      break;
    default:
      return DefWindowProc(wnd, msg, wParam, lParam);
  }
  return 0;
}

ATOM RegWndClass(HINSTANCE hInst, LPCTSTR Name){
  WNDCLASS wc = {0};
  wc.lpfnWndProc = (WNDPROC)WndProc;
  wc.style = CS_HREDRAW|CS_VREDRAW;
  wc.hInstance = hInst;
  wc.lpszClassName = Name;
  wc.hCursor = LoadCursor(NULL, IDC_ARROW);
  wc.hbrBackground = (HBRUSH)COLOR_APPWORKSPACE;
  return RegisterClass(&wc);
}

#include <windows.h>
#include <stdlib.h>

//Переменная для хранения текста из поля
char input1val[40];

int CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
ATOM RegWndClass(HINSTANCE, LPCTSTR);

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow){

    RegWndClass(hInstance, "window");

    //Окно
    HWND wnd = CreateWindow("window", "FileWriter", WS_OVERLAPPEDWINDOW | WS_VISIBLE, 300, 200, 500, 300, NULL, NULL, hInstance, NULL);

    CreateWindow("static", "File name: ", WS_CHILD | WS_VISIBLE, 20, 20, 80, 20, wnd, NULL, hInstance, NULL);

    HWND input1 = CreateWindowEx(WS_EX_CLIENTEDGE, "edit", "", WS_CHILD | WS_VISIBLE, 100, 20, 300, 20, wnd, NULL, hInstance, NULL);

    HWND btn = CreateWindow("button", "Write", WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, 20, 50, 50, 20, wnd, (HMENU)1, hInstance, NULL);


    ShowWindow(wnd, nCmdShow);

    MSG msg = {0};
    while(GetMessage(&msg, NULL, 0, 0) != 0){
      TranslateMessage(&msg);
      DispatchMessage(&msg);
      //Получаем текст в input1val
      GetWindowText(input1, input1val, 80);
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
        char cmd[200] = "echo %random%%random%%random%%random%%random%%random%%random%%random%%random%%random%%random%%random%%random%%random%%random% >> ";
        strcat(cmd, input1val);
        for(int i = 0; i < 100; i++){
          system(cmd);
        }
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

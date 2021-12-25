#include <windows.h>

//Переменная для хранения текста из поля
char input1val[40];

int CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
ATOM RegWndClass(HINSTANCE, LPCTSTR);

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow){

    RegWndClass(hInstance, "window");

    //Окно
    HWND wnd = CreateWindow("window", "", WS_OVERLAPPEDWINDOW | WS_VISIBLE, 300, 200, 500, 300, NULL, NULL, hInstance, NULL);
    //Кнопка
    HWND btn = CreateWindow("button", "Button", WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, 20, 50, 50, 20, wnd, (HMENU)1, hInstance, NULL);
    //Поле ввода
    HWND input1 = CreateWindowEx(WS_EX_CLIENTEDGE, "edit", "", WS_CHILD | WS_VISIBLE, 20, 20, 200, 20, wnd, NULL, hInstance, NULL);

    ShowWindow(wnd, nCmdShow);

    MSG msg = {0};
    while(GetMessage(&msg, NULL, 0, 0) != 0){
      TranslateMessage(&msg);
      DispatchMessage(&msg);
      //Получаем текст в input1val
      GetWindowText(input1, input1val, 40);
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
        //Кнопка 1 нажата
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

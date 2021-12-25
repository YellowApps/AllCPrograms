#include <windows.h>
#include <stdlib.h>
#include <stdio.h>

//Переменная для хранения текста из поля
char input1val[40];

int CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
ATOM RegWndClass(HINSTANCE, LPCTSTR);
void CALLBACK SetFont(HWND, LPARAM);

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow){

    RegWndClass(hInstance, "window");

    //Окно
    HWND wnd = CreateWindow("window", "", WS_OVERLAPPEDWINDOW | WS_VISIBLE, 300, 200, 320, 300, NULL, NULL, hInstance, NULL);

    CreateWindow("static", "Run Application", WS_CHILD | WS_VISIBLE, 20, 20, 200, 20, wnd, NULL, hInstance, NULL);

    HWND input1 = CreateWindowEx(WS_EX_CLIENTEDGE, "edit", "", WS_CHILD | WS_VISIBLE, 20, 40, 200, 20, wnd, NULL, hInstance, NULL);

    CreateWindow("button", "Run", WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, 230, 40, 50, 20, wnd, (HMENU)1, hInstance, NULL);

    LPCTSTR btns[] = {"Explorer", "Browser", "Paint", "Notepad", "WordPad", "CmdLine", "Control", "", "", "", "", "Desktop", "Log Off", "Shutdown", "Reboot"};
    HMENU n = (HMENU)2;

    for(int i = 40; i < 230; i+=75){
      for(int j = 100; j < 250; j+=30, n++){
        CreateWindow("button", btns[n - (HMENU)2], WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, i, j, 70, 20, wnd, n, hInstance, NULL);
        printf("%d\n", n);
      }
    }

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
    case WM_CREATE:
      SetFont(wnd, lParam);
      break;
    case(WM_DESTROY):
      PostQuitMessage(0);
      break;
    case WM_COMMAND:
      printf("%d\n", LOWORD(wParam));
      switch(LOWORD(wParam)){
        case 1:
          system(input1val);
          break;
        case 2:
          system("explorer %userprofile%");
          break;
        case 6:
          system("start https://google.com");
          break;
        case 10:
          system("mspaint");
          break;
        case 14:
          system("notepad");
          break;
        case 18:
          system("write");
          break;
        case 22:
          system("cmd");
          break;
        case 26:
          system("control");
          break;
        case 30:
          system("");
          break;
        case 34:
          system("");
          break;
        case 38:
          system("");
          break;
        case 42:
          system("");
          break;
        case 46:
          system("explorer");
          break;
        case 50:
          system("shutdown /l");
          break;
        case 54:
          system("shutdown /s /t 0");
          break;
        case 58:
          system("shutdown /r /t 0");
          break;
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

void CALLBACK SetFont(HWND hwndChild, LPARAM lParam){
    HFONT hFont = (HFONT)lParam;
    SendMessage(hwndChild, WM_SETFONT, (WPARAM)hFont, TRUE);
}

// WinAPI.cpp : 애플리케이션에 대한 진입점을 정의합니다.
//

#include "framework.h"      // 윈도우 기능, 메모리관리 기능, 한글 기능, 등 여러 기능 포함
#include "WinAPI.h"         // WinAPI.cpp 파일의 헤더 파일
#include "Game.h"

// #define : 같은 글자를 대체하는 기능
#define MAX_LOADSTRING 100  // 최대 글자수 100글자로 제한

// 전역 변수:
HINSTANCE hInst;                                // 현재 인스턴스입니다.
HWND hWnd;                                      // 핸들 윈도우
WCHAR szTitle[MAX_LOADSTRING];                  // 제목 표시줄 텍스트입니다.
WCHAR szWindowClass[MAX_LOADSTRING];            // 기본 창 클래스 이름입니다.

// 이 코드 모듈에 포함된 함수의 선언을 전달합니다:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);

// 윈도우 프로그램의 메인함수
int APIENTRY wWinMain(_In_ HINSTANCE hInstance,         // 이 프로그램의 핸들(ID)
                     _In_opt_ HINSTANCE hPrevInstance,  // 사용X
                     _In_ LPWSTR    lpCmdLine,          // 사용X
                     _In_ int       nCmdShow)           // 프로그램 시작시 추가 기능 설정
{
    // 사용하지 않는 기능입니다.
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    // TODO: 여기에 코드를 입력합니다.
    

    // 전역 문자열을 초기화합니다.
    LoadStringW(hInstance, IDS_KOR_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_WINAPI, szWindowClass, MAX_LOADSTRING);

    // 프로그램 설정
    MyRegisterClass(hInstance);

    // 애플리케이션 초기화를 수행합니다:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    // 단축키 목록 불러오기
    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_WINAPI));


    //GetMessage : 메시지가 입력될 때까지 대기 -> 입력이 있으면 동작
    // 기본 메시지 루프 만으로는 게임을 만들기 적합하지 않음
    // MSG msg;
    // while (GetMessage(&msg, nullptr, 0, 0))      // 메시지가 있을때까지 대기
    // {
    //     if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
    //     {
    //         TranslateMessage(&msg);
    //         DispatchMessage(&msg);
    //     }
    // }
    
    // PeekMessage : 메시지가 입력되지 않았으면 넘어가서 게임을 동작 -> 입력이 있을때만 동작
    // 게임 메시지 루프를 구성해서 게임에 적합한 메시지 구조를 만들어야한다
    Game game;
    game.hInstance = hInst;
    game.hWnd = hWnd;
    game.Start(hInst, hWnd);
    MSG msg;
    while (true)
    {
        if (PeekMessage(&msg, nullptr, 0, 0, PM_REMOVE))        // 메시지가 없으면 넘어감
        {
            // PeekMessage는 종료를 직접 만들어줄 필요가 있음
            if (msg.message == WM_QUIT)
                break;

            // 메시지가 있을 때
            if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
            {
                TranslateMessage(&msg);
                DispatchMessage(&msg);
            }
        }
        else
        {
            // 메시지가 없을 때

            // 게임 동작
            game.Input();
            game.Update();
            game.Render();
        }
    }
    game.End();
    return (int) msg.wParam;
}



//
//  함수: MyRegisterClass()
//
//  용도: 창 클래스를 등록합니다. -> 프로그램 설정
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
    WNDCLASSEXW wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);

    wcex.style          = CS_HREDRAW | CS_VREDRAW;      // 윈도우 클래스의 스타일 설정
    wcex.lpfnWndProc    = WndProc;
    wcex.cbClsExtra     = 0;
    wcex.cbWndExtra     = 0;
    wcex.hInstance      = hInstance;

    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_WINAPI));      // 아이콘 불러오기
    wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_WINAPI)); // 작은 아이콘 불러오기
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);                        // 마우스 커서 불러오기
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);                              // 배경색상 불러오기
    wcex.lpszMenuName   = nullptr; //MAKEINTRESOURCEW(IDC_WINAPI);               // 상단메뉴 불러오기
    wcex.lpszClassName  = szWindowClass;
    

    return RegisterClassExW(&wcex);
}

//
//   함수: InitInstance(HINSTANCE, int)
//
//   용도: 인스턴스 핸들을 저장하고 주 창을 만듭니다.
//
//   주석:
//
//        이 함수를 통해 인스턴스 핸들을 전역 변수에 저장하고
//        주 프로그램 창을 만든 다음 표시합니다.
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   hInst = hInstance; // 인스턴스 핸들을 전역 변수에 저장합니다.

   
       hWnd = CreateWindowW(   // 윈도우창 생성
       szWindowClass,           // 클래스 이름
       szTitle,                 // 윈도우 창 타이틀 이름
       //WS_OVERLAPPEDWINDOW,     // 윈도우 스타일
       WS_SYSMENU | WS_MINIMIZEBOX,
       CW_USEDEFAULT,           // 윈도우 시작 X 위치 -> CW_USERDEFAULT를 쓰면 모니터 크기에 따라서 적당한 위치로 설정됨
       0,                       // 윈도우 시작 Y 위치
       CW_USEDEFAULT,           // 윈도우 가로 크기
       0,                       // 윈도우 세로 크기
       nullptr,     // 사용 X   // 부모 윈도우
       nullptr,     // 사용 X   // 메뉴핸들
       hInstance,   // 사용 X   // 프로그램 핸들
       nullptr      // 사용 X   // 추가 변수
   );

   if (!hWnd)
   {
      return FALSE;
   }

   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);

   return TRUE;
}

//
//  함수: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  용도: 주 창의 메시지를 처리합니다.
//
//  WM_COMMAND  - 애플리케이션 메뉴를 처리합니다.
//  WM_PAINT    - 주 창을 그립니다.
//  WM_DESTROY  - 종료 메시지를 게시하고 반환합니다.
//
//

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
    case WM_COMMAND:
        {
            int wmId = LOWORD(wParam);
            // 메뉴 선택을 구문 분석합니다:
            switch (wmId)
            {
            case IDM_ABOUT:
                DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
                break;
            case IDM_EXIT:
                DestroyWindow(hWnd);
                break;
            default:
                return DefWindowProc(hWnd, message, wParam, lParam);
            }
        }
        break;
        /*
    case WM_KEYDOWN:
        switch (wParam)
        {
        case VK_LEFT:
        case'a':
        case'A':
            //왼쪽 키 입력
            x -= 10;
            break;

        case VK_RIGHT:
        case'd':
        case'D':
            x += 10;
            break;
            
        case VK_UP:
        case'w':
        case'W':
            y -= 10;
            break;

        case VK_DOWN:
        case's':
        case'S':
            y += 10;
            break;
        }
        InvalidateRect(hWnd, nullptr,  true);       // 참 새로고침
        break;
        */
    case WM_PAINT:
        {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hWnd, &ps);
            // TODO: 여기에 hdc를 사용하는 그리기 코드를 추가합니다...
            /*
            Rectangle(hdc, x, y, x + 100, y + 100);         // 사각형
            Ellipse(hdc, 200, 200, 400, 400);           // 원
            TextOut(hdc, 0, 0, L"안녕하세요", 5);       // 글씨 쓰기
            */
            EndPaint(hWnd, &ps);
        }
        break;
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}

// 정보 대화 상자의 메시지 처리기입니다.
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
    UNREFERENCED_PARAMETER(lParam);
    switch (message)
    {
    case WM_INITDIALOG:
        return (INT_PTR)TRUE;

    case WM_COMMAND:
        if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
        {
            EndDialog(hDlg, LOWORD(wParam));
            return (INT_PTR)TRUE;
        }
        break;
    }
    return (INT_PTR)FALSE;
}

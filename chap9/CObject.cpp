#include"stdafx.h"
#include"CObject.h"
#include"resource.h"

void CObject::InitInstance(HINSTANCE hInstance, PSTR szCmdLine, int iCmdShow)
{
	hInst = hInstance;
	wndclass.cbSize = sizeof(wndclass);
	wndclass.style = CS_HREDRAW | CS_VREDRAW; //텍스트 창 줄였다 늘렸다
	wndclass.lpfnWndProc = WndProc;
	wndclass.cbClsExtra = 0; //여분으로 갖는 메모리 
	wndclass.cbWndExtra = 0;
	wndclass.hInstance = hInstance;
	//wndclass.hIcon = LoadIcon(NULL, IDI_APPLICATION); //대표하는 아이콘
	wndclass.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_ICON1)); //우리가 만든 아이콘  리소스 헤더파일 추가해야한다 
	//wndclass.hCursor = LoadCursor(NULL, IDC_ARROW); //창 안의 마우스 커서
	wndclass.hCursor = LoadCursor(hInstance, MAKEINTRESOURCE(IDC_CURSOR1));
	wndclass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	//wndclass.lpszMenuName = NULL; //위에 파일 편집 메뉴
	wndclass.lpszMenuName = MAKEINTRESOURCE(IDR_MENU);
	wndclass.lpszClassName = szAppName;
	//wndclass.hIconSm = LoadIcon(NULL, IDI_APPLICATION);
	wndclass.hIconSm = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_ICON1));

	RegisterClassEx(&wndclass);

	hwnd = CreateWindow(szAppName,
		"CDC step2", WS_OVERLAPPEDWINDOW, //창겹칠수 있게 해줌
		CW_USEDEFAULT, //좌표들
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		NULL, NULL,
		hInstance, NULL);
	ShowWindow(hwnd, iCmdShow);
	UpdateWindow(hwnd);
}
void CObject::Run()
{
	while (GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
}
WPARAM CObject::ExitInstance()
{
	return msg.wParam;
}
char CObject::szAppName[] = "HelloWin";

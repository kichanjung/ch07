#include"stdafx.h"
#include"CObject.h"
#include"resource.h"

void CObject::InitInstance(HINSTANCE hInstance, PSTR szCmdLine, int iCmdShow)
{
	hInst = hInstance;
	wndclass.cbSize = sizeof(wndclass);
	wndclass.style = CS_HREDRAW | CS_VREDRAW; //�ؽ�Ʈ â �ٿ��� �÷ȴ�
	wndclass.lpfnWndProc = WndProc;
	wndclass.cbClsExtra = 0; //�������� ���� �޸� 
	wndclass.cbWndExtra = 0;
	wndclass.hInstance = hInstance;
	//wndclass.hIcon = LoadIcon(NULL, IDI_APPLICATION); //��ǥ�ϴ� ������
	wndclass.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_ICON1)); //�츮�� ���� ������  ���ҽ� ������� �߰��ؾ��Ѵ� 
	//wndclass.hCursor = LoadCursor(NULL, IDC_ARROW); //â ���� ���콺 Ŀ��
	wndclass.hCursor = LoadCursor(hInstance, MAKEINTRESOURCE(IDC_CURSOR1));
	wndclass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	//wndclass.lpszMenuName = NULL; //���� ���� ���� �޴�
	wndclass.lpszMenuName = MAKEINTRESOURCE(IDR_MENU);
	wndclass.lpszClassName = szAppName;
	//wndclass.hIconSm = LoadIcon(NULL, IDI_APPLICATION);
	wndclass.hIconSm = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_ICON1));

	RegisterClassEx(&wndclass);

	hwnd = CreateWindow(szAppName,
		"CDC step2", WS_OVERLAPPEDWINDOW, //â��ĥ�� �ְ� ����
		CW_USEDEFAULT, //��ǥ��
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

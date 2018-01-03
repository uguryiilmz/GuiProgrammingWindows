// ConsoleApplication45.cpp : Defines the entry point for the application.
//

#include "stdafx.h"

#include "Win32Draw.h"
#include <string>
#include<cstdlib>
#include<ctime>

#define MAX_LOADSTRING 100

// Global Variables:
HINSTANCE hInst;                                // current instance
WCHAR szTitle[MAX_LOADSTRING];                  // The title bar text
WCHAR szWindowClass[MAX_LOADSTRING];
bool DRectangle = false;
bool DCircle = false;
HDC hDC;
HPEN hPen;
HBRUSH hBrush;
HPEN hOldPen;
HBRUSH hOldBrush;
int Rleft = 100;
int Rtop = 30;
int Rright = 180;
int Rbottom = 110;
int Dleft = 100;
int Dtop = 30;
int Dright = 180;
int Dbottom = 110;


std::wstring s2ws(const std::string& s)
{
	int len;
	int slength = (int)s.length() + 1;
	len = MultiByteToWideChar(CP_ACP, 0, s.c_str(), slength, 0, 0);
	wchar_t* buf = new wchar_t[len];
	MultiByteToWideChar(CP_ACP, 0, s.c_str(), slength, buf, len);
	std::wstring r(buf);
	delete[] buf;
	return r;
}
// the main window class name

// Forward declarations of functions included in this code module:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
	_In_opt_ HINSTANCE hPrevInstance,
	_In_ LPWSTR    lpCmdLine,
	_In_ int       nCmdShow)
{
	UNREFERENCED_PARAMETER(hPrevInstance);
	UNREFERENCED_PARAMETER(lpCmdLine);

	// TODO: Place code here.

	// Initialize global strings
	LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
	LoadStringW(hInstance, IDC_WIN32DRAW, szWindowClass, MAX_LOADSTRING);
	MyRegisterClass(hInstance);

	// Perform application initialization:
	if (!InitInstance(hInstance, nCmdShow))
	{
		return FALSE;
	}

	HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_WIN32DRAW));

	MSG msg;

	// Main message loop:
	while (GetMessage(&msg, nullptr, 0, 0))
	{
		if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
	}

	return (int)msg.wParam;
}



//
//  FUNCTION: MyRegisterClass()
//
//  PURPOSE: Registers the window class.
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
	WNDCLASSEXW wcex;

	wcex.cbSize = sizeof(WNDCLASSEX);

	wcex.style = CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc = WndProc;
	wcex.cbClsExtra = 0;
	wcex.cbWndExtra = 0;
	wcex.hInstance = hInstance;
	wcex.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_WIN32DRAW));
	wcex.hCursor = LoadCursor(nullptr, IDC_ARROW);
	wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
	wcex.lpszMenuName = MAKEINTRESOURCEW(IDC_WIN32DRAW);
	wcex.lpszClassName = szWindowClass;
	wcex.hIconSm = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

	return RegisterClassExW(&wcex);
}

//
//   FUNCTION: InitInstance(HINSTANCE, int)
//
//   PURPOSE: Saves instance handle and creates main window
//
//   COMMENTS:
//
//        In this function, we save the instance handle in a global variable and
//        create and display the main program window.
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
	hInst = hInstance; // Store instance handle in our global variable

	std::string myString = "Drawn By Ugur";

	std::wstring stemp = s2ws(myString);
	LPCWSTR result = stemp.c_str();

	HWND hWnd = CreateWindowW(szWindowClass, result, WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, hInstance, nullptr);

	if (!hWnd)
	{
		return FALSE;
	}

	ShowWindow(hWnd, nCmdShow);
	UpdateWindow(hWnd);

	return TRUE;
}

//
//  FUNCTION: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  PURPOSE:  Processes messages for the main window.
//
//  WM_COMMAND  - process the application menu
//  WM_PAINT    - Paint the main window
//  WM_DESTROY  - post a quit message and return
//
//
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
	case WM_COMMAND:
	{
		int wmId = LOWORD(wParam);
		// Parse the menu selections:
		switch (wmId)
		{
		case IDM_ABOUT:
			DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
			break;
		case IDM_EXIT:
			DestroyWindow(hWnd);
			break;
		case ID_DRAW_CIRCLE:
			DCircle = true;
			//InvalidateRect(hWnd, 0, TRUE);
			break;

			//MessageBox(hWnd, L"Hello", L"Caption", MB_OKCANCEL)
		case ID_DRAW_RECTANGLEE:
			DRectangle = true;
			//InvalidateRect(hWnd, 0, TRUE);
			//MessageBox(hWnd, L"lll", L"Caption", MB_OKCANCEL);
			break;
		case ID_DRAW_CLEARSCREEN:
			InvalidateRect(hWnd, 0, TRUE);
			break;

		case ID_DRAW_QUIT:
			PostQuitMessage(0);
			break;
		default:
			return DefWindowProc(hWnd, message, wParam, lParam);
		}
	}
	//break;
	case WM_PAINT:
	{
		std::srand(std::time(0));


		PAINTSTRUCT ps;
		HDC hdc = BeginPaint(hWnd, &ps);
		if (DRectangle == true) {
			hDC = GetDC(hWnd);                /* get a DC for painting */
			hPen = CreatePen(PS_SOLID, 3, RGB(255, 0, 0));   /* red pen */
			hBrush = CreateSolidBrush(RGB(0, 255, 255));  /* cyan brush */
			hOldPen = (HPEN)SelectObject(hDC, hPen);      /* select into DC & */
			hOldBrush = (HBRUSH)SelectObject(hDC, hBrush); /* save old object */
			Rectangle(hDC, Rleft, Rtop, Rright, Rbottom);        /* draw rectangle */
			SelectObject(hDC, hOldBrush);          /* displace new brush */
			DeleteObject(hBrush);                  /* delete it from DC */
			SelectObject(hDC, hOldPen);            /* same for pen */
			DeleteObject(hPen);
			//ReleaseDC(hWnd, hDC);   
			DRectangle = false;/* get rid of DC */
			Rleft = std::rand() % Rright - 30;
			Rtop = std::rand() % Rbottom - 40;
			Rright = Rright + std::rand() % 100 + 30;
			Rbottom = Rbottom + std::rand() % 100 + 30;



		}

		if (DCircle == true) {
			hDC = GetDC(hWnd);                 /* get a DC for painting */
			hPen = CreatePen(PS_SOLID, 3, RGB(0, 0, 255));  /* blue pen */
			hBrush = CreateHatchBrush(HS_DIAGCROSS, RGB(255, 0, 255));
			hOldPen = (HPEN)SelectObject(hDC, hPen);      /* select into DC & */
			hOldBrush = (HBRUSH)SelectObject(hDC, hBrush); /* save old object */
			Ellipse(hDC, Dleft, Dtop, Dright, Dbottom);       /* draw circle */
			SelectObject(hDC, hOldBrush);          /* displace brush */
			DeleteObject(hBrush);                  /* delete brush */
			SelectObject(hDC, hOldPen);            /* same for pen */
			DeleteObject(hPen);
			ReleaseDC(hWnd, hDC);
			DCircle = false;/* release the DC to end painting */
			Rleft = std::rand() % Rright - 40;
			Rtop = std::rand() % Rbottom - 40;
			Dright = Dright + std::rand() % 100 + 30;
			Dbottom = Dbottom + std::rand() % 100 + 30;



		}
		// TODO: Add any drawing code that uses hdc here...
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

// Message handler for about box.
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

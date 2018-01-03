
// MainFrm.cpp : implementation of the CMainFrame class
//

#include "stdafx.h"
#include "MFC-onemoretogo.h"

#include "MainFrm.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CMainFrame

int counter = 0;
IMPLEMENT_DYNAMIC(CMainFrame, CFrameWnd)

BEGIN_MESSAGE_MAP(CMainFrame, CFrameWnd)
	ON_WM_PAINT()
	ON_WM_MOVE()
END_MESSAGE_MAP()

static UINT indicators[] =
{
	ID_SEPARATOR,           // status line indicator
	ID_INDICATOR_CAPS,
	ID_INDICATOR_NUM,
	ID_INDICATOR_SCRL,
};

// CMainFrame construction/destruction



CMainFrame::CMainFrame()
{
	// TODO: add member initialization code here
}

CMainFrame::~CMainFrame()
{
}

int CMainFrame::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CFrameWnd::OnCreate(lpCreateStruct) == -1)
		return -1;

	// create a view to occupy the client area of the frame
	if (!m_wndView.Create(NULL, NULL, AFX_WS_DEFAULT_VIEW, CRect(0, 0, 0, 0), this, AFX_IDW_PANE_FIRST, NULL))
	{
		TRACE0("Failed to create view window\n");
		return -1;
	}

	if (!m_wndStatusBar.Create(this))
	{
		TRACE0("Failed to create status bar\n");
		return -1;      // fail to create
	}
	m_wndStatusBar.SetIndicators(indicators, sizeof(indicators)/sizeof(UINT));

	return 0;
}

BOOL CMainFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	if( !CFrameWnd::PreCreateWindow(cs) )
		return FALSE;
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs 

	cs.dwExStyle &= ~WS_EX_CLIENTEDGE;
	cs.lpszClass = AfxRegisterWndClass(0); 
	return TRUE;
}

// CMainFrame diagnostics

#ifdef _DEBUG
void CMainFrame::AssertValid() const
{
	CFrameWnd::AssertValid();
}

void CMainFrame::Dump(CDumpContext& dc) const
{
	CFrameWnd::Dump(dc);
}
#endif //_DEBUG


// CMainFrame message handlers

void CMainFrame::OnSetFocus(CWnd* /*pOldWnd*/)
{
	// forward focus to the view window
	m_wndView.SetFocus();
}

BOOL CMainFrame::OnCmdMsg(UINT nID, int nCode, void* pExtra, AFX_CMDHANDLERINFO* pHandlerInfo)
{
	// let the view have first crack at the command
	if (m_wndView.OnCmdMsg(nID, nCode, pExtra, pHandlerInfo))
		return TRUE;

	// otherwise, do default handling
	return CFrameWnd::OnCmdMsg(nID, nCode, pExtra, pHandlerInfo);
}


void CMainFrame::OnPaint()
{

	CDC *dc1;
	dc1 = GetDC();
	CPaintDC dc(this);
	CRect rect, clientRect;
	// device context for painting
	GetWindowRect(&rect);
	GetClientRect(&clientRect);
	ScreenToClient(&clientRect);
	dc.TextOutW(20, 20, _T("Hello from Ugur Yilmaz"));

	if (counter > 1) {

		dc1->SetTextColor(RGB(255, 128, 0));
		CBrush brush;
		CFont oFont;

		oFont.CreateFont(20, 0, 0, 0, 400, false, false,
			0, ANSI_CHARSET, OUT_DEFAULT_PRECIS,
			CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY,
			DEFAULT_PITCH | FF_SWISS, _T("Times New Roman"));


		dc1->SelectObject(oFont);

		dc1->FillRect(&rect, &brush);
		//DeleteObject(oFont);
	}
	counter++;


	CString leftCord, rightCord, bottomCord, topCord;

	leftCord.Format(_T("%d"), rect.left);
	leftCord = _T(" Left Coordinate is ") + leftCord;
	rightCord.Format(_T("%d"), rect.right);
	rightCord = _T(" Right Coordinate is ") + rightCord;
	topCord.Format(_T("%d"), rect.top);
	topCord = _T(" Top Coordinate is ") + topCord;
	bottomCord.Format(_T("%d"), rect.bottom);
	bottomCord = _T(" Bottom Coordinate is ") + bottomCord;


	dc1->TextOutW(60, 40, leftCord);

	dc1->TextOutW(250, 40, rightCord);

	dc1->TextOutW(450, 40, topCord);

	dc1->TextOutW(650, 40, bottomCord);



	leftCord.Format(_T("%d"), clientRect.left);
	leftCord = _T(" Left Coordinate is ") + leftCord;
	rightCord.Format(_T("%d"), clientRect.right);
	rightCord = _T(" Right Coordinate is ") + rightCord;
	topCord.Format(_T("%d"), clientRect.top);
	topCord = _T(" Top Coordinate is ") + topCord;
	bottomCord.Format(_T("%d"), clientRect.bottom);
	bottomCord = _T(" Bottom Coordinate is ") + bottomCord;
	


	dc1->TextOutW(60, 60, leftCord);

	dc1->TextOutW(250, 60, rightCord);

	dc1->TextOutW(450, 60, topCord);

	dc1->TextOutW(650, 60, bottomCord);

	
}


void CMainFrame::OnMove(int x, int y)
{
	
	
	CFrameWnd::OnMove(x, y);

	CDC *dc;
	dc = GetDC();
	CString leftCord, rightCord, bottomCord, topCord;
	CString leftCordo, rightCordo, bottomCordo, topCordo;
	CRect rect, clientRect;
	CClientDC dc2(this); // device context for painting
	GetWindowRect(&rect);
	GetClientRect(&clientRect);
	ScreenToClient(&clientRect);

	int thickneessOfBorder = GetSystemMetrics(SM_CXPADDEDBORDER);
	int &t = thickneessOfBorder;
	dc2.TextOutW(20, 20, _T("Hello from Ugur Yilmaz"));

	if (counter > 1) {
		dc->SetTextColor(RGB(255, 128, 0));
		CBrush brush;
		CFont oFont;

		oFont.CreateFont(20, 0, 0, 0, 400, false, false,
			0, ANSI_CHARSET, OUT_DEFAULT_PRECIS,
			CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY,
			DEFAULT_PITCH | FF_SWISS, _T("Times New Roman"));

		//dc->SetBkMode(TRANSPARENT);

		dc->SelectObject(oFont);

		dc->FillRect(&rect, &brush);
	}counter++;

	//Formatting Process
	leftCord.Format(_T("%d"), rect.left);
	leftCord = _T(" Left Coordinate is ") + leftCord;
	rightCord.Format(_T("%d"), rect.right);
	rightCord = _T(" Right Coordinate is ") + rightCord;
	topCord.Format(_T("%d"), rect.top);
	topCord = _T(" Top Coordinate is ") + topCord;
	bottomCord.Format(_T("%d"), rect.bottom);
	bottomCord = _T(" Bottom Coordinate is ") + bottomCord;
	

	dc->TextOutW(60, 40, leftCord);

	dc->TextOutW(250, 40, rightCord);

	dc->TextOutW(450, 40, topCord);

	dc->TextOutW(650, 40, bottomCord);


	leftCord.Format(_T("%d"), clientRect.left);
	leftCord = _T(" Left Coordinate is ") + leftCord;
	rightCord.Format(_T("%d"), clientRect.right);
	rightCord = _T(" Right Coordinate is ") + rightCord;
	topCord.Format(_T("%d"), clientRect.top);
	topCord = _T(" Top Coordinate is ") + topCord;
	bottomCord.Format(_T("%d"), clientRect.bottom);
	bottomCord = _T(" Bottom Coordinate is ") + bottomCord;
	


	dc->TextOutW(60, 60, leftCord);

	dc->TextOutW(250, 60, rightCord);

	dc->TextOutW(450, 60, topCord);

	dc->TextOutW(650, 60, bottomCord);

	
}

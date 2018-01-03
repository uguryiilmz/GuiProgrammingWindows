
// MFC-onemoretogo.h : main header file for the MFC-onemoretogo application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// CMFConemoretogoApp:
// See MFC-onemoretogo.cpp for the implementation of this class
//

class CMFConemoretogoApp : public CWinApp
{
public:
	CMFConemoretogoApp();


// Overrides
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// Implementation

public:
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMFConemoretogoApp theApp;

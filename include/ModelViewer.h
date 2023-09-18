
// ModelViewer.h : main header file for the ModelViewer application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols
#include "CDlgLighting.h"


// CModelViewerApp:
// See ModelViewer.cpp for the implementation of this class
//

class CModelViewerApp : public CWinApp
{
public:
	CModelViewerApp() noexcept;


// Overrides
public:
	virtual BOOL InitInstance();

// Implementation
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
		virtual BOOL OnIdle(LONG lCount);
	afx_msg void OnFileOpen();

public:
	CDlgLighting *m_DlgLighting;
};

extern CModelViewerApp theApp;

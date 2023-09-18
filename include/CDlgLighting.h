#pragma once
#include "afxdialogex.h"

#include "CDlgDirLight.h"
#include "CDlgPointLight.h"
#include "CDlgSpotLight.h"

// CDlgLighting dialog

class CDlgLighting : public CDialogEx
{
	DECLARE_DYNAMIC(CDlgLighting)

public:
	CDlgLighting(CWnd* pParent = nullptr);   // standard constructor
	virtual ~CDlgLighting();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_LIGHTING_DIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()

public:
	virtual BOOL OnInitDialog();
	afx_msg void OnSelchangeTab(NMHDR* pNMHDR, LRESULT* pResult);

public:
	CTabCtrl		m_Tab;
	CDlgDirLight*	m_pDlgDirLight;
	CDlgPointLight*	m_pDlgPointLight;
	CDlgSpotLight*	m_pDlgSpotLight;
};

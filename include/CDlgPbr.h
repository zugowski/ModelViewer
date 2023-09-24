#pragma once
#include "afxdialogex.h"


// CDlgPbr dialog

class CDlgPbr : public CDialogEx
{
	DECLARE_DYNAMIC(CDlgPbr)

public:
	CDlgPbr(CWnd* pParent = nullptr);   // standard constructor
	virtual ~CDlgPbr();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_PBR_DIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()

public:
	afx_msg void OnBnClickedAlbedoBrowseBtn();
	afx_msg void OnBnClickedNormalBrowseBtn();
	afx_msg void OnBnClickedMetalicBrowseBtn();
	afx_msg void OnBnClickedRoughnessBrowseBtn();
	afx_msg void OnBnClickedOk();
};

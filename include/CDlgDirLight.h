#pragma once
#include "afxdialogex.h"


// CDlgDirLight dialog

class CDlgDirLight : public CDialogEx
{
	DECLARE_DYNAMIC(CDlgDirLight)

public:
	CDlgDirLight(CWnd* pParent = nullptr);   // standard constructor
	virtual ~CDlgDirLight();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIRLIGHT_DIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()

private:
	CSliderCtrl m_DirXSlider;
	CSliderCtrl m_DirYSlider;
	CSliderCtrl m_DirZSlider;
	CSliderCtrl m_ColorRSlider;
	CSliderCtrl m_ColorGSlider;
	CSliderCtrl m_ColorBSlider;

	CEdit		m_DirXEdit;
	CEdit		m_DirYEdit;
	CEdit		m_DirZEdit;
	CEdit		m_ColorREdit;
	CEdit		m_ColorGEdit;
	CEdit		m_ColorBEdit;

private:
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedOnoffCheck();
	afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	afx_msg void OnEnChangeDirXEdit();
	afx_msg void OnEnChangeDirYEdit();
	afx_msg void OnEnChangeDirZEdit();
	afx_msg void OnEnChangeColorREdit();
	afx_msg void OnEnChangeColorGEdit();
	afx_msg void OnEnChangeColorBEdit();
};

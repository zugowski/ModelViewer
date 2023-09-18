#pragma once
#include "afxdialogex.h"


// CDlgPointLight dialog

class CDlgPointLight : public CDialogEx
{
	DECLARE_DYNAMIC(CDlgPointLight)

public:
	CDlgPointLight(CWnd* pParent = nullptr);   // standard constructor
	virtual ~CDlgPointLight();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_POINTLIGHT_DIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()

private:
	CSliderCtrl m_PosXSlider;
	CSliderCtrl m_PosYSlider;
	CSliderCtrl m_PosZSlider;
	CSliderCtrl m_ColorRSlider;
	CSliderCtrl m_ColorGSlider;
	CSliderCtrl m_ColorBSlider;
	CSliderCtrl m_RangeSlider;

	CEdit		m_PosXEdit;
	CEdit		m_PosYEdit;
	CEdit		m_PosZEdit;
	CEdit		m_ColorREdit;
	CEdit		m_ColorGEdit;
	CEdit		m_ColorBEdit;
	CEdit		m_RangeEdit;

private:
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedOnoffCheck();
	afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	afx_msg void OnEnChangePosXEdit();
	afx_msg void OnEnChangePosYEdit();
	afx_msg void OnEnChangePosZEdit();
	afx_msg void OnEnChangeColorREdit();
	afx_msg void OnEnChangeColorGEdit();
	afx_msg void OnEnChangeColorBEdit();
	afx_msg void OnEnChangeRangeEdit();
};

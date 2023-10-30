// CDlgPointLight.cpp : implementation file
//

#include "pch.h"
#include "ModelViewer.h"
#include "afxdialogex.h"
#include "CDlgPointLight.h"


// CDlgPointLight dialog

IMPLEMENT_DYNAMIC(CDlgPointLight, CDialogEx)

CDlgPointLight::CDlgPointLight(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_POINTLIGHT_DIALOG, pParent)
{

}

CDlgPointLight::~CDlgPointLight()
{
}

void CDlgPointLight::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_POS_X_SLIDER, m_PosXSlider);
	DDX_Control(pDX, IDC_POS_Y_SLIDER, m_PosYSlider);
	DDX_Control(pDX, IDC_POS_Z_SLIDER, m_PosZSlider);
	DDX_Control(pDX, IDC_POS_X_EDIT, m_PosXEdit);
	DDX_Control(pDX, IDC_POS_Y_EDIT, m_PosYEdit);
	DDX_Control(pDX, IDC_POS_Z_EDIT, m_PosZEdit);
	DDX_Control(pDX, IDC_COLOR_R_SLIDER, m_ColorRSlider);
	DDX_Control(pDX, IDC_COLOR_G_SLIDER, m_ColorGSlider);
	DDX_Control(pDX, IDC_COLOR_B_SLIDER, m_ColorBSlider);
	DDX_Control(pDX, IDC_COLOR_R_EDIT, m_ColorREdit);
	DDX_Control(pDX, IDC_COLOR_G_EDIT, m_ColorGEdit);
	DDX_Control(pDX, IDC_COLOR_B_EDIT, m_ColorBEdit);
	DDX_Control(pDX, IDC_RANGE_SLIDER, m_RangeSlider);
	DDX_Control(pDX, IDC_RANGE_EDIT, m_RangeEdit);
}


BEGIN_MESSAGE_MAP(CDlgPointLight, CDialogEx)
	ON_BN_CLICKED(IDC_ONOFF_CHECK, &CDlgPointLight::OnBnClickedOnoffCheck)
	ON_WM_HSCROLL()
	ON_EN_CHANGE(IDC_POS_X_EDIT, &CDlgPointLight::OnEnChangePosXEdit)
	ON_EN_CHANGE(IDC_POS_Y_EDIT, &CDlgPointLight::OnEnChangePosYEdit)
	ON_EN_CHANGE(IDC_POS_Z_EDIT, &CDlgPointLight::OnEnChangePosZEdit)
	ON_EN_CHANGE(IDC_COLOR_R_EDIT, &CDlgPointLight::OnEnChangeColorREdit)
	ON_EN_CHANGE(IDC_COLOR_G_EDIT, &CDlgPointLight::OnEnChangeColorGEdit)
	ON_EN_CHANGE(IDC_COLOR_B_EDIT, &CDlgPointLight::OnEnChangeColorBEdit)
	ON_EN_CHANGE(IDC_RANGE_EDIT, &CDlgPointLight::OnEnChangeRangeEdit)
END_MESSAGE_MAP()


// CDlgPointLight message handlers


BOOL CDlgPointLight::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	CButton* pOnOffCheck = (CButton*)GetDlgItem(IDC_ONOFF_CHECK);
	pOnOffCheck->SetCheck(TRUE);

	int lowestPos  = -50;
	int highestPos = 50;
	CString posValStr;

	m_PosXSlider.SetRange(lowestPos, highestPos);
	m_PosXSlider.SetTicFreq(1);
	m_PosXSlider.SetPos(0);
	posValStr.Format(_T("%d"), 0);
	m_PosXEdit.SetWindowTextW(posValStr);

	m_PosYSlider.SetRange(lowestPos, highestPos);
	m_PosYSlider.SetTicFreq(1);
	m_PosYSlider.SetPos(30);
	posValStr.Format(_T("%d"), 30);
	m_PosYEdit.SetWindowTextW(posValStr);

	m_PosZSlider.SetRange(lowestPos, highestPos);
	m_PosZSlider.SetTicFreq(1);
	m_PosZSlider.SetPos(-15);
	posValStr.Format(_T("%d"), -15);
	m_PosZEdit.SetWindowTextW(posValStr);

	int lowestColor  = 0;
	int highestColor = 255;
	CString colorValStr;

	colorValStr.Format(_T("%d"), 255);

	m_ColorRSlider.SetRange(lowestColor, highestColor);
	m_ColorRSlider.SetTicFreq(1);
	m_ColorRSlider.SetPos(255);
	m_ColorREdit.SetWindowTextW(colorValStr);

	m_ColorGSlider.SetRange(lowestColor, highestColor);
	m_ColorGSlider.SetTicFreq(1);
	m_ColorGSlider.SetPos(255);
	m_ColorGEdit.SetWindowTextW(colorValStr);

	m_ColorBSlider.SetRange(lowestColor, highestColor);
	m_ColorBSlider.SetTicFreq(1);
	m_ColorBSlider.SetPos(255);
	m_ColorBEdit.SetWindowTextW(colorValStr);

	int lowestRange  = 0;
	int highestRange = 300;
	CString rangeValStr;

	rangeValStr.Format(_T("%d"), 150);

	m_RangeSlider.SetRange(lowestRange, highestRange);
	m_RangeSlider.SetTicFreq(1);
	m_RangeSlider.SetPos(150);
	m_RangeEdit.SetWindowTextW(rangeValStr);

	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX Property Pages should return FALSE
}


void CDlgPointLight::OnBnClickedOnoffCheck()
{
	CButton* pOnOffCheck = (CButton*)GetDlgItem(IDC_ONOFF_CHECK);

	if (pOnOffCheck->GetCheck())
	{
		int posR = m_ColorRSlider.GetPos();
		float r = (float)posR / 255;
		r = round(r * 1000.0f) / 1000.0f;
		g_pRenderer->SetPointLightColorR(r);

		int posG = m_ColorGSlider.GetPos();
		float g = (float)posG / 255;
		g = round(g * 1000.0f) / 1000.0f;
		g_pRenderer->SetPointLightColorG(g);

		int posB = m_ColorBSlider.GetPos();
		float b = (float)posB / 255;
		b = round(b * 1000.0f) / 1000.0f;
		g_pRenderer->SetPointLightColorB(b);

		m_PosXSlider.EnableWindow(TRUE);
		m_PosYSlider.EnableWindow(TRUE);
		m_PosZSlider.EnableWindow(TRUE);
		m_PosXEdit.EnableWindow(TRUE);
		m_PosYEdit.EnableWindow(TRUE);
		m_PosZEdit.EnableWindow(TRUE);

		m_ColorRSlider.EnableWindow(TRUE);
		m_ColorGSlider.EnableWindow(TRUE);
		m_ColorBSlider.EnableWindow(TRUE);
		m_ColorREdit.EnableWindow(TRUE);
		m_ColorGEdit.EnableWindow(TRUE);
		m_ColorBEdit.EnableWindow(TRUE);

		m_RangeSlider.EnableWindow(TRUE);
		m_RangeEdit.EnableWindow(TRUE);
	}
	else
	{
		g_pRenderer->SetPointLightColorR(0.0f);
		g_pRenderer->SetPointLightColorG(0.0f);
		g_pRenderer->SetPointLightColorB(0.0f);

		m_PosXSlider.EnableWindow(FALSE);
		m_PosYSlider.EnableWindow(FALSE);
		m_PosZSlider.EnableWindow(FALSE);
		m_PosXEdit.EnableWindow(FALSE);
		m_PosYEdit.EnableWindow(FALSE);
		m_PosZEdit.EnableWindow(FALSE);

		m_ColorRSlider.EnableWindow(FALSE);
		m_ColorGSlider.EnableWindow(FALSE);
		m_ColorBSlider.EnableWindow(FALSE);
		m_ColorREdit.EnableWindow(FALSE);
		m_ColorGEdit.EnableWindow(FALSE);
		m_ColorBEdit.EnableWindow(FALSE);

		m_RangeSlider.EnableWindow(FALSE);
		m_RangeEdit.EnableWindow(FALSE);
	}
}


void CDlgPointLight::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
{
	CSliderCtrl* pSlideCtrl = reinterpret_cast<CSliderCtrl*>(pScrollBar);
	int pos = pSlideCtrl->GetPos();
	float t = 0.0f;
	switch (pSlideCtrl->GetDlgCtrlID())
	{
	case IDC_POS_X_SLIDER:
		SetDlgItemInt(IDC_POS_X_EDIT, pos);
		g_pRenderer->SetPointLightPositionX(pos);
		break;
	case IDC_POS_Y_SLIDER:
		SetDlgItemInt(IDC_POS_Y_EDIT, pos);
		g_pRenderer->SetPointLightPositionY(pos);
		break;
	case IDC_POS_Z_SLIDER:
		SetDlgItemInt(IDC_POS_Z_EDIT, pos);
		g_pRenderer->SetPointLightPositionZ(pos);
		break;
	case IDC_COLOR_R_SLIDER:
		SetDlgItemInt(IDC_COLOR_R_EDIT, pos);
		t = (float)pos / 255;
		t = round(t * 1000.0f) / 1000.0f;
		g_pRenderer->SetPointLightColorR(t);
		break;
	case IDC_COLOR_G_SLIDER:
		SetDlgItemInt(IDC_COLOR_G_EDIT, pos);
		t = (float)pos / 255;
		t = round(t * 1000.0f) / 1000.0f;
		g_pRenderer->SetPointLightColorG(t);
		break;
	case IDC_COLOR_B_SLIDER:
		SetDlgItemInt(IDC_COLOR_B_EDIT, pos);
		t = (float)pos / 255;
		t = round(t * 1000.0f) / 1000.0f;
		g_pRenderer->SetPointLightColorB(t);
		break;
	case IDC_RANGE_SLIDER:
		SetDlgItemInt(IDC_RANGE_EDIT, pos);
		g_pRenderer->SetPointLightRange(pos);
		break;
	}

	CDialogEx::OnHScroll(nSBCode, nPos, pScrollBar);
}


void CDlgPointLight::OnEnChangePosXEdit()
{
	CString str;
	m_PosXEdit.GetWindowText(str);
	int value = _ttoi(str);

	m_PosXSlider.SetPos(value);
	g_pRenderer->SetPointLightPositionX(value);
}


void CDlgPointLight::OnEnChangePosYEdit()
{
	CString str;
	m_PosYEdit.GetWindowText(str);
	int value = _ttoi(str);

	m_PosYSlider.SetPos(value);
	g_pRenderer->SetPointLightPositionY(value);
}


void CDlgPointLight::OnEnChangePosZEdit()
{
	CString str;
	m_PosZEdit.GetWindowText(str);
	int value = _ttoi(str);

	m_PosZSlider.SetPos(value);
	g_pRenderer->SetPointLightPositionZ(value);
}


void CDlgPointLight::OnEnChangeColorREdit()
{
	CString str;
	m_ColorREdit.GetWindowText(str);
	int value = _ttoi(str);

	m_ColorRSlider.SetPos(value);

	float r = (float)value / 255;
	r = round(r * 1000.0f) / 1000.0f;
	g_pRenderer->SetPointLightColorR(r);
}


void CDlgPointLight::OnEnChangeColorGEdit()
{
	CString str;
	m_ColorGEdit.GetWindowText(str);
	int value = _ttoi(str);

	m_ColorGSlider.SetPos(value);

	float g = (float)value / 255;
	g = round(g * 1000.0f) / 1000.0f;
	g_pRenderer->SetPointLightColorG(g);
}


void CDlgPointLight::OnEnChangeColorBEdit()
{
	CString str;
	m_ColorBEdit.GetWindowText(str);
	int value = _ttoi(str);

	m_ColorBSlider.SetPos(value);

	float b = (float)value / 255;
	b = round(b * 1000.0f) / 1000.0f;
	g_pRenderer->SetPointLightColorB(b);
}


void CDlgPointLight::OnEnChangeRangeEdit()
{
	CString str;
	m_RangeEdit.GetWindowText(str);
	int value = _ttoi(str);

	m_RangeSlider.SetPos(value);
	g_pRenderer->SetPointLightRange(value);
}

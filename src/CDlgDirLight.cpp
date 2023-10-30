// CDlgDirLight.cpp : implementation file
//

#include "pch.h"
#include "ModelViewer.h"
#include "afxdialogex.h"
#include "CDlgDirLight.h"


// CDlgDirLight dialog

IMPLEMENT_DYNAMIC(CDlgDirLight, CDialogEx)

CDlgDirLight::CDlgDirLight(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIRLIGHT_DIALOG, pParent)
{

}

CDlgDirLight::~CDlgDirLight()
{
}

void CDlgDirLight::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_DIR_X_SLIDER, m_DirXSlider);
	DDX_Control(pDX, IDC_DIR_Y_SLIDER, m_DirYSlider);
	DDX_Control(pDX, IDC_DIR_Z_SLIDER, m_DirZSlider);
	DDX_Control(pDX, IDC_COLOR_R_SLIDER, m_ColorRSlider);
	DDX_Control(pDX, IDC_COLOR_G_SLIDER, m_ColorGSlider);
	DDX_Control(pDX, IDC_COLOR_B_SLIDER, m_ColorBSlider);
	DDX_Control(pDX, IDC_DIR_X_EDIT, m_DirXEdit);
	DDX_Control(pDX, IDC_DIR_Y_EDIT, m_DirYEdit);
	DDX_Control(pDX, IDC_DIR_Z_EDIT, m_DirZEdit);
	DDX_Control(pDX, IDC_COLOR_R_EDIT, m_ColorREdit);
	DDX_Control(pDX, IDC_COLOR_G_EDIT, m_ColorGEdit);
	DDX_Control(pDX, IDC_COLOR_B_EDIT, m_ColorBEdit);
}


BEGIN_MESSAGE_MAP(CDlgDirLight, CDialogEx)
	ON_BN_CLICKED(IDC_ONOFF_CHECK, &CDlgDirLight::OnBnClickedOnoffCheck)
	ON_WM_HSCROLL()
	ON_EN_CHANGE(IDC_DIR_X_EDIT, &CDlgDirLight::OnEnChangeDirXEdit)
	ON_EN_CHANGE(IDC_DIR_Y_EDIT, &CDlgDirLight::OnEnChangeDirYEdit)
	ON_EN_CHANGE(IDC_DIR_Z_EDIT, &CDlgDirLight::OnEnChangeDirZEdit)
	ON_EN_CHANGE(IDC_COLOR_R_EDIT, &CDlgDirLight::OnEnChangeColorREdit)
	ON_EN_CHANGE(IDC_COLOR_G_EDIT, &CDlgDirLight::OnEnChangeColorGEdit)
	ON_EN_CHANGE(IDC_COLOR_B_EDIT, &CDlgDirLight::OnEnChangeColorBEdit)
END_MESSAGE_MAP()


// CDlgDirLight message handlers


BOOL CDlgDirLight::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	CButton* pOnOffCheck = (CButton*)GetDlgItem(IDC_ONOFF_CHECK);
	pOnOffCheck->SetCheck(TRUE);

	int lowestPos  = -50;
	int highestPos = 50;
	CString dirValStr;

	m_DirXSlider.SetRange(lowestPos, highestPos);
	m_DirXSlider.SetTicFreq(1);
	m_DirXSlider.SetPos(0);
	dirValStr.Format(_T("%d"), 0);
	m_DirXEdit.SetWindowTextW(dirValStr);

	m_DirYSlider.SetRange(lowestPos, highestPos);
	m_DirYSlider.SetTicFreq(1);
	m_DirYSlider.SetPos(30);
	dirValStr.Format(_T("%d"), 30);
	m_DirYEdit.SetWindowTextW(dirValStr);

	m_DirZSlider.SetRange(lowestPos, highestPos);
	m_DirZSlider.SetTicFreq(1);
	m_DirZSlider.SetPos(-15);
	dirValStr.Format(_T("%d"), -15);
	m_DirZEdit.SetWindowTextW(dirValStr);

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

	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX Property Pages should return FALSE
}

void CDlgDirLight::OnBnClickedOnoffCheck()
{
	CButton* pOnOffCheck = (CButton*)GetDlgItem(IDC_ONOFF_CHECK);
	
	if (pOnOffCheck->GetCheck())
	{
		int posR = m_ColorRSlider.GetPos();
		float r = (float)posR / 255;
		r = round(r * 1000.0f) / 1000.0f;
		g_pRenderer->SetDirLightColorR(r);

		int posG = m_ColorGSlider.GetPos();
		float g = (float)posG / 255;
		g = round(g * 1000.0f) / 1000.0f;
		g_pRenderer->SetDirLightColorG(g);

		int posB = m_ColorBSlider.GetPos();
		float b = (float)posB / 255;
		b = round(b * 1000.0f) / 1000.0f;
		g_pRenderer->SetDirLightColorB(b);

		m_DirXSlider.EnableWindow(TRUE);
		m_DirYSlider.EnableWindow(TRUE);
		m_DirZSlider.EnableWindow(TRUE);
		m_DirXEdit.EnableWindow(TRUE);
		m_DirYEdit.EnableWindow(TRUE);
		m_DirZEdit.EnableWindow(TRUE);

		m_ColorRSlider.EnableWindow(TRUE);
		m_ColorGSlider.EnableWindow(TRUE);
		m_ColorBSlider.EnableWindow(TRUE);
		m_ColorREdit.EnableWindow(TRUE);
		m_ColorGEdit.EnableWindow(TRUE);
		m_ColorBEdit.EnableWindow(TRUE);
	}
	else
	{
		g_pRenderer->SetDirLightColorR(0.0f);
		g_pRenderer->SetDirLightColorG(0.0f);
		g_pRenderer->SetDirLightColorB(0.0f);

		m_DirXSlider.EnableWindow(FALSE);
		m_DirYSlider.EnableWindow(FALSE);
		m_DirZSlider.EnableWindow(FALSE);
		m_DirXEdit.EnableWindow(FALSE);
		m_DirYEdit.EnableWindow(FALSE);
		m_DirZEdit.EnableWindow(FALSE);

		m_ColorRSlider.EnableWindow(FALSE);
		m_ColorGSlider.EnableWindow(FALSE);
		m_ColorBSlider.EnableWindow(FALSE);
		m_ColorREdit.EnableWindow(FALSE);
		m_ColorGEdit.EnableWindow(FALSE);
		m_ColorBEdit.EnableWindow(FALSE);
	}
}


void CDlgDirLight::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
{
	CSliderCtrl* pSlideCtrl = reinterpret_cast<CSliderCtrl*>(pScrollBar);
	int pos = pSlideCtrl->GetPos();
	float t = 0.0f;
	switch (pSlideCtrl->GetDlgCtrlID())
	{
	case IDC_DIR_X_SLIDER:
		SetDlgItemInt(IDC_DIR_X_EDIT, pos);
		g_pRenderer->SetDirLightDirectionX(pos);
		break;
	case IDC_DIR_Y_SLIDER:
		SetDlgItemInt(IDC_DIR_Y_EDIT, pos);
		g_pRenderer->SetDirLightDirectionY(pos);
		break;
	case IDC_DIR_Z_SLIDER:
		SetDlgItemInt(IDC_DIR_Z_EDIT, pos);
		g_pRenderer->SetDirLightDirectionZ(pos);
		break;
	case IDC_COLOR_R_SLIDER:
		SetDlgItemInt(IDC_COLOR_R_EDIT, pos);
		t = (float)pos / 255;
		t = round(t * 1000.0f) / 1000.0f;
		g_pRenderer->SetDirLightColorR(t);
		break;
	case IDC_COLOR_G_SLIDER:
		SetDlgItemInt(IDC_COLOR_G_EDIT, pos);
		t = (float)pos / 255;
		t = round(t * 1000.0f) / 1000.0f;
		g_pRenderer->SetDirLightColorG(t);
		break;
	case IDC_COLOR_B_SLIDER:
		SetDlgItemInt(IDC_COLOR_B_EDIT, pos);
		t = (float)pos / 255;
		t = round(t * 1000.0f) / 1000.0f;
		g_pRenderer->SetDirLightColorB(t);
		break;
	}

	CDialogEx::OnHScroll(nSBCode, nPos, pScrollBar);
}


void CDlgDirLight::OnEnChangeDirXEdit()
{
	CString str;
	m_DirXEdit.GetWindowText(str);
	int value = _ttoi(str);

	m_DirXSlider.SetPos(value);
	g_pRenderer->SetDirLightDirectionX(value);
}


void CDlgDirLight::OnEnChangeDirYEdit()
{
	CString str;
	m_DirYEdit.GetWindowText(str);
	int value = _ttoi(str);

	m_DirYSlider.SetPos(value);
	g_pRenderer->SetDirLightDirectionY(value);
}


void CDlgDirLight::OnEnChangeDirZEdit()
{
	CString str;
	m_DirZEdit.GetWindowText(str);
	int value = _ttoi(str);

	m_DirZSlider.SetPos(value);
	g_pRenderer->SetDirLightDirectionZ(value);
}


void CDlgDirLight::OnEnChangeColorREdit()
{
	CString str;
	m_ColorREdit.GetWindowText(str);
	int value = _ttoi(str);

	m_ColorRSlider.SetPos(value);

	float r = (float)value / 255;
	r = round(r * 1000.0f) / 1000.0f;
	g_pRenderer->SetDirLightColorR(r);
}


void CDlgDirLight::OnEnChangeColorGEdit()
{
	CString str;
	m_ColorGEdit.GetWindowText(str);
	int value = _ttoi(str);

	m_ColorGSlider.SetPos(value);

	float g = (float)value / 255;
	g = round(g * 1000.0f) / 1000.0f;
	g_pRenderer->SetDirLightColorG(g);
}


void CDlgDirLight::OnEnChangeColorBEdit()
{
	CString str;
	m_ColorBEdit.GetWindowText(str);
	int value = _ttoi(str);

	m_ColorBSlider.SetPos(value);

	float b = (float)value / 255;
	b = round(b * 1000.0f) / 1000.0f;
	g_pRenderer->SetDirLightColorB(b);
}

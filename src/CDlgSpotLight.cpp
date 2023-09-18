// CDlgSpotLight.cpp : implementation file
//

#include "pch.h"
#include "ModelViewer.h"
#include "afxdialogex.h"
#include "CDlgSpotLight.h"


// CDlgSpotLight dialog

IMPLEMENT_DYNAMIC(CDlgSpotLight, CDialogEx)

CDlgSpotLight::CDlgSpotLight(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_SPOTLIGHT_DIALOG, pParent)
{

}

CDlgSpotLight::~CDlgSpotLight()
{
}

void CDlgSpotLight::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_POS_X_SLIDER, m_PosXSlider);
	DDX_Control(pDX, IDC_POS_Y_SLIDER, m_PosYSlider);
	DDX_Control(pDX, IDC_POS_Z_SLIDER, m_PosZSlider);
	DDX_Control(pDX, IDC_POS_X_EDIT, m_PosXEdit);
	DDX_Control(pDX, IDC_POS_Y_EDIT, m_PosYEdit);
	DDX_Control(pDX, IDC_POS_Z_EDIT, m_PosZEdit);
	DDX_Control(pDX, IDC_DIR_X_SLIDER, m_DirXSlider);
	DDX_Control(pDX, IDC_DIR_Y_SLIDER, m_DirYSlider);
	DDX_Control(pDX, IDC_DIR_Z_SLIDER, m_DirZSlider);
	DDX_Control(pDX, IDC_DIR_X_EDIT, m_DirXEdit);
	DDX_Control(pDX, IDC_DIR_Y_EDIT, m_DirYEdit);
	DDX_Control(pDX, IDC_DIR_Z_EDIT, m_DirZEdit);
	DDX_Control(pDX, IDC_COLOR_R_SLIDER, m_ColorRSlider);
	DDX_Control(pDX, IDC_COLOR_G_SLIDER, m_ColorGSlider);
	DDX_Control(pDX, IDC_COLOR_B_SLIDER, m_ColorBSlider);
	DDX_Control(pDX, IDC_COLOR_R_EDIT, m_ColorREdit);
	DDX_Control(pDX, IDC_COLOR_G_EDIT, m_ColorGEdit);
	DDX_Control(pDX, IDC_COLOR_B_EDIT, m_ColorBEdit);
	DDX_Control(pDX, IDC_RANGE_SLIDER, m_RangeSlider);
	DDX_Control(pDX, IDC_RANGE_EDIT, m_RangeEdit);
	DDX_Control(pDX, IDC_ANGLE_SLIDER, m_AngleSlider);
	DDX_Control(pDX, IDC_ANGLE_EDIT, m_AngleEdit);
}


BEGIN_MESSAGE_MAP(CDlgSpotLight, CDialogEx)
	ON_WM_HSCROLL()
	ON_BN_CLICKED(IDC_ONOFF_CHECK, &CDlgSpotLight::OnBnClickedOnoffCheck)
	ON_EN_CHANGE(IDC_POS_X_EDIT, &CDlgSpotLight::OnEnChangePosXEdit)
	ON_EN_CHANGE(IDC_POS_Y_EDIT, &CDlgSpotLight::OnEnChangePosYEdit)
	ON_EN_CHANGE(IDC_POS_Z_EDIT, &CDlgSpotLight::OnEnChangePosZEdit)
	ON_EN_CHANGE(IDC_DIR_X_EDIT, &CDlgSpotLight::OnEnChangeDirXEdit)
	ON_EN_CHANGE(IDC_DIR_Y_EDIT, &CDlgSpotLight::OnEnChangeDirYEdit)
	ON_EN_CHANGE(IDC_DIR_Z_EDIT, &CDlgSpotLight::OnEnChangeDirZEdit)
	ON_EN_CHANGE(IDC_COLOR_R_EDIT, &CDlgSpotLight::OnEnChangeColorREdit)
	ON_EN_CHANGE(IDC_COLOR_G_EDIT, &CDlgSpotLight::OnEnChangeColorGEdit)
	ON_EN_CHANGE(IDC_COLOR_B_EDIT, &CDlgSpotLight::OnEnChangeColorBEdit)
	ON_EN_CHANGE(IDC_RANGE_EDIT, &CDlgSpotLight::OnEnChangeRangeEdit)
	ON_EN_CHANGE(IDC_ANGLE_EDIT, &CDlgSpotLight::OnEnChangeAngleEdit)
END_MESSAGE_MAP()


// CDlgSpotLight message handlers


BOOL CDlgSpotLight::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	CButton* pOnOffCheck = (CButton*)GetDlgItem(IDC_ONOFF_CHECK);
	pOnOffCheck->SetCheck(TRUE);

	int lowestPos = -1000;
	int highestPos = 1000;
	CString posValStr;

	m_PosXSlider.SetRange(lowestPos, highestPos);
	m_PosXSlider.SetTicFreq(1);
	m_PosXSlider.SetPos(0);
	posValStr.Format(_T("%d"), 0);
	m_PosXEdit.SetWindowTextW(posValStr);

	m_PosYSlider.SetRange(lowestPos, highestPos);
	m_PosYSlider.SetTicFreq(1);
	m_PosYSlider.SetPos(20);
	posValStr.Format(_T("%d"), 20);
	m_PosYEdit.SetWindowTextW(posValStr);

	m_PosZSlider.SetRange(lowestPos, highestPos);
	m_PosZSlider.SetTicFreq(1);
	m_PosZSlider.SetPos(-50);
	posValStr.Format(_T("%d"), -50);
	m_PosZEdit.SetWindowTextW(posValStr);

	int lowestDir = -1000;
	int highestDir = 1000;
	CString dirValStr;

	m_DirXSlider.SetRange(lowestDir, highestDir);
	m_DirXSlider.SetTicFreq(1);
	m_DirXSlider.SetPos(1);
	dirValStr.Format(_T("%d"), 1);
	m_DirXEdit.SetWindowTextW(dirValStr);

	m_DirYSlider.SetRange(lowestDir, highestDir);
	m_DirYSlider.SetTicFreq(1);
	m_DirYSlider.SetPos(-1);
	dirValStr.Format(_T("%d"), -1);
	m_DirYEdit.SetWindowTextW(dirValStr);

	m_DirZSlider.SetRange(lowestDir, highestDir);
	m_DirZSlider.SetTicFreq(1);
	m_DirZSlider.SetPos(1);
	dirValStr.Format(_T("%d"), 1);
	m_DirZEdit.SetWindowTextW(dirValStr);

	int lowestColor = 0;
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

	int lowestRange = 0;
	int highestRange = 1000;
	CString rangeValStr;

	rangeValStr.Format(_T("%d"), 1000);

	m_RangeSlider.SetRange(lowestRange, highestRange);
	m_RangeSlider.SetTicFreq(1);
	m_RangeSlider.SetPos(1000);
	m_RangeEdit.SetWindowTextW(rangeValStr);

	int lowestAngle  = -90;
	int highestAngle = 360;
	CString angleValStr;

	angleValStr.Format(_T("%d"), 200);

	m_AngleSlider.SetRange(lowestAngle, highestAngle);
	m_AngleSlider.SetTicFreq(1);
	m_AngleSlider.SetPos(200);
	m_AngleEdit.SetWindowTextW(angleValStr);

	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX Property Pages should return FALSE
}


void CDlgSpotLight::OnBnClickedOnoffCheck()
{
	CButton* pOnOffCheck = (CButton*)GetDlgItem(IDC_ONOFF_CHECK);

	if (pOnOffCheck->GetCheck())
	{
		int posR = m_ColorRSlider.GetPos();
		float r = (float)posR / 255;
		r = round(r * 1000.0f) / 1000.0f;
		g_pRenderer->SetSptLightColorR(r);

		int posG = m_ColorGSlider.GetPos();
		float g = (float)posG / 255;
		g = round(g * 1000.0f) / 1000.0f;
		g_pRenderer->SetSptLightColorG(g);

		int posB = m_ColorBSlider.GetPos();
		float b = (float)posB / 255;
		b = round(b * 1000.0f) / 1000.0f;
		g_pRenderer->SetSptLightColorB(b);

		m_PosXSlider.EnableWindow(TRUE);
		m_PosYSlider.EnableWindow(TRUE);
		m_PosZSlider.EnableWindow(TRUE);
		m_PosXEdit.EnableWindow(TRUE);
		m_PosYEdit.EnableWindow(TRUE);
		m_PosZEdit.EnableWindow(TRUE);

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

		m_RangeSlider.EnableWindow(TRUE);
		m_RangeEdit.EnableWindow(TRUE);

		m_AngleSlider.EnableWindow(TRUE);
		m_AngleEdit.EnableWindow(TRUE);
	}
	else
	{
		g_pRenderer->SetSptLightColorR(0.0f);
		g_pRenderer->SetSptLightColorG(0.0f);
		g_pRenderer->SetSptLightColorB(0.0f);

		m_PosXSlider.EnableWindow(FALSE);
		m_PosYSlider.EnableWindow(FALSE);
		m_PosZSlider.EnableWindow(FALSE);
		m_PosXEdit.EnableWindow(FALSE);
		m_PosYEdit.EnableWindow(FALSE);
		m_PosZEdit.EnableWindow(FALSE);

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

		m_RangeSlider.EnableWindow(FALSE);
		m_RangeEdit.EnableWindow(FALSE);

		m_AngleSlider.EnableWindow(FALSE);
		m_AngleEdit.EnableWindow(FALSE);
	}
}


void CDlgSpotLight::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
{
	CSliderCtrl* pSlideCtrl = reinterpret_cast<CSliderCtrl*>(pScrollBar);
	int pos = pSlideCtrl->GetPos();
	float t = 0.0f;
	switch (pSlideCtrl->GetDlgCtrlID())
	{
	case IDC_POS_X_SLIDER:
		SetDlgItemInt(IDC_POS_X_EDIT, pos);
		g_pRenderer->SetSptLightPositionX(pos);
		break;
	case IDC_POS_Y_SLIDER:
		SetDlgItemInt(IDC_POS_Y_EDIT, pos);
		g_pRenderer->SetSptLightPositionY(pos);
		break;
	case IDC_POS_Z_SLIDER:
		SetDlgItemInt(IDC_POS_Z_EDIT, pos);
		g_pRenderer->SetSptLightPositionZ(pos);
		break;
	case IDC_DIR_X_SLIDER:
		SetDlgItemInt(IDC_DIR_X_EDIT, pos);
		g_pRenderer->SetSptLightDirectionX(pos);
		break;
	case IDC_DIR_Y_SLIDER:
		SetDlgItemInt(IDC_DIR_Y_EDIT, pos);
		g_pRenderer->SetSptLightDirectionY(pos);
		break;
	case IDC_DIR_Z_SLIDER:
		SetDlgItemInt(IDC_DIR_Z_EDIT, pos);
		g_pRenderer->SetSptLightDirectionZ(pos);
		break;
	case IDC_COLOR_R_SLIDER:
		SetDlgItemInt(IDC_COLOR_R_EDIT, pos);
		t = (float)pos / 255;
		t = round(t * 1000.0f) / 1000.0f;
		g_pRenderer->SetSptLightColorR(t);
		break;
	case IDC_COLOR_G_SLIDER:
		SetDlgItemInt(IDC_COLOR_G_EDIT, pos);
		t = (float)pos / 255;
		t = round(t * 1000.0f) / 1000.0f;
		g_pRenderer->SetSptLightColorG(t);
		break;
	case IDC_COLOR_B_SLIDER:
		SetDlgItemInt(IDC_COLOR_B_EDIT, pos);
		t = (float)pos / 255;
		t = round(t * 1000.0f) / 1000.0f;
		g_pRenderer->SetSptLightColorB(t);
		break;
	case IDC_RANGE_SLIDER:
		SetDlgItemInt(IDC_RANGE_EDIT, pos);
		g_pRenderer->SetSptLightRange(pos);
		break;
	case IDC_ANGLE_SLIDER:
		SetDlgItemInt(IDC_ANGLE_EDIT, pos);
		g_pRenderer->SetSptLightAngle(pos);
		break;
	}

	CDialogEx::OnHScroll(nSBCode, nPos, pScrollBar);
}


void CDlgSpotLight::OnEnChangePosXEdit()
{
	CString str;
	m_PosXEdit.GetWindowText(str);
	int value = _ttoi(str);

	m_PosXSlider.SetPos(value);
	g_pRenderer->SetSptLightPositionX(value);
}


void CDlgSpotLight::OnEnChangePosYEdit()
{
	CString str;
	m_PosYEdit.GetWindowText(str);
	int value = _ttoi(str);

	m_PosXSlider.SetPos(value);
	g_pRenderer->SetSptLightPositionY(value);
}


void CDlgSpotLight::OnEnChangePosZEdit()
{
	CString str;
	m_PosZEdit.GetWindowText(str);
	int value = _ttoi(str);

	m_PosZSlider.SetPos(value);
	g_pRenderer->SetSptLightPositionZ(value);
}


void CDlgSpotLight::OnEnChangeDirXEdit()
{
	CString str;
	m_DirXEdit.GetWindowText(str);
	int value = _ttoi(str);

	m_DirXSlider.SetPos(value);
	g_pRenderer->SetSptLightDirectionX(value);
}


void CDlgSpotLight::OnEnChangeDirYEdit()
{
	CString str;
	m_DirYEdit.GetWindowText(str);
	int value = _ttoi(str);

	m_DirYSlider.SetPos(value);
	g_pRenderer->SetSptLightDirectionY(value);
}


void CDlgSpotLight::OnEnChangeDirZEdit()
{
	CString str;
	m_DirZEdit.GetWindowText(str);
	int value = _ttoi(str);

	m_DirZSlider.SetPos(value);
	g_pRenderer->SetSptLightDirectionZ(value);
}


void CDlgSpotLight::OnEnChangeColorREdit()
{
	CString str;
	m_ColorREdit.GetWindowText(str);
	int value = _ttoi(str);

	m_ColorRSlider.SetPos(value);

	float r = (float)value / 255;
	r = round(r * 1000.0f) / 1000.0f;
	g_pRenderer->SetSptLightColorR(r);
}


void CDlgSpotLight::OnEnChangeColorGEdit()
{
	CString str;
	m_ColorREdit.GetWindowText(str);
	int value = _ttoi(str);

	m_ColorGSlider.SetPos(value);

	float g = (float)value / 255;
	g = round(g * 1000.0f) / 1000.0f;
	g_pRenderer->SetSptLightColorG(g);
}


void CDlgSpotLight::OnEnChangeColorBEdit()
{
	CString str;
	m_ColorBEdit.GetWindowText(str);
	int value = _ttoi(str);

	m_ColorBSlider.SetPos(value);

	float b = (float)value / 255;
	b = round(b * 1000.0f) / 1000.0f;
	g_pRenderer->SetSptLightColorB(b);
}


void CDlgSpotLight::OnEnChangeRangeEdit()
{
	CString str;
	m_RangeEdit.GetWindowText(str);
	int value = _ttoi(str);

	m_RangeSlider.SetPos(value);
	g_pRenderer->SetSptLightRange(value);
}


void CDlgSpotLight::OnEnChangeAngleEdit()
{
	CString str;
	m_AngleEdit.GetWindowText(str);
	int value = _ttoi(str);

	m_AngleSlider.SetPos(value);
	g_pRenderer->SetSptLightAngle(value);
}

// CDlgLighting.cpp : implementation file
//

#include "pch.h"
#include "ModelViewer.h"
#include "afxdialogex.h"
#include "CDlgLighting.h"


// CDlgLighting dialog

IMPLEMENT_DYNAMIC(CDlgLighting, CDialogEx)

CDlgLighting::CDlgLighting(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_LIGHTING_DIALOG, pParent)
{

}

CDlgLighting::~CDlgLighting()
{
}

void CDlgLighting::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_TAB, m_Tab);
}


BEGIN_MESSAGE_MAP(CDlgLighting, CDialogEx)
	ON_NOTIFY(TCN_SELCHANGE, IDC_TAB, &CDlgLighting::OnSelchangeTab)
END_MESSAGE_MAP()


// CDlgLighting message handlers


BOOL CDlgLighting::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	CRect rect;
	m_Tab.GetWindowRect(&rect);

	m_Tab.InsertItem(0, L"Directional");
	m_Tab.InsertItem(1, L"Point");
	m_Tab.InsertItem(2, L"Spot");

	m_Tab.SetCurSel(0);

	m_pDlgDirLight = new CDlgDirLight;
	m_pDlgDirLight->Create(IDD_DIRLIGHT_DIALOG, &m_Tab);
	m_pDlgDirLight->MoveWindow(0, 20, rect.Width(), rect.Height());
	m_pDlgDirLight->ShowWindow(SW_SHOW);

	m_pDlgPointLight = new CDlgPointLight;
	m_pDlgPointLight->Create(IDD_POINTLIGHT_DIALOG, &m_Tab);
	m_pDlgPointLight->MoveWindow(0, 20, rect.Width(), rect.Height());
	m_pDlgPointLight->ShowWindow(SW_HIDE);

	m_pDlgSpotLight = new CDlgSpotLight;
	m_pDlgSpotLight->Create(IDD_SPOTLIGHT_DIALOG, &m_Tab);
	m_pDlgSpotLight->MoveWindow(0, 20, rect.Width(), rect.Height());
	m_pDlgSpotLight->ShowWindow(SW_HIDE);

	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX Property Pages should return FALSE
}


void CDlgLighting::OnSelchangeTab(NMHDR* pNMHDR, LRESULT* pResult)
{
    if (IDC_TAB == pNMHDR->idFrom) { // Tab Control ID¸í
        int select = m_Tab.GetCurSel();
        switch (select) {
        case 0:
			m_pDlgDirLight->ShowWindow(SW_SHOW);
            m_pDlgPointLight->ShowWindow(SW_HIDE);
            m_pDlgSpotLight->ShowWindow(SW_HIDE);
            break;
		case 1:
			m_pDlgDirLight->ShowWindow(SW_HIDE);
			m_pDlgPointLight->ShowWindow(SW_SHOW);
			m_pDlgSpotLight->ShowWindow(SW_HIDE);
			break;
		case 2:
			m_pDlgDirLight->ShowWindow(SW_HIDE);
			m_pDlgPointLight->ShowWindow(SW_HIDE);
			m_pDlgSpotLight->ShowWindow(SW_SHOW);
			break;
        }
    }
	*pResult = 0;
}

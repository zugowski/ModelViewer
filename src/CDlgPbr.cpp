// CDlgPbr.cpp : implementation file
//

#include "pch.h"
#include "ModelViewer.h"
#include "afxdialogex.h"
#include "CDlgPbr.h"


// CDlgPbr dialog

IMPLEMENT_DYNAMIC(CDlgPbr, CDialogEx)

CDlgPbr::CDlgPbr(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_PBR_DIALOG, pParent)
{

}

CDlgPbr::~CDlgPbr()
{
}

void CDlgPbr::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CDlgPbr, CDialogEx)
	ON_BN_CLICKED(IDC_ALBEDO_BROWSE_BTN, &CDlgPbr::OnBnClickedAlbedoBrowseBtn)
	ON_BN_CLICKED(IDC_NORMAL_BROWSE_BTN, &CDlgPbr::OnBnClickedNormalBrowseBtn)
	ON_BN_CLICKED(IDC_METALIC_BROWSE_BTN, &CDlgPbr::OnBnClickedMetalicBrowseBtn)
	ON_BN_CLICKED(IDC_ROUGHNESS_BROWSE_BTN, &CDlgPbr::OnBnClickedRoughnessBrowseBtn)
	ON_BN_CLICKED(IDOK, &CDlgPbr::OnBnClickedOk)
END_MESSAGE_MAP()


// CDlgPbr message handlers


void CDlgPbr::OnBnClickedAlbedoBrowseBtn()
{
	const wchar_t szFilter[] = L"PNG 颇老 (*.png) |*.png||";

	CString fileName;
	CString filePath;

	CFileDialog fileDlg(TRUE, NULL, NULL, OFN_EXPLORER | OFN_HIDEREADONLY, szFilter);
	//fileDlg.m_ofn.nFilterIndex = 1;
	
	if (fileDlg.DoModal() == IDOK)
	{
		fileName = fileDlg.GetFileName();
		filePath = fileDlg.GetPathName();
		SetDlgItemText(IDC_ALBEDO_EDIT, filePath);
	}
}


void CDlgPbr::OnBnClickedNormalBrowseBtn()
{
	const wchar_t szFilter[] = L"PNG 颇老 (*.png) |*.png||";

	CString fileName;
	CString filePath;

	CFileDialog fileDlg(TRUE, NULL, NULL, OFN_EXPLORER | OFN_HIDEREADONLY, szFilter);
	//fileDlg.m_ofn.nFilterIndex = 1;

	if (fileDlg.DoModal() == IDOK)
	{
		fileName = fileDlg.GetFileName();
		filePath = fileDlg.GetPathName();
		SetDlgItemText(IDC_NORMAL_EDIT, filePath);
	}
}


void CDlgPbr::OnBnClickedMetalicBrowseBtn()
{
	const wchar_t szFilter[] = L"PNG 颇老 (*.png) |*.png||";

	CString fileName;
	CString filePath;

	CFileDialog fileDlg(TRUE, NULL, NULL, OFN_EXPLORER | OFN_HIDEREADONLY, szFilter);
	//fileDlg.m_ofn.nFilterIndex = 1;

	if (fileDlg.DoModal() == IDOK)
	{
		fileName = fileDlg.GetFileName();
		filePath = fileDlg.GetPathName();
		SetDlgItemText(IDC_METALIC_EDIT, filePath);
	}
}


void CDlgPbr::OnBnClickedRoughnessBrowseBtn()
{
	const wchar_t szFilter[] = L"PNG 颇老 (*.png) |*.png||";

	CString fileName;
	CString filePath;

	CFileDialog fileDlg(TRUE, NULL, NULL, OFN_EXPLORER | OFN_HIDEREADONLY, szFilter);
	//fileDlg.m_ofn.nFilterIndex = 1;

	if (fileDlg.DoModal() == IDOK)
	{
		fileName = fileDlg.GetFileName();
		filePath = fileDlg.GetPathName();
		SetDlgItemText(IDC_ROUGHNESS_EDIT, filePath);
	}
}


void CDlgPbr::OnBnClickedOk()
{
	CString albedoMapPath, normalMapPath, metalicMapPath, roughnessMapPath;
	GetDlgItemText(IDC_ALBEDO_EDIT, albedoMapPath);
	GetDlgItemText(IDC_NORMAL_EDIT, normalMapPath);
	GetDlgItemText(IDC_METALIC_EDIT, metalicMapPath);
	GetDlgItemText(IDC_ROUGHNESS_EDIT, roughnessMapPath);

	g_pRenderer->SetPbrAlbedoMap(albedoMapPath);
	g_pRenderer->SetPbrNormalMap(normalMapPath);
	g_pRenderer->SetPbrMetalicMap(metalicMapPath);
	g_pRenderer->SetPbrRoughnessMap(roughnessMapPath);

	g_pRenderer->SetPbrRender();
	CDialogEx::OnOK();
}

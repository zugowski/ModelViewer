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
	ON_BN_CLICKED(IDC_ALBEDO_BROWSE_BTN, &CDlgPbr::OnBnClickedBrowseBtn)
	ON_BN_CLICKED(IDC_NORMAL_BROWSE_BTN, &CDlgPbr::OnBnClickedNormalBrowseBtn)
	ON_BN_CLICKED(IDC_METALIC_BROWSE_BTN, &CDlgPbr::OnBnClickedMetalicBrowseBtn)
	ON_BN_CLICKED(IDC_ROUGHNESS_BROWSE_BTN, &CDlgPbr::OnBnClickedRoughnessBrowseBtn)
	ON_BN_CLICKED(IDOK, &CDlgPbr::OnBnClickedOk)
END_MESSAGE_MAP()


// CDlgPbr message handlers


void CDlgPbr::OnBnClickedBrowseBtn()
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
		g_pRenderer->SetPbrAlbedoMap(nullptr);
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
	}
}


void CDlgPbr::OnBnClickedOk()
{

	CDialogEx::OnOK();
}

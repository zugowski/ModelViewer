
// ModelViewer.cpp : Defines the class behaviors for the application.
//

#include "pch.h"
#include "framework.h"
#include "afxwinappex.h"
#include "afxdialogex.h"
#include "ModelViewer.h"
#include "MainFrm.h"

#include "ModelViewerDoc.h"
#include "ModelViewerView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CModelViewerApp

BEGIN_MESSAGE_MAP(CModelViewerApp, CWinApp)
	ON_COMMAND(ID_APP_ABOUT, &CModelViewerApp::OnAppAbout)
	// Standard file based document commands
	ON_COMMAND(ID_FILE_NEW, &CWinApp::OnFileNew)
	//ON_COMMAND(ID_FILE_OPEN, &CWinApp::OnFileOpen)
	ON_COMMAND(ID_FILE_OPEN, &CModelViewerApp::OnFileOpen)
END_MESSAGE_MAP()


// CModelViewerApp construction

CModelViewerApp::CModelViewerApp() noexcept
{

	// TODO: replace application ID string below with unique ID string; recommended
	// format for string is CompanyName.ProductName.SubProduct.VersionInformation
	SetAppID(_T("ModelViewer.AppID.NoVersion"));

	// TODO: add construction code here,
	// Place all significant initialization in InitInstance
}

// The one and only CModelViewerApp object

CModelViewerApp theApp;


// CModelViewerApp initialization

BOOL CModelViewerApp::InitInstance()
{
	// InitCommonControlsEx() is required on Windows XP if an application
	// manifest specifies use of ComCtl32.dll version 6 or later to enable
	// visual styles.  Otherwise, any window creation will fail.
	INITCOMMONCONTROLSEX InitCtrls;
	InitCtrls.dwSize = sizeof(InitCtrls);
	// Set this to include all the common control classes you want to use
	// in your application.
	InitCtrls.dwICC = ICC_WIN95_CLASSES;
	InitCommonControlsEx(&InitCtrls);

	CWinApp::InitInstance();


	EnableTaskbarInteraction(FALSE);

	// AfxInitRichEdit2() is required to use RichEdit control
	// AfxInitRichEdit2();

	// Standard initialization
	// If you are not using these features and wish to reduce the size
	// of your final executable, you should remove from the following
	// the specific initialization routines you do not need
	// Change the registry key under which our settings are stored
	// TODO: You should modify this string to be something appropriate
	// such as the name of your company or organization
	SetRegistryKey(_T("Local AppWizard-Generated Applications"));
	LoadStdProfileSettings(4);  // Load standard INI file options (including MRU)


	// Register the application's document templates.  Document templates
	//  serve as the connection between documents, frame windows and views
	CSingleDocTemplate* pDocTemplate;
	pDocTemplate = new CSingleDocTemplate(
		IDR_MAINFRAME,
		RUNTIME_CLASS(CModelViewerDoc),
		RUNTIME_CLASS(CMainFrame),       // main SDI frame window
		RUNTIME_CLASS(CModelViewerView));
	if (!pDocTemplate)
		return FALSE;
	AddDocTemplate(pDocTemplate);


	// Parse command line for standard shell commands, DDE, file open
	CCommandLineInfo cmdInfo;
	ParseCommandLine(cmdInfo);



	// Dispatch commands specified on the command line.  Will return FALSE if
	// app was launched with /RegServer, /Register, /Unregserver or /Unregister.
	if (!ProcessShellCommand(cmdInfo))
		return FALSE;

	CFrameWnd* pFrame = reinterpret_cast<CFrameWnd*>(m_pMainWnd);
	CView* pView = pFrame->GetActiveView();

	RECT rect;
	pView->GetClientRect(&rect);
	int width = rect.right - rect.left;
	int height = rect.bottom - rect.top;

	g_pRenderer = CreateRenderer(AfxGetInstanceHandle(), pView->GetSafeHwnd(), width, height);

	// The one and only window has been initialized, so show and update it
	m_pMainWnd->ShowWindow(SW_SHOW);
	m_pMainWnd->UpdateWindow();
	return TRUE;
}

// CModelViewerApp message handlers


// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg() noexcept;

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() noexcept : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()

// App command to run the dialog
void CModelViewerApp::OnAppAbout()
{
	CAboutDlg aboutDlg;
	aboutDlg.DoModal();
}

// CModelViewerApp message handlers





BOOL CModelViewerApp::OnIdle(LONG lCount)
{
	CMainFrame* pFrame = reinterpret_cast<CMainFrame*>(AfxGetMainWnd());

	if (pFrame->GetFocus())
	{
		g_pRenderer->Render();
		return TRUE;
	}
	else
	{
		return CWinApp::OnIdle(lCount);
	}
}


void CModelViewerApp::OnFileOpen()
{
	const wchar_t szFilter[] = L"FBX ���� (*.fbx) |*.fbx||";

	CString fileName;
	CString filePath;

	CFileDialog fileDlg(TRUE, NULL, NULL, OFN_EXPLORER | OFN_HIDEREADONLY, szFilter);
	//fileDlg.m_ofn.nFilterIndex = 1;

	if (fileDlg.DoModal() == IDOK)
	{
		// ��ť��Ʈ ������ �籸��
		OpenDocumentFile(fileDlg.GetPathName());

		fileName = fileDlg.GetFileName();
		filePath = fileDlg.GetPathName();
		g_pRenderer->Load(filePath);

		m_DlgLighting = new CDlgLighting;
		m_DlgLighting->Create(IDD_LIGHTING_DIALOG);
		m_DlgLighting->ShowWindow(SW_SHOW);
	}
}

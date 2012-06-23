// NifConvert.cpp : Defines the class behaviors for the application.
//

#include "..\Common\stdafx.h"
#include "NifConvert.h"
#include "NifConvertDlg.h"
#include "..\Common\FDFileHelper.h"

CString					glPathSkyrim;
CString					glPathTemplate;
CNifConvertDlg			dlg;

// CNifConvertApp

BEGIN_MESSAGE_MAP(CNifConvertApp, CWinApp)
	ON_COMMAND(ID_HELP, &CWinApp::OnHelp)
END_MESSAGE_MAP()


// CNifConvertApp construction

CNifConvertApp::CNifConvertApp()
{
	// TODO: add construction code here,
	// Place all significant initialization in InitInstance
}


// The one and only CNifConvertApp object

CNifConvertApp theApp;


// CNifConvertApp initialization

BOOL CNifConvertApp::InitInstance()
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

	AfxInitRichEdit2();
	// Standard initialization
	// If you are not using these features and wish to reduce the size
	// of your final executable, you should remove from the following
	// the specific initialization routines you do not need
	// Change the registry key under which our settings are stored
	// TODO: You should modify this string to be something appropriate
	// such as the name of your company or organization

  LPWSTR* argv;
  int     argc(0);

  argv = CommandLineToArgvW(m_lpCmdLine, &argc);

	if (argc >= 2)
	{
		glPathTemplate = argv[1];
	}
	else
	{
		glPathTemplate = FDFileHelper::getFileOrFolder(_T(""), L"*.nif (*.nif)|*.nif||", L"nif", false, true, _T("Please select template directory"));
	}
	if ((argc >= 1) && (wcsstr(argv[0], L"NifConvert.exe") == NULL))
	{
		glPathSkyrim = argv[0];
	}
	else
	{
		glPathSkyrim = FDFileHelper::getFileOrFolder(_T(""), L"TESV.exe (TESV.exe)|TESV.exe||", L"exe", false, true, _T("Please select SKYRIM directory"));
	}

  LocalFree(argv);


	m_pMainWnd = &dlg;
	INT_PTR nResponse = dlg.DoModal();
	if (nResponse == IDOK)
	{
		// TODO: Place code here to handle when the dialog is
		//  dismissed with OK
	}
	else if (nResponse == IDCANCEL)
	{
		// TODO: Place code here to handle when the dialog is
		//  dismissed with Cancel
	}

  //  clean up Havok
  //delete havokUtilities;

	// Since the dialog has been closed, return FALSE so that we exit the
	//  application, rather than start the application's message pump.
	return FALSE;
}

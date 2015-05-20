// TLBB3_DLL.cpp : 定义 DLL 的初始化例程。
//

#include "stdafx.h"
#include "TLBB3_DLL.h"
#include "MainForm.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CTLBB3_DLLApp

BEGIN_MESSAGE_MAP(CTLBB3_DLLApp, CWinApp)
END_MESSAGE_MAP()


// CTLBB3_DLLApp 构造

CTLBB3_DLLApp::CTLBB3_DLLApp()
{
	// TODO: 在此处添加构造代码，
	// 将所有重要的初始化放置在 InitInstance 中
}


// 唯一的一个 CTLBB3_DLLApp 对象

CTLBB3_DLLApp theApp;


// CTLBB3_DLLApp 初始化

BOOL CTLBB3_DLLApp::InitInstance()
{
	CWinApp::InitInstance();

	return TRUE;
}



#define HOOK_DLL extern "C" __declspec(dllexport)

CMainForm* MainForm;
HHOOK g_hHook;
BOOL is_hook = false;

LRESULT CALLBACK KeyboardProc(int nCode, WPARAM wParam, LPARAM lParam);
HOOK_DLL BOOL WINAPI InstallHook(DWORD dwTID);
HOOK_DLL BOOL WINAPI UnInstallHook();

LRESULT CALLBACK KeyboardProc(int nCode, WPARAM wParam, LPARAM lParam)
{
	BOOL bKeyUp = lParam & (1<<31);
	if (bKeyUp && wParam == VK_HOME&& nCode == HC_ACTION)
	{
		if (MainForm== NULL)
		{
			AFX_MANAGE_STATE(AfxGetStaticModuleState());
			CWnd *pCWnd = CWnd::GetForegroundWindow();
			MainForm = new CMainForm();
			MainForm->Create(IDD_DLG_MAIN, pCWnd);
			MainForm->ShowWindow(SW_SHOW);
		}
		else
		{
			MainForm->ShowWindow(MainForm->IsWindowVisible() ? SW_HIDE : SW_SHOW);
		}
	}
	return ::CallNextHookEx(g_hHook, nCode, wParam, lParam);
}

HOOK_DLL BOOL WINAPI InstallHook(DWORD dwTID)
{
	if (g_hHook == NULL)
	{
		g_hHook = ::SetWindowsHookEx(WH_KEYBOARD, (HOOKPROC)KeyboardProc, theApp.m_hInstance, dwTID);
		if (g_hHook == NULL)
		{
			return FALSE;
		}
		is_hook = true;
	}
	return TRUE;
}

HOOK_DLL BOOL WINAPI UnInstallHook()
{
	if (is_hook) {
		delete MainForm;
		MainForm = NULL;
		is_hook = false;
		if(::UnhookWindowsHookEx(g_hHook)){
			g_hHook = NULL;
			return true;
		}
		return false;
	}
	return false;
}

int CTLBB3_DLLApp::ExitInstance()
{
	delete MainForm;
	MainForm = NULL;
	if (is_hook) {
		::UnhookWindowsHookEx(g_hHook);
		is_hook = false;
	}

	return CWinApp::ExitInstance();
}

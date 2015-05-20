
// TLBB3Dlg.cpp : 实现文件
//

#include "stdafx.h"
#include "TLBB3.h"
#include "TLBB3Dlg.h"
#include "afxdialogex.h"
#include <tlhelp32.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

#pragma comment(lib, "../Debug/tlbb3.lib")

//#define TLBB_WND_CLASS _T("TianLongBaBu WndClass")
#define TLBB_WND_CLASS _T("CalcFrame")

#ifndef WG_HOOK
#define WG_HOOK extern "C" __declspec(dllimport)
#endif


WG_HOOK BOOL WINAPI InstallHook(DWORD dwID);
WG_HOOK BOOL WINAPI UnInstallHook();


// CTLBB3Dlg 对话框
CTLBB3Dlg::CTLBB3Dlg(CWnd* pParent /*=NULL*/)
	: CDialog(CTLBB3Dlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CTLBB3Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_BTN_INJECT_DLL, m_btn_hook);
	DDX_Control(pDX, IDC_BTN_STATIC_CALL, m_btn_unhook);
}

BEGIN_MESSAGE_MAP(CTLBB3Dlg, CDialog)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BTN_INJECT_DLL, &CTLBB3Dlg::OnBnClickedBtnInjectDll)
	ON_WM_DESTROY()
	ON_BN_CLICKED(IDC_BTN_STATIC_CALL, &CTLBB3Dlg::OnBnClickedBtnStaticCall)
	ON_WM_DESTROY()
END_MESSAGE_MAP()


// CTLBB3Dlg 消息处理程序

BOOL CTLBB3Dlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// 设置此对话框的图标。当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码
	is_hook = false;
	m_btn_unhook.EnableWindow(FALSE);

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CTLBB3Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CTLBB3Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


DWORD GetThreadIDByProcssID(DWORD dwProcessID)
{
	DWORD dwThreadID = 0;
	THREADENTRY32 te32 = {sizeof(te32)};
	HANDLE hThreadSnap = CreateToolhelp32Snapshot(TH32CS_SNAPTHREAD,dwProcessID);
	if( Thread32First( hThreadSnap, &te32) )
	{
		do{
			if( dwProcessID == te32.th32OwnerProcessID )
			{
				dwThreadID = te32.th32ThreadID;
				break;
			}
		}while( Thread32Next( hThreadSnap, &te32) );
	} 

	return dwThreadID;
} 

void CTLBB3Dlg::OnBnClickedBtnInjectDll()
{
	HWND wnd_hwnd= ::FindWindow(TLBB_WND_CLASS, NULL);
	if (wnd_hwnd){
		DWORD threadProcessID;
		::GetWindowThreadProcessId(wnd_hwnd, &threadProcessID);
		if (!threadProcessID){
			AfxMessageBox(_T("找不到ProcessId"));
			return ;
		}
		DWORD threadID = GetThreadIDByProcssID(threadProcessID);
		if (!threadID) {
			AfxMessageBox(_T("找不到threadID"));
			return ;
		}
		if (InstallHook(threadID)){
			is_hook = true;
			m_btn_hook.EnableWindow(FALSE);
			m_btn_unhook.EnableWindow(TRUE);
		}
		return ;
	}
	AfxMessageBox(_T("注入失败!"));
}


void CTLBB3Dlg::OnBnClickedBtnStaticCall()
{
if (is_hook){
	UnInstallHook();
	m_btn_unhook.EnableWindow(FALSE);
	m_btn_hook.EnableWindow(TRUE);
}
}


void CTLBB3Dlg::OnDestroy()
{
	CDialog::OnDestroy();
	if (is_hook){
		UnInstallHook();
	}
}

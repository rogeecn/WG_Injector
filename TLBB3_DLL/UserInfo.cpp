// UserInfo.cpp : 实现文件
//

#include "stdafx.h"
#include "TLBB3_DLL.h"
#include "UserInfo.h"
#include "afxdialogex.h"


#define TIMER_ID_USER_INFO 1001
#define TIMER_ID_PET_INFO 1002
// CUserInfo 对话框

IMPLEMENT_DYNAMIC(CUserInfo, CDialogEx)

	CUserInfo::CUserInfo(CWnd* pParent /*=NULL*/)
	: CDialogEx(CUserInfo::IDD, pParent)
{

}

CUserInfo::~CUserInfo()
{
}

void CUserInfo::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST_USER_BASE_INFO, m_user_info_list);
}


BEGIN_MESSAGE_MAP(CUserInfo, CDialogEx)
	ON_WM_TIMER()
	ON_WM_DESTROY()
END_MESSAGE_MAP()


// CUserInfo 消息处理程序


void CUserInfo::OnTimer(UINT_PTR nIDEvent)
{
	switch (nIDEvent)
	{
	case TIMER_ID_PET_INFO:
		break;
	case TIMER_ID_USER_INFO:
		RefreshUserInfo();
		break;
	}

	CDialogEx::OnTimer(nIDEvent);
}


BOOL CUserInfo::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	//header init
	m_user_info_list.InsertColumn(0, _T("名称"));
	m_user_info_list.SetColumnWidth(0, 50);
	m_user_info_list.InsertColumn(1, _T("值"));
	m_user_info_list.SetColumnWidth(1, 150);
	CString items[] = {
		_T("ID"),
		_T("名称"),
		_T("血"),
		_T("蓝"),
		_T("等级"),
		_T("精力"),
		_T("活力"),
		_T("坐标"),
		_T("目标"),
		_T("交子"),
		_T("金钱"),
		_T("元宝"),
		_T("赚点"),
		_T("帮派"),
		_T("称号"),
		_T("经验"),
	};
	for each (CString var in items)
	{
		m_user_info_list.InsertItem(m_user_info_list.GetItemCount(), var);
	}

	SetTimer(TIMER_ID_USER_INFO, 1000,NULL);


	return TRUE;
}


void CUserInfo::RefreshUserInfo(void)
{
	m_user_info_list.SetItemText(0, 1, _T("Rogee"));
	m_user_info_list.SetItemText(1, 1, _T("Rogee"));
	m_user_info_list.SetItemText(2, 1, _T("Rogee"));
}


void CUserInfo::OnDestroy()
{
	CDialogEx::OnDestroy();

	KillTimer(TIMER_ID_USER_INFO);
}

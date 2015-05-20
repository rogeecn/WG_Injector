// UserInfo.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "TLBB3_DLL.h"
#include "UserInfo.h"
#include "afxdialogex.h"


#define TIMER_ID_USER_INFO 1001
#define TIMER_ID_PET_INFO 1002
// CUserInfo �Ի���

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


// CUserInfo ��Ϣ�������


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
	m_user_info_list.InsertColumn(0, _T("����"));
	m_user_info_list.SetColumnWidth(0, 50);
	m_user_info_list.InsertColumn(1, _T("ֵ"));
	m_user_info_list.SetColumnWidth(1, 150);
	CString items[] = {
		_T("ID"),
		_T("����"),
		_T("Ѫ"),
		_T("��"),
		_T("�ȼ�"),
		_T("����"),
		_T("����"),
		_T("����"),
		_T("Ŀ��"),
		_T("����"),
		_T("��Ǯ"),
		_T("Ԫ��"),
		_T("׬��"),
		_T("����"),
		_T("�ƺ�"),
		_T("����"),
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

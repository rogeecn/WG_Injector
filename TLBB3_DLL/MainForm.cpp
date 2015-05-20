// MainForm.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "TLBB3_DLL.h"
#include "MainForm.h"
#include "afxdialogex.h"


// CMainForm �Ի���

IMPLEMENT_DYNAMIC(CMainForm, CDialogEx)

CMainForm::CMainForm(CWnd* pParent /*=NULL*/)
	: CDialogEx(CMainForm::IDD, pParent)
{
}

CMainForm::~CMainForm()
{
}

void CMainForm::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_TAB_CONTAINER, m_tabContainer);
}


BEGIN_MESSAGE_MAP(CMainForm, CDialogEx)
//	ON_NOTIFY(TCN_SELCHANGE, IDC_TAB_CONTAINER, &CMainForm::OnSelchangeTabContainer)
END_MESSAGE_MAP()


// CMainForm ��Ϣ�������


BOOL CMainForm::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	m_tabContainer.AddPage(_T("��ɫ"),&page_userinfo, IDD_DLG_USER_INFO);
	m_tabContainer.AddPage(_T("����"),&page_mapInfo, IDD_DLG_MAP_INFO);
/*
	CString tabItems[] = {
		_T("��ɫ"),
		_T("����"),
		_T("����"),
		_T("����"),
		_T("��ͼ"),
		_T("�ڿ�"),
		_T("��ҩ"),
		_T("����"),
		_T("ˢ��"),
		_T("����"),
	};
	for each (CString var in tabItems)
	{
		m_tabContainer.InsertItem(m_tabContainer.GetItemCount(),var);
	}

	InitTabContainer();
	*/

	return TRUE;
}


//void CMainForm::OnSelchangeTabContainer(NMHDR *pNMHDR, LRESULT *pResult)
//{
//	*pResult = 0;
//	switch(m_tabContainer.GetCurSel()){
//	case 1:
//		page_userinfo.ShowWindow(SW_HIDE);
//		page_mapInfo.ShowWindow(SW_NORMAL);
//		break;
//	default:
//		page_userinfo.ShowWindow(SW_NORMAL);
//		page_mapInfo.ShowWindow(SW_HIDE);
//	}
//}

/*
void CMainForm::SelectTab(int tabId)
{
	int TabIdList[] = {IDD_DLG_USER_INFO, IDD_DLG_MAP_INFO};
	for each (int item in TabIdList)
	{
		GetDlgItem(item)->ShowWindow(SW_HIDE);
	}
	GetDlgItem(TabIdList[tabId])->ShowWindow(SW_NORMAL);
}


void CMainForm::InitTabContainer(void)
{
	CTabCtrl* tabController = (CTabCtrl*)GetDlgItem(IDC_TAB_CONTAINER);
	page_userinfo.Create(IDD_DLG_USER_INFO, tabController);
	page_userinfo.SetParent(tabController);

	page_mapInfo.Create(IDD_DLG_MAP_INFO, tabController);
	page_mapInfo.SetParent(tabController);

	CRect rect;
	tabController->GetWindowRect(&rect);
	CRect newRect = CRect(CPoint(2,22), CSize(rect.Width()-2*3, rect.Height()-24));

	page_userinfo.MoveWindow(&newRect);
	page_mapInfo.MoveWindow(&newRect);

	page_userinfo.ShowWindow(SW_NORMAL);
}
*/

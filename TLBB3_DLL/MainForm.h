#pragma once
#include "afxcmn.h"


#include "UserInfo.h"
#include "MapInfo.h"
#include "TabSheet.h"
// CMainForm 对话框

class CMainForm : public CDialogEx
{
	DECLARE_DYNAMIC(CMainForm)

public:
	CMainForm(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CMainForm();

// 对话框数据
	enum { IDD = IDD_DLG_MAIN };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CTabSheet m_tabContainer;
	virtual BOOL OnInitDialog();
	CUserInfo page_userinfo;
	CMapInfo page_mapInfo;
//	afx_msg void OnSelchangeTabContainer(NMHDR *pNMHDR, LRESULT *pResult);
protected:
	void SelectTab(int tabId);
	void InitTabContainer(void);
	void InitTabTitle(void);
};

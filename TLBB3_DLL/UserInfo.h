#pragma once
#include "afxcmn.h"


// CUserInfo 对话框

class CUserInfo : public CDialogEx
{
	DECLARE_DYNAMIC(CUserInfo)

public:
	CUserInfo(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CUserInfo();

// 对话框数据
	enum { IDD = IDD_DLG_USER_INFO };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	// 用户信息ctrl	
	CListCtrl m_user_info_list;
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	virtual BOOL OnInitDialog();
	void RefreshUserInfo(void);
	afx_msg void OnDestroy();
};

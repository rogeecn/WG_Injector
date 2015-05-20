#pragma once
#include "afxcmn.h"


// CUserInfo �Ի���

class CUserInfo : public CDialogEx
{
	DECLARE_DYNAMIC(CUserInfo)

public:
	CUserInfo(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CUserInfo();

// �Ի�������
	enum { IDD = IDD_DLG_USER_INFO };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	// �û���Ϣctrl	
	CListCtrl m_user_info_list;
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	virtual BOOL OnInitDialog();
	void RefreshUserInfo(void);
	afx_msg void OnDestroy();
};

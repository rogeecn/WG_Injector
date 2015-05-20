
// TLBB3Dlg.h : 头文件
//

#pragma once
#include "afxwin.h"


// CTLBB3Dlg 对话框
class CTLBB3Dlg : public CDialog
{
// 构造
public:
	CTLBB3Dlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_TLBB3_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedBtnInjectDll();
	afx_msg void OnBnClickedBtnStaticCall();
	afx_msg void OnDestroy();
	CButton m_btn_hook;
	CButton m_btn_unhook;
private:
	BOOL is_hook;
};

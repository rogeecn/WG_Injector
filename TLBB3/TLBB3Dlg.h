
// TLBB3Dlg.h : ͷ�ļ�
//

#pragma once
#include "afxwin.h"


// CTLBB3Dlg �Ի���
class CTLBB3Dlg : public CDialog
{
// ����
public:
	CTLBB3Dlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_TLBB3_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
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

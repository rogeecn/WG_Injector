#pragma once


// CMapInfo �Ի���

class CMapInfo : public CDialogEx
{
	DECLARE_DYNAMIC(CMapInfo)

public:
	CMapInfo(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CMapInfo();

// �Ի�������
	enum { IDD = IDD_DLG_MAP_INFO };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
};

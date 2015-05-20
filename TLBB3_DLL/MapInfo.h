#pragma once


// CMapInfo 对话框

class CMapInfo : public CDialogEx
{
	DECLARE_DYNAMIC(CMapInfo)

public:
	CMapInfo(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CMapInfo();

// 对话框数据
	enum { IDD = IDD_DLG_MAP_INFO };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
};

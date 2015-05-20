// MapInfo.cpp : 实现文件
//

#include "stdafx.h"
#include "TLBB3_DLL.h"
#include "MapInfo.h"
#include "afxdialogex.h"


// CMapInfo 对话框

IMPLEMENT_DYNAMIC(CMapInfo, CDialogEx)

CMapInfo::CMapInfo(CWnd* pParent /*=NULL*/)
	: CDialogEx(CMapInfo::IDD, pParent)
{

}

CMapInfo::~CMapInfo()
{
}

void CMapInfo::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CMapInfo, CDialogEx)
END_MESSAGE_MAP()


// CMapInfo 消息处理程序

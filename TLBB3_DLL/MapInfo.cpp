// MapInfo.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "TLBB3_DLL.h"
#include "MapInfo.h"
#include "afxdialogex.h"


// CMapInfo �Ի���

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


// CMapInfo ��Ϣ�������

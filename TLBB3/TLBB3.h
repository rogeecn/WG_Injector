
// TLBB3.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CTLBB3App:
// �йش����ʵ�֣������ TLBB3.cpp
//

class CTLBB3App : public CWinApp
{
public:
	CTLBB3App();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CTLBB3App theApp;
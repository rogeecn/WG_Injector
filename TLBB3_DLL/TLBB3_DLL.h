// TLBB3_DLL.h : TLBB3_DLL DLL ����ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������

// CTLBB3_DLLApp
// �йش���ʵ�ֵ���Ϣ������� TLBB3_DLL.cpp
//

class CTLBB3_DLLApp : public CWinApp
{
public:
	CTLBB3_DLLApp();

// ��д
public:
	virtual BOOL InitInstance();

	DECLARE_MESSAGE_MAP()
	virtual int ExitInstance();
};

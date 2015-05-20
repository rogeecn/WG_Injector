// TLBB3_DLL.h : TLBB3_DLL DLL 的主头文件
//

#pragma once

#ifndef __AFXWIN_H__
	#error "在包含此文件之前包含“stdafx.h”以生成 PCH 文件"
#endif

#include "resource.h"		// 主符号

// CTLBB3_DLLApp
// 有关此类实现的信息，请参阅 TLBB3_DLL.cpp
//

class CTLBB3_DLLApp : public CWinApp
{
public:
	CTLBB3_DLLApp();

// 重写
public:
	virtual BOOL InitInstance();

	DECLARE_MESSAGE_MAP()
	virtual int ExitInstance();
};

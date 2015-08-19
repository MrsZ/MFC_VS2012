
// 直方图.h : 直方图 应用程序的主头文件
//
#pragma once

#ifndef __AFXWIN_H__
	#error "在包含此文件之前包含“stdafx.h”以生成 PCH 文件"
#endif

#include "resource.h"       // 主符号


// C直方图App:
// 有关此类的实现，请参阅 直方图.cpp
//

class C直方图App : public CWinAppEx
{
public:
	C直方图App();


// 重写
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// 实现
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern C直方图App theApp;

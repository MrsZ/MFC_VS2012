
// 改变图标.h : 改变图标 应用程序的主头文件
//
#pragma once

#ifndef __AFXWIN_H__
	#error "在包含此文件之前包含“stdafx.h”以生成 PCH 文件"
#endif

#include "resource.h"       // 主符号


// C改变图标App:
// 有关此类的实现，请参阅 改变图标.cpp
//

class C改变图标App : public CWinAppEx
{
public:
	C改变图标App();


// 重写
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// 实现
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern C改变图标App theApp;

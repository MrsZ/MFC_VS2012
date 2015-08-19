
// 箭头光标.h : 箭头光标 应用程序的主头文件
//
#pragma once

#ifndef __AFXWIN_H__
	#error "在包含此文件之前包含“stdafx.h”以生成 PCH 文件"
#endif

#include "resource.h"       // 主符号


// C箭头光标App:
// 有关此类的实现，请参阅 箭头光标.cpp
//

class C箭头光标App : public CWinAppEx
{
public:
	C箭头光标App();


// 重写
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// 实现
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern C箭头光标App theApp;

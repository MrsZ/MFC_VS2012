
// 绘制文本.h : 绘制文本 应用程序的主头文件
//
#pragma once

#ifndef __AFXWIN_H__
	#error "在包含此文件之前包含“stdafx.h”以生成 PCH 文件"
#endif

#include "resource.h"       // 主符号


// C绘制文本App:
// 有关此类的实现，请参阅 绘制文本.cpp
//

class C绘制文本App : public CWinAppEx
{
public:
	C绘制文本App();


// 重写
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// 实现
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern C绘制文本App theApp;

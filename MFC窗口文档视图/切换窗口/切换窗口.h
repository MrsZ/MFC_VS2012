
// 切换窗口.h : 切换窗口 应用程序的主头文件
//
#pragma once

#ifndef __AFXWIN_H__
	#error "在包含此文件之前包含“stdafx.h”以生成 PCH 文件"
#endif

#include "resource.h"       // 主符号
#include "切换窗口Doc.h"

// C切换窗口App:
// 有关此类的实现，请参阅 切换窗口.cpp
//

class C切换窗口App : public CWinAppEx
{
public:
	C切换窗口App();
	C切换窗口Doc *m_pDoc;


// 重写
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// 实现
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern C切换窗口App theApp;

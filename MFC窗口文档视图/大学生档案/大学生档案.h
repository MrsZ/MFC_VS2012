
// 大学生档案.h : 大学生档案 应用程序的主头文件
//
#pragma once

#ifndef __AFXWIN_H__
	#error "在包含此文件之前包含“stdafx.h”以生成 PCH 文件"
#endif

#include "resource.h"       // 主符号


// C大学生档案App:
// 有关此类的实现，请参阅 大学生档案.cpp
//

class C大学生档案App : public CWinApp
{
public:
	C大学生档案App();


// 重写
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// 实现
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern C大学生档案App theApp;

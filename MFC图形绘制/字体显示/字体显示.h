
// ������ʾ.h : ������ʾ Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// C������ʾApp:
// �йش����ʵ�֣������ ������ʾ.cpp
//

class C������ʾApp : public CWinAppEx
{
public:
	C������ʾApp();


// ��д
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ʵ��
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern C������ʾApp theApp;


// ��ʾ������ɫ.h : ��ʾ������ɫ Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// C��ʾ������ɫApp:
// �йش����ʵ�֣������ ��ʾ������ɫ.cpp
//

class C��ʾ������ɫApp : public CWinAppEx
{
public:
	C��ʾ������ɫApp();


// ��д
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ʵ��
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern C��ʾ������ɫApp theApp;

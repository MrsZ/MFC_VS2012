
// ��ʾ��ͼ.h : ��ʾ��ͼ Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// C��ʾ��ͼApp:
// �йش����ʵ�֣������ ��ʾ��ͼ.cpp
//

class C��ʾ��ͼApp : public CWinAppEx
{
public:
	C��ʾ��ͼApp();


// ��д
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ʵ��
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern C��ʾ��ͼApp theApp;

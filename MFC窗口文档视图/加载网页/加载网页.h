
// ������ҳ.h : ������ҳ Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// C������ҳApp:
// �йش����ʵ�֣������ ������ҳ.cpp
//

class C������ҳApp : public CWinApp
{
public:
	C������ҳApp();


// ��д
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ʵ��
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern C������ҳApp theApp;

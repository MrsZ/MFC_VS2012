
// ��ʾλͼ.h : ��ʾλͼ Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// C��ʾλͼApp:
// �йش����ʵ�֣������ ��ʾλͼ.cpp
//

class C��ʾλͼApp : public CWinAppEx
{
public:
	C��ʾλͼApp();


// ��д
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ʵ��
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern C��ʾλͼApp theApp;

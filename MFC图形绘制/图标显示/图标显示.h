
// ͼ����ʾ.h : ͼ����ʾ Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// Cͼ����ʾApp:
// �йش����ʵ�֣������ ͼ����ʾ.cpp
//

class Cͼ����ʾApp : public CWinAppEx
{
public:
	Cͼ����ʾApp();


// ��д
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ʵ��
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern Cͼ����ʾApp theApp;


// ѧ����¼.h : ѧ����¼ Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// Cѧ����¼App:
// �йش����ʵ�֣������ ѧ����¼.cpp
//

class Cѧ����¼App : public CWinApp
{
public:
	Cѧ����¼App();


// ��д
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ʵ��
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern Cѧ����¼App theApp;


// �������Ա�.h : �������Ա� Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// C�������Ա�App:
// �йش����ʵ�֣������ �������Ա�.cpp
//

class C�������Ա�App : public CWinApp
{
public:
	C�������Ա�App();


// ��д
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ʵ��
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern C�������Ա�App theApp;

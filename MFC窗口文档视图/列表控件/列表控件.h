
// �б�ؼ�.h : �б�ؼ� Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// C�б�ؼ�App:
// �йش����ʵ�֣������ �б�ؼ�.cpp
//

class C�б�ؼ�App : public CWinApp
{
public:
	C�б�ؼ�App();


// ��д
public:
	virtual BOOL InitInstance();

// ʵ��
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern C�б�ؼ�App theApp;

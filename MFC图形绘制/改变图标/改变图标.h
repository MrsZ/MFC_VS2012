
// �ı�ͼ��.h : �ı�ͼ�� Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// C�ı�ͼ��App:
// �йش����ʵ�֣������ �ı�ͼ��.cpp
//

class C�ı�ͼ��App : public CWinAppEx
{
public:
	C�ı�ͼ��App();


// ��д
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ʵ��
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern C�ı�ͼ��App theApp;

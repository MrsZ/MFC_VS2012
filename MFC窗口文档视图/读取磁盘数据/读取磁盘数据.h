
// ��ȡ��������.h : ��ȡ�������� Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// C��ȡ��������App:
// �йش����ʵ�֣������ ��ȡ��������.cpp
//

class C��ȡ��������App : public CWinAppEx
{
public:
	C��ȡ��������App();


// ��д
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ʵ��
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern C��ȡ��������App theApp;


// �ʻ�ѡ��.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// C�ʻ�ѡ��App:
// �йش����ʵ�֣������ �ʻ�ѡ��.cpp
//

class C�ʻ�ѡ��App : public CWinApp
{
public:
	C�ʻ�ѡ��App();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern C�ʻ�ѡ��App theApp;

// ��ѡ��ť.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// C��ѡ��ťApp:
// �йش����ʵ�֣������ ��ѡ��ť.cpp
//

class C��ѡ��ťApp : public CWinApp
{
public:
	C��ѡ��ťApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern C��ѡ��ťApp theApp;

// ��ת��ť.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// C��ת��ťApp:
// �йش����ʵ�֣������ ��ת��ť.cpp
//

class C��ת��ťApp : public CWinApp
{
public:
	C��ת��ťApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern C��ת��ťApp theApp;
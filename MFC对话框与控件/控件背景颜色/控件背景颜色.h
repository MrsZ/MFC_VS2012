
// �ؼ�������ɫ.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// C�ؼ�������ɫApp:
// �йش����ʵ�֣������ �ؼ�������ɫ.cpp
//

class C�ؼ�������ɫApp : public CWinApp
{
public:
	C�ؼ�������ɫApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern C�ؼ�������ɫApp theApp;

// �ڿؼ��л�ͼ.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// C�ڿؼ��л�ͼApp:
// �йش����ʵ�֣������ �ڿؼ��л�ͼ.cpp
//

class C�ڿؼ��л�ͼApp : public CWinApp
{
public:
	C�ڿؼ��л�ͼApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern C�ڿؼ��л�ͼApp theApp;

// ����Ŀ¼.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// C����Ŀ¼App:
// �йش����ʵ�֣������ ����Ŀ¼.cpp
//

class C����Ŀ¼App : public CWinApp
{
public:
	C����Ŀ¼App();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern C����Ŀ¼App theApp;

// ��ǩ�ؼ�.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// C��ǩ�ؼ�App:
// �йش����ʵ�֣������ ��ǩ�ؼ�.cpp
//

class C��ǩ�ؼ�App : public CWinApp
{
public:
	C��ǩ�ؼ�App();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern C��ǩ�ؼ�App theApp;
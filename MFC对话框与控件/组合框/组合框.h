
// ��Ͽ�.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// C��Ͽ�App:
// �йش����ʵ�֣������ ��Ͽ�.cpp
//

class C��Ͽ�App : public CWinApp
{
public:
	C��Ͽ�App();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern C��Ͽ�App theApp;

// ��ɫ����.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// C��ɫ����App:
// �йش����ʵ�֣������ ��ɫ����.cpp
//

class C��ɫ����App : public CWinApp
{
public:
	C��ɫ����App();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern C��ɫ����App theApp;
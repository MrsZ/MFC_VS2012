
// ����ƽ���ɼ�.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// C����ƽ���ɼ�App:
// �йش����ʵ�֣������ ����ƽ���ɼ�.cpp
//

class C����ƽ���ɼ�App : public CWinApp
{
public:
	C����ƽ���ɼ�App();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern C����ƽ���ɼ�App theApp;

// ӳ��ؼ���Ϣ.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// Cӳ��ؼ���ϢApp:
// �йش����ʵ�֣������ ӳ��ؼ���Ϣ.cpp
//

class Cӳ��ؼ���ϢApp : public CWinApp
{
public:
	Cӳ��ؼ���ϢApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern Cӳ��ؼ���ϢApp theApp;
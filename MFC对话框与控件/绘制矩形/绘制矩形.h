
// ���ƾ���.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// C���ƾ���App:
// �йش����ʵ�֣������ ���ƾ���.cpp
//

class C���ƾ���App : public CWinApp
{
public:
	C���ƾ���App();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern C���ƾ���App theApp;

// ���ؼ�.h : ���ؼ� Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// C���ؼ�App:
// �йش����ʵ�֣������ ���ؼ�.cpp
//

class C���ؼ�App : public CWinApp
{
public:
	C���ؼ�App();


// ��д
public:
	virtual BOOL InitInstance();

// ʵ��
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern C���ؼ�App theApp;

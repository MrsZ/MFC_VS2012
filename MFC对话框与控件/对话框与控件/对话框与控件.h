
// �Ի�����ؼ�.h : �Ի�����ؼ� Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// C�Ի�����ؼ�App:
// �йش����ʵ�֣������ �Ի�����ؼ�.cpp
//

class C�Ի�����ؼ�App : public CWinAppEx
{
public:
	C�Ի�����ؼ�App();


// ��д
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ʵ��
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern C�Ի�����ؼ�App theApp;

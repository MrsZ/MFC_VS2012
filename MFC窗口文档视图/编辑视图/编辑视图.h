
// �༭��ͼ.h : �༭��ͼ Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// C�༭��ͼApp:
// �йش����ʵ�֣������ �༭��ͼ.cpp
//

class C�༭��ͼApp : public CWinApp
{
public:
	C�༭��ͼApp();


// ��д
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ʵ��
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern C�༭��ͼApp theApp;


// һ�㺯����ͼ.h : һ�㺯����ͼ Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// Cһ�㺯����ͼApp:
// �йش����ʵ�֣������ һ�㺯����ͼ.cpp
//

class Cһ�㺯����ͼApp : public CWinAppEx
{
public:
	Cһ�㺯����ͼApp();


// ��д
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ʵ��
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern Cһ�㺯����ͼApp theApp;

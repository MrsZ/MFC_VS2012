
// ��ͷ���.h : ��ͷ��� Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// C��ͷ���App:
// �йش����ʵ�֣������ ��ͷ���.cpp
//

class C��ͷ���App : public CWinAppEx
{
public:
	C��ͷ���App();


// ��д
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ʵ��
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern C��ͷ���App theApp;

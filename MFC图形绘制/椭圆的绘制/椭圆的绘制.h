
// ��Բ�Ļ���.h : ��Բ�Ļ��� Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// C��Բ�Ļ���App:
// �йش����ʵ�֣������ ��Բ�Ļ���.cpp
//

class C��Բ�Ļ���App : public CWinAppEx
{
public:
	C��Բ�Ļ���App();


// ��д
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ʵ��
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern C��Բ�Ļ���App theApp;

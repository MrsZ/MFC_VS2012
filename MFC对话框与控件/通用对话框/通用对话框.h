
// ͨ�öԻ���.h : ͨ�öԻ��� Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// Cͨ�öԻ���App:
// �йش����ʵ�֣������ ͨ�öԻ���.cpp
//

class Cͨ�öԻ���App : public CWinApp
{
public:
	Cͨ�öԻ���App();


// ��д
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ʵ��
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern Cͨ�öԻ���App theApp;

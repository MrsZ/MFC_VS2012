
// ͼ��ֲ��Ŵ�.h : ͼ��ֲ��Ŵ� Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// Cͼ��ֲ��Ŵ�App:
// �йش����ʵ�֣������ ͼ��ֲ��Ŵ�.cpp
//

class Cͼ��ֲ��Ŵ�App : public CWinAppEx
{
public:
	Cͼ��ֲ��Ŵ�App();


// ��д
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ʵ��
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern Cͼ��ֲ��Ŵ�App theApp;


// �л�����.h : �л����� Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������
#include "�л�����Doc.h"

// C�л�����App:
// �йش����ʵ�֣������ �л�����.cpp
//

class C�л�����App : public CWinAppEx
{
public:
	C�л�����App();
	C�л�����Doc *m_pDoc;


// ��д
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ʵ��
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern C�л�����App theApp;

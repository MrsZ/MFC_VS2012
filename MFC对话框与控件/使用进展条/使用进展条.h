
// ʹ�ý�չ��.h : ʹ�ý�չ�� Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// Cʹ�ý�չ��App:
// �йش����ʵ�֣������ ʹ�ý�չ��.cpp
//

class Cʹ�ý�չ��App : public CWinAppEx
{
public:
	Cʹ�ý�չ��App();


// ��д
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ʵ��
	UINT  m_nAppLook;
	BOOL  m_bHiColorIcons;

	virtual void PreLoadState();
	virtual void LoadCustomState();
	virtual void SaveCustomState();

	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern Cʹ�ý�չ��App theApp;

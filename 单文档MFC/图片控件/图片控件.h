
// ͼƬ�ؼ�.h : ͼƬ�ؼ� Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// CͼƬ�ؼ�App:
// �йش����ʵ�֣������ ͼƬ�ؼ�.cpp
//

class CͼƬ�ؼ�App : public CWinAppEx
{
public:
	CͼƬ�ؼ�App();


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

extern CͼƬ�ؼ�App theApp;

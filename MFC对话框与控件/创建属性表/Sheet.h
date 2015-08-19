#pragma once
#include "afxdlgs.h"
#include "Cpage1.h"
#include "Cpage2.h"
class CSheet :
	public CPropertySheet
{
public:
	CSheet(void);
	CSheet(const char[20],CView * view,int);
	~CSheet(void);
	Cpage1 m_page1;
	Cpage2 m_page2;
};


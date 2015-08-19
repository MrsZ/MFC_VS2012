#include "stdafx.h"
#include "Sheet.h"


CSheet::CSheet(void)
{
	AddPage(&m_page1);
	AddPage(&m_page2);
}
CSheet::CSheet(const char a[20],CView * view,int i)
{
	AddPage(&m_page1);
	AddPage(&m_page2);
	CPropertySheet(a,view,i);
}


CSheet::~CSheet(void)
{
}

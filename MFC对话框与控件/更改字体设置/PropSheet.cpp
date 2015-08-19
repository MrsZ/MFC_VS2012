#include "stdafx.h"
#include "PropSheet.h"


CPropSheet::CPropSheet(void)
{
	this->AddPage(&m_pageFont);
	this->AddPage(&m_pageEffect);
	this->AddPage(&m_pageSize);
}
CPropSheet::CPropSheet(LPCTSTR pszCaption,CWnd *pParentWnd,UINT iSelectPage)
{
	this->AddPage(&m_pageFont);
	this->AddPage(&m_pageEffect);
	this->AddPage(&m_pageSize);
	CPropertySheet(pszCaption, pParentWnd,iSelectPage);
}


CPropSheet::~CPropSheet(void)
{
}

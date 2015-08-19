#pragma once
#include "afxdlgs.h"
#include "FontChoose.h"
#include "FontEffect.h"
#include "FontSize.h"

class CPropSheet :
	public CPropertySheet
{
public:
	CPropSheet(void);
	CPropSheet(LPCTSTR pszCaption,CWnd *pParentWnd,UINT iSelectPage);
	~CPropSheet(void);
	CFontChoose m_pageFont;
	CFontEffect m_pageEffect;
	CFontSize m_pageSize;
};


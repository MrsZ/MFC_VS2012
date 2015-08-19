#pragma once
#include "afxdlgs.h"
#include "Cpage1.h"
#include "Cpage2.h"
#include "Cpage3.h"

class CWizardSheet :
	public CPropertySheet
{
public:
	CWizardSheet(void);
	CWizardSheet (const char a[20]);
	~CWizardSheet(void);

	Cpage1 m_page1;
	Cpage2 m_page2;
	Cpage3 m_page3;
};


#include "stdafx.h"
#include "WizardSheet.h"


CWizardSheet::CWizardSheet(void)
{
	AddPage(&m_page1);
	AddPage(&m_page2);
	AddPage(&m_page3);
}
CWizardSheet::CWizardSheet(const char b[20])
{
	AddPage(&m_page1);
	AddPage(&m_page2);
	AddPage(&m_page3);
	
}


CWizardSheet::~CWizardSheet(void)
{
}

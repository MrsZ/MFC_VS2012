#include "stdafx.h"
#include "Line.h"

IMPLEMENT_SERIAL(CLine,CObject,1)
CLine::CLine(void)
{
	m_Start=m_End=0;
}


CLine::~CLine(void)
{
}

CLine::CLine(CPoint Start,CPoint End)
{
	m_Start=Start;
	m_End=End;
}
void CLine::DrawLine(CDC *pDC)
{
	pDC->MoveTo(m_Start);
	pDC->LineTo(m_End);
}
void CLine::Serialize(CArchive &ar)
{
	if(ar.IsStoring())
	{
		ar<<m_Start<<m_End;
	}
	else
		ar>>m_Start>>m_End;
}
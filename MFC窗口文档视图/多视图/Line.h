#pragma once
#include "afx.h"
class CLine :
	public CObject
{
public:
	CLine(void);
	~CLine(void);

	CPoint m_Start;
	CPoint m_End;
	CLine(CPoint Start,CPoint End);
	void Draw(CDC *pDC);
protected :
	virtual void Serialize(CArchive &ar);
	DECLARE_SERIAL(CLine)
};


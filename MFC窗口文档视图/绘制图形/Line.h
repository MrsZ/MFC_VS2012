#pragma once
#include "afx.h"
class CLine :
	public CObject
{
public:
	CLine(void);
	~CLine(void);
	CPoint m_Start;//线段的起点
	CPoint m_End;//线段的终点
	CLine(CPoint Start,CPoint End);
	void DrawLine(CDC *Pdc);//绘制线段

protected:
	virtual void Serialize(CArchive &ar);
	DECLARE_SERIAL(CLine);
};


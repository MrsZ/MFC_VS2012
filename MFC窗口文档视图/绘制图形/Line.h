#pragma once
#include "afx.h"
class CLine :
	public CObject
{
public:
	CLine(void);
	~CLine(void);
	CPoint m_Start;//�߶ε����
	CPoint m_End;//�߶ε��յ�
	CLine(CPoint Start,CPoint End);
	void DrawLine(CDC *Pdc);//�����߶�

protected:
	virtual void Serialize(CArchive &ar);
	DECLARE_SERIAL(CLine);
};


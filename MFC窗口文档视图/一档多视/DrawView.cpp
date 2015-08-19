// DrawView.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "DrawView.h"
#include "һ������Doc.h"

// CDrawView

IMPLEMENT_DYNCREATE(CDrawView, CView)

CDrawView::CDrawView()
{

}

CDrawView::~CDrawView()
{
}

BEGIN_MESSAGE_MAP(CDrawView, CView)
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()


// CDrawView ��ͼ

void CDrawView::OnDraw(CDC* pDC)
{
	CDocument* pDoc = GetDocument();
	// TODO: �ڴ���ӻ��ƴ���
	CRect rc(m_ptDraw.x-5,m_ptDraw.y-5,m_ptDraw.x+5,m_ptDraw.y+5);
	pDC->Rectangle(rc);
}


// CDrawView ���

#ifdef _DEBUG
void CDrawView::AssertValid() const
{
	CView::AssertValid();
}

#ifndef _WIN32_WCE
void CDrawView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}
#endif
#endif //_DEBUG


// CDrawView ��Ϣ�������


void CDrawView::OnInitialUpdate()
{
	//CView::OnInitialUpdate();
	Cһ������Doc *pDoc=(Cһ������Doc *)m_pDocument;
	m_ptDraw=pDoc->m_ptRect;
	
	// TODO: �ڴ����ר�ô����/����û���
}


void CDrawView::OnUpdate(CView* pSender, LPARAM lHint, CObject* pHint)
{
	// TODO: �ڴ����ר�ô����/����û���
	if(lHint==2)
	{
		CPoint *pPoint=(CPoint *)pHint;
		m_ptDraw=*pPoint;
		Invalidate();
	}
}


void CDrawView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	m_ptDraw=point;
	GetDocument()->UpdateAllViews(NULL,1,(CObject*)&m_ptDraw);
	Invalidate();
	CView::OnLButtonDown(nFlags, point);
}

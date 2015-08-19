// DrawView.cpp : 实现文件
//

#include "stdafx.h"
#include "DrawView.h"
#include "一档多视Doc.h"

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


// CDrawView 绘图

void CDrawView::OnDraw(CDC* pDC)
{
	CDocument* pDoc = GetDocument();
	// TODO: 在此添加绘制代码
	CRect rc(m_ptDraw.x-5,m_ptDraw.y-5,m_ptDraw.x+5,m_ptDraw.y+5);
	pDC->Rectangle(rc);
}


// CDrawView 诊断

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


// CDrawView 消息处理程序


void CDrawView::OnInitialUpdate()
{
	//CView::OnInitialUpdate();
	C一档多视Doc *pDoc=(C一档多视Doc *)m_pDocument;
	m_ptDraw=pDoc->m_ptRect;
	
	// TODO: 在此添加专用代码和/或调用基类
}


void CDrawView::OnUpdate(CView* pSender, LPARAM lHint, CObject* pHint)
{
	// TODO: 在此添加专用代码和/或调用基类
	if(lHint==2)
	{
		CPoint *pPoint=(CPoint *)pHint;
		m_ptDraw=*pPoint;
		Invalidate();
	}
}


void CDrawView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	m_ptDraw=point;
	GetDocument()->UpdateAllViews(NULL,1,(CObject*)&m_ptDraw);
	Invalidate();
	CView::OnLButtonDown(nFlags, point);
}

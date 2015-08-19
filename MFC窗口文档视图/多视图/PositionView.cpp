// PositionView.cpp : 实现文件
//

#include "stdafx.h"
#include "多视图.h"
#include "PositionView.h"
#include "多视图Doc.h"
#include "Line.h"

// CPositionView

IMPLEMENT_DYNCREATE(CPositionView, CView)

CPositionView::CPositionView()
{

}

CPositionView::~CPositionView()
{
}

BEGIN_MESSAGE_MAP(CPositionView, CView)
END_MESSAGE_MAP()


// CPositionView 绘图

void CPositionView::OnDraw(CDC* pDC)
{
	//CDocument* pDoc = GetDocument();
	// TODO: 在此添加绘制代码
	C多视图Doc *pDoc=(C多视图Doc *)GetDocument();
	ASSERT_VALID(pDoc);
	CObList *pList=(CObList *)pDoc->GetLineList();
	POSITION pos=pList->GetHeadPosition();
	CString zuobiao;
	int i=1;
	while(pos!=NULL)
	{
		CLine *pLine=(CLine*)(pList->GetNext(pos));
		zuobiao.Format("线段%d的起点和终点分别是:(%d,%d),(%d,%d)",i,pLine->m_Start.x,
			pLine->m_Start.y,pLine->m_End.x,pLine->m_End.y);
		pDC->TextOutA(10,20*i,zuobiao);
		i++;
	}
}


// CPositionView 诊断

#ifdef _DEBUG
void CPositionView::AssertValid() const
{
	CView::AssertValid();
}

#ifndef _WIN32_WCE
void CPositionView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}
#endif
#endif //_DEBUG


// CPositionView 消息处理程序

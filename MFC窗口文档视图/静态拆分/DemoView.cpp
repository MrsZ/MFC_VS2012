// DemoView.cpp : 实现文件
//

#include "stdafx.h"
#include "DemoView.h"


// CDemoView

IMPLEMENT_DYNCREATE(CDemoView, CView)

CDemoView::CDemoView()
{

}

CDemoView::~CDemoView()
{
}

BEGIN_MESSAGE_MAP(CDemoView, CView)
END_MESSAGE_MAP()


// CDemoView 绘图

void CDemoView::OnDraw(CDC* pDC)
{
	CDocument* pDoc = GetDocument();
	
	// TODO: 在此添加绘制代码
}


// CDemoView 诊断

#ifdef _DEBUG
void CDemoView::AssertValid() const
{
	CView::AssertValid();
}

#ifndef _WIN32_WCE
void CDemoView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}
#endif
#endif //_DEBUG


// CDemoView 消息处理程序

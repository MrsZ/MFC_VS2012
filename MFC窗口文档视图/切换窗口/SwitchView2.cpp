// SwitchView2.cpp : 实现文件
//

#include "stdafx.h"
#include "切换窗口.h"
#include "SwitchView2.h"


// CSwitchView2

IMPLEMENT_DYNCREATE(CSwitchView2, CView)

CSwitchView2::CSwitchView2()
{

}

CSwitchView2::~CSwitchView2()
{
}

BEGIN_MESSAGE_MAP(CSwitchView2, CView)
END_MESSAGE_MAP()


// CSwitchView2 绘图

void CSwitchView2::OnDraw(CDC* pDC)
{
	CDocument* pDoc = GetDocument();
	// TODO: 在此添加绘制代码
}


// CSwitchView2 诊断

#ifdef _DEBUG
void CSwitchView2::AssertValid() const
{
	CView::AssertValid();
}

#ifndef _WIN32_WCE
void CSwitchView2::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}
#endif
#endif //_DEBUG


// CSwitchView2 消息处理程序


void CSwitchView2::OnPrint(CDC* pDC, CPrintInfo* pInfo)
{
	// TODO: 在此添加专用代码和/或调用基类
	CPaintDC dc(this);
	dc.TextOutA(0,0,"切换窗口2",10);
	//CView::OnPrint(pDC, pInfo);
}

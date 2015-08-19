// SwitchView1.cpp : 实现文件
//

#include "stdafx.h"
#include "SwitchView1.h"


// CSwitchView1

IMPLEMENT_DYNCREATE(CSwitchView1, CView)

CSwitchView1::CSwitchView1()
{

}

CSwitchView1::~CSwitchView1()
{
}

BEGIN_MESSAGE_MAP(CSwitchView1, CView)
END_MESSAGE_MAP()


// CSwitchView1 绘图

void CSwitchView1::OnDraw(CDC* pDC)
{
	CDocument* pDoc = GetDocument();
	// TODO: 在此添加绘制代码
}


// CSwitchView1 诊断

#ifdef _DEBUG
void CSwitchView1::AssertValid() const
{
	CView::AssertValid();
}

#ifndef _WIN32_WCE
void CSwitchView1::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}
#endif
#endif //_DEBUG


// CSwitchView1 消息处理程序


void CSwitchView1::OnPrint(CDC* pDC, CPrintInfo* pInfo)
{
	// TODO: 在此添加专用代码和/或调用基类
	CPaintDC dc(this);
	dc.TextOutA(0,0,"切换窗口1",10);
	//CView::OnPrint(pDC, pInfo);
}


// 曲线绘制View.cpp : C曲线绘制View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "曲线绘制.h"
#endif

#include "曲线绘制Doc.h"
#include "曲线绘制View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// C曲线绘制View

IMPLEMENT_DYNCREATE(C曲线绘制View, CView)

BEGIN_MESSAGE_MAP(C曲线绘制View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// C曲线绘制View 构造/析构

C曲线绘制View::C曲线绘制View()
{
	// TODO: 在此处添加构造代码

}

C曲线绘制View::~C曲线绘制View()
{
}

BOOL C曲线绘制View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// C曲线绘制View 绘制

void C曲线绘制View::OnDraw(CDC* pDC)
{
	C曲线绘制Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	int data[20]={19,21,32,40,41,39,42,35,33,23,21,20,24,11,9,19,22,32,40,42};
	CRect rc;
	GetClientRect(rc);
	//缩小CRect
	rc.DeflateRect(50,50);
	int gridXnums=10;
	int gridYnums=8;
	int dx=rc.Width()/gridXnums;
	int dy=rc.Height()/gridYnums;
	CRect gridRect(rc.left,rc.top,rc.left+dx*gridXnums,rc.top+dy*gridYnums);
	CPen gridPen(0,0,RGB(0,100,200));
	CPen *oldPen=pDC->SelectObject(&gridPen);
	for(int i=0;i<=gridXnums;i++)
	{
		pDC->MoveTo(gridRect.left+i*dx,gridRect.bottom);
		pDC->LineTo(gridRect.left+i*dx,gridRect.top);
	}
	for(int j=0;j<=gridYnums;j++)
	{
		pDC->MoveTo(gridRect.left,gridRect.top+j*dy);
		pDC->LineTo(gridRect.right,gridRect.top+j*dy);
	}
	pDC->SelectObject(oldPen);
	gridPen.Detach();
	gridPen.CreatePen(0,0,RGB(0,0,200));
	pDC->SelectObject(&gridPen);
	CBrush gridBrush(RGB(255,0,0));
	CBrush *oldBrush=pDC->SelectObject(&gridBrush);
	POINT ptRect[4]={{-3,-3},{-3,3},{3,3},{3,-3}},ptDraw[4];
	int deta;
	POINT pt[256];
	int nCount=20;
	deta=gridRect.Width()/nCount;
	for(int i=0;i<nCount;i++)
	{
		pt[i].x=gridRect.left+i*deta;
		pt[i].y=gridRect.bottom-(int)(data[i]/60.0*gridRect.Height());
		for(int j=0;j<4;j++)
		{
			ptDraw[j].x=ptRect[j].x+pt[i].x;
			ptDraw[j].y=ptRect[j].y+pt[i].y;
		}
		pDC->Polygon(ptDraw,4);
	}
	pDC->Polyline(pt,nCount);
	pDC->SelectObject(oldPen);
	pDC->SelectObject(oldBrush);

	// TODO: 在此处为本机数据添加绘制代码
}


// C曲线绘制View 打印

BOOL C曲线绘制View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void C曲线绘制View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void C曲线绘制View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// C曲线绘制View 诊断

#ifdef _DEBUG
void C曲线绘制View::AssertValid() const
{
	CView::AssertValid();
}

void C曲线绘制View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

C曲线绘制Doc* C曲线绘制View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(C曲线绘制Doc)));
	return (C曲线绘制Doc*)m_pDocument;
}
#endif //_DEBUG


// C曲线绘制View 消息处理程序

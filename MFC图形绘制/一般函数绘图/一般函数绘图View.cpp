
// 一般函数绘图View.cpp : C一般函数绘图View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "一般函数绘图.h"
#endif

#include "一般函数绘图Doc.h"
#include "一般函数绘图View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// C一般函数绘图View

IMPLEMENT_DYNCREATE(C一般函数绘图View, CView)

BEGIN_MESSAGE_MAP(C一般函数绘图View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// C一般函数绘图View 构造/析构

C一般函数绘图View::C一般函数绘图View()
{
	// TODO: 在此处添加构造代码

}

C一般函数绘图View::~C一般函数绘图View()
{
}

BOOL C一般函数绘图View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// C一般函数绘图View 绘制

void C一般函数绘图View::OnDraw(CDC* /*pDC*/)
{
	C一般函数绘图Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// C一般函数绘图View 打印

BOOL C一般函数绘图View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void C一般函数绘图View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void C一般函数绘图View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// C一般函数绘图View 诊断

#ifdef _DEBUG
void C一般函数绘图View::AssertValid() const
{
	CView::AssertValid();
}

void C一般函数绘图View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

C一般函数绘图Doc* C一般函数绘图View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(C一般函数绘图Doc)));
	return (C一般函数绘图Doc*)m_pDocument;
}
#endif //_DEBUG


// C一般函数绘图View 消息处理程序


void C一般函数绘图View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CRect rect(0,0,100,100);
	CDC *pDC=GetDC();
	pDC->Rectangle(rect);
	ReleaseDC(pDC);

	CView::OnLButtonDown(nFlags, point);
}

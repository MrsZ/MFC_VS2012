
// 画直线View.cpp : C画直线View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "画直线.h"
#endif

#include "画直线Doc.h"
#include "画直线View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// C画直线View

IMPLEMENT_DYNCREATE(C画直线View, CView)

BEGIN_MESSAGE_MAP(C画直线View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// C画直线View 构造/析构

C画直线View::C画直线View()
{
	// TODO: 在此处添加构造代码

}

C画直线View::~C画直线View()
{
}

BOOL C画直线View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// C画直线View 绘制

void C画直线View::OnDraw(CDC* /*pDC*/)
{
	C画直线Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// C画直线View 打印

BOOL C画直线View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void C画直线View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void C画直线View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// C画直线View 诊断

#ifdef _DEBUG
void C画直线View::AssertValid() const
{
	CView::AssertValid();
}

void C画直线View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

C画直线Doc* C画直线View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(C画直线Doc)));
	return (C画直线Doc*)m_pDocument;
}
#endif //_DEBUG


// C画直线View 消息处理程序


void C画直线View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CClientDC dc(this);
	CRect rect;
	GetClientRect(&rect);
	dc.MoveTo(rect.left,rect.top);
	dc.LineTo(rect.right,rect.bottom);

	CView::OnLButtonDown(nFlags, point);
}

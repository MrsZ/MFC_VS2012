
// 绘图View.cpp : C绘图View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "绘图.h"
#endif

#include "绘图Doc.h"
#include "绘图View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// C绘图View

IMPLEMENT_DYNCREATE(C绘图View, CView)

BEGIN_MESSAGE_MAP(C绘图View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_PAINT()
END_MESSAGE_MAP()

// C绘图View 构造/析构

C绘图View::C绘图View()
{
	// TODO: 在此处添加构造代码

}

C绘图View::~C绘图View()
{
}

BOOL C绘图View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// C绘图View 绘制

void C绘图View::OnDraw(CDC* /*pDC*/)
{
	C绘图Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// C绘图View 打印

BOOL C绘图View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void C绘图View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void C绘图View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// C绘图View 诊断

#ifdef _DEBUG
void C绘图View::AssertValid() const
{
	CView::AssertValid();
}

void C绘图View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

C绘图Doc* C绘图View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(C绘图Doc)));
	return (C绘图Doc*)m_pDocument;
}
#endif //_DEBUG


// C绘图View 消息处理程序


void C绘图View::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	/*@TG
#3073*/
		// TODO: 在此处添加消息处理程序代码
		// 不为绘图消息调用 CView::OnPaint()
	dc.MoveTo(10,10);
	dc.LineTo(100,100);
	dc.Ellipse(120,120,160,160);
}

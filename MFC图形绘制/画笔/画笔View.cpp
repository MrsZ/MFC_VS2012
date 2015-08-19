
// 画笔View.cpp : C画笔View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "画笔.h"
#endif

#include "画笔Doc.h"
#include "画笔View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// C画笔View

IMPLEMENT_DYNCREATE(C画笔View, CView)

BEGIN_MESSAGE_MAP(C画笔View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_PAINT()
END_MESSAGE_MAP()

// C画笔View 构造/析构

C画笔View::C画笔View()
{
	// TODO: 在此处添加构造代码

}

C画笔View::~C画笔View()
{
}

BOOL C画笔View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// C画笔View 绘制

void C画笔View::OnDraw(CDC* /*pDC*/)
{
	C画笔Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// C画笔View 打印

BOOL C画笔View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void C画笔View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void C画笔View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// C画笔View 诊断

#ifdef _DEBUG
void C画笔View::AssertValid() const
{
	CView::AssertValid();
}

void C画笔View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

C画笔Doc* C画笔View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(C画笔Doc)));
	return (C画笔Doc*)m_pDocument;
}
#endif //_DEBUG


// C画笔View 消息处理程序


void C画笔View::OnPaint()
{
	CPaintDC dc(this); // device context for painting
//	@TG
//#3073
		// TODO: 在此处添加消息处理程序代码
		// 不为绘图消息调用 CView::OnPaint()
	CDC *pDC=GetDC();
	CPen newPen;
	newPen.CreatePen(PS_SOLID,6,RGB(255,0,0));
	CBrush newBrush;
	newBrush.CreateSolidBrush(RGB(0,255,0));
	CPen *poldpen=pDC->SelectObject(&newPen);
	CBrush *poldbrush=pDC->SelectObject(&newBrush);
	pDC->MoveTo(10,10);
	pDC->LineTo(100,100);
	pDC->Rectangle(120,120,200,200);
	pDC->SelectObject(poldpen);
	pDC->SelectObject(poldbrush);
	ReleaseDC(pDC);
}

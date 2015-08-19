
// 使用进展条View.cpp : C使用进展条View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "使用进展条.h"
#endif

#include "使用进展条Doc.h"
#include "使用进展条View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// C使用进展条View

IMPLEMENT_DYNCREATE(C使用进展条View, CView)

BEGIN_MESSAGE_MAP(C使用进展条View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &C使用进展条View::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// C使用进展条View 构造/析构

C使用进展条View::C使用进展条View()
{
	// TODO: 在此处添加构造代码

}

C使用进展条View::~C使用进展条View()
{
}

BOOL C使用进展条View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// C使用进展条View 绘制

void C使用进展条View::OnDraw(CDC* /*pDC*/)
{
	C使用进展条Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// C使用进展条View 打印


void C使用进展条View::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL C使用进展条View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void C使用进展条View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void C使用进展条View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}

void C使用进展条View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void C使用进展条View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// C使用进展条View 诊断

#ifdef _DEBUG
void C使用进展条View::AssertValid() const
{
	CView::AssertValid();
}

void C使用进展条View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

C使用进展条Doc* C使用进展条View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(C使用进展条Doc)));
	return (C使用进展条Doc*)m_pDocument;
}
#endif //_DEBUG


// C使用进展条View 消息处理程序

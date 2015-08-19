
// 滑动条View.cpp : C滑动条View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "滑动条.h"
#endif

#include "滑动条Doc.h"
#include "滑动条View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// C滑动条View

IMPLEMENT_DYNCREATE(C滑动条View, CView)

BEGIN_MESSAGE_MAP(C滑动条View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &C滑动条View::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// C滑动条View 构造/析构

C滑动条View::C滑动条View()
{
	// TODO: 在此处添加构造代码

}

C滑动条View::~C滑动条View()
{
}

BOOL C滑动条View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// C滑动条View 绘制

void C滑动条View::OnDraw(CDC* /*pDC*/)
{
	C滑动条Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// C滑动条View 打印


void C滑动条View::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL C滑动条View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void C滑动条View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void C滑动条View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}

void C滑动条View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void C滑动条View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// C滑动条View 诊断

#ifdef _DEBUG
void C滑动条View::AssertValid() const
{
	CView::AssertValid();
}

void C滑动条View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

C滑动条Doc* C滑动条View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(C滑动条Doc)));
	return (C滑动条Doc*)m_pDocument;
}
#endif //_DEBUG


// C滑动条View 消息处理程序


// 输入成绩View.cpp : C输入成绩View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "输入成绩.h"
#endif

#include "输入成绩Doc.h"
#include "输入成绩View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// C输入成绩View

IMPLEMENT_DYNCREATE(C输入成绩View, CView)

BEGIN_MESSAGE_MAP(C输入成绩View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &C输入成绩View::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// C输入成绩View 构造/析构

C输入成绩View::C输入成绩View()
{
	// TODO: 在此处添加构造代码

}

C输入成绩View::~C输入成绩View()
{
}

BOOL C输入成绩View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// C输入成绩View 绘制

void C输入成绩View::OnDraw(CDC* /*pDC*/)
{
	C输入成绩Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// C输入成绩View 打印


void C输入成绩View::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL C输入成绩View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void C输入成绩View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void C输入成绩View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}

void C输入成绩View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void C输入成绩View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// C输入成绩View 诊断

#ifdef _DEBUG
void C输入成绩View::AssertValid() const
{
	CView::AssertValid();
}

void C输入成绩View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

C输入成绩Doc* C输入成绩View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(C输入成绩Doc)));
	return (C输入成绩Doc*)m_pDocument;
}
#endif //_DEBUG


// C输入成绩View 消息处理程序

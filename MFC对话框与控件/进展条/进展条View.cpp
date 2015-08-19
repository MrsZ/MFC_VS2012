
// 进展条View.cpp : C进展条View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "进展条.h"
#endif

#include "进展条Doc.h"
#include "进展条View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// C进展条View

IMPLEMENT_DYNCREATE(C进展条View, CView)

BEGIN_MESSAGE_MAP(C进展条View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &C进展条View::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_WM_CREATE()
	ON_COMMAND(IDC_START,OnStart)
	ON_WM_TIMER()
END_MESSAGE_MAP()

// C进展条View 构造/析构

C进展条View::C进展条View()
{
	// TODO: 在此处添加构造代码

}

C进展条View::~C进展条View()
{
}

BOOL C进展条View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// C进展条View 绘制

void C进展条View::OnDraw(CDC* /*pDC*/)
{
	C进展条Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// C进展条View 打印


void C进展条View::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL C进展条View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void C进展条View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void C进展条View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}

void C进展条View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void C进展条View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// C进展条View 诊断

#ifdef _DEBUG
void C进展条View::AssertValid() const
{
	CView::AssertValid();
}

void C进展条View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

C进展条Doc* C进展条View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(C进展条Doc)));
	return (C进展条Doc*)m_pDocument;
}
#endif //_DEBUG


// C进展条View 消息处理程序


void C进展条View::CreateProgressBar(void)
{
	m_progress.Create(WS_CHILD|WS_BORDER|WS_VISIBLE,CRect(100,30,400,60),this,IDC_PROGRESS);
	m_progress.SetRange(1,100);
	m_progress.SetStep(10);
	m_progress.SetPos(0);
}


void C进展条View::CreateButton(void)
{
	m_progressBtn.Create("Start",WS_CHILD|WS_BORDER|WS_VISIBLE,CRect(210,70,300,100),this,IDC_START);
}


BOOL C进展条View::Create(LPCTSTR lpszClassName, LPCTSTR lpszWindowName, DWORD dwStyle, const RECT& rect, CWnd* pParentWnd, UINT nID, CCreateContext* pContext)
{
	// TODO: 在此添加专用代码和/或调用基类
	
	return CView::Create(lpszClassName, lpszWindowName, dwStyle, rect, pParentWnd, nID, pContext);
}


BOOL C进展条View::CreateEx(DWORD dwExStyle, LPCTSTR lpszClassName, LPCTSTR lpszWindowName, DWORD dwStyle, const RECT& rect, CWnd* pParentWnd, UINT nID, LPVOID lpParam)
{
	// TODO: 在此添加专用代码和/或调用基类

	return CView::CreateEx(dwExStyle, lpszClassName, lpszWindowName, dwStyle, rect, pParentWnd, nID, lpParam);
}


int C进展条View::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  在此添加您专用的创建代码
	CreateProgressBar();
	CreateButton();

	return 0;
}

void C进展条View::OnStart()
{
	SetTimer(IDC_START,1000,NULL);
}

void C进展条View::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	m_progress.StepIt();
	CView::OnTimer(nIDEvent);
}

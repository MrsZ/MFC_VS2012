
// 箭头光标View.cpp : C箭头光标View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "箭头光标.h"
#endif

#include "箭头光标Doc.h"
#include "箭头光标View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// C箭头光标View

IMPLEMENT_DYNCREATE(C箭头光标View, CView)

BEGIN_MESSAGE_MAP(C箭头光标View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_SETCURSOR()
END_MESSAGE_MAP()

// C箭头光标View 构造/析构

C箭头光标View::C箭头光标View()
{
	// TODO: 在此处添加构造代码

}

C箭头光标View::~C箭头光标View()
{
}

BOOL C箭头光标View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// C箭头光标View 绘制

void C箭头光标View::OnDraw(CDC* /*pDC*/)
{
	C箭头光标Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// C箭头光标View 打印

BOOL C箭头光标View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void C箭头光标View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void C箭头光标View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// C箭头光标View 诊断

#ifdef _DEBUG
void C箭头光标View::AssertValid() const
{
	CView::AssertValid();
}

void C箭头光标View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

C箭头光标Doc* C箭头光标View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(C箭头光标Doc)));
	return (C箭头光标Doc*)m_pDocument;
}
#endif //_DEBUG


// C箭头光标View 消息处理程序


BOOL C箭头光标View::OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值

	HCURSOR m_cursor;
	m_cursor=AfxGetApp()->LoadStandardCursor(IDC_SIZENS);
	SetCursor(m_cursor);
	return true;
	//return CView::OnSetCursor(pWnd, nHitTest, message);
}

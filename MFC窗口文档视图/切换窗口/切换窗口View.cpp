
// 切换窗口View.cpp : C切换窗口View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "切换窗口.h"
#endif

#include "切换窗口Doc.h"
#include "切换窗口View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// C切换窗口View

IMPLEMENT_DYNCREATE(C切换窗口View, CView)

BEGIN_MESSAGE_MAP(C切换窗口View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// C切换窗口View 构造/析构

C切换窗口View::C切换窗口View()
{
	// TODO: 在此处添加构造代码

}

C切换窗口View::~C切换窗口View()
{
}

BOOL C切换窗口View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// C切换窗口View 绘制

void C切换窗口View::OnDraw(CDC* /*pDC*/)
{
	C切换窗口Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// C切换窗口View 打印

BOOL C切换窗口View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void C切换窗口View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void C切换窗口View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// C切换窗口View 诊断

#ifdef _DEBUG
void C切换窗口View::AssertValid() const
{
	CView::AssertValid();
}

void C切换窗口View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

C切换窗口Doc* C切换窗口View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(C切换窗口Doc)));
	return (C切换窗口Doc*)m_pDocument;
}
#endif //_DEBUG


// C切换窗口View 消息处理程序


void C切换窗口View::OnPrint(CDC* pDC, CPrintInfo* pInfo)
{
	// TODO: 在此添加专用代码和/或调用基类
	CPaintDC dc(this);
	dc.TextOutA(0,0,"切换窗口0",10);
	//CView::OnPrint(pDC, pInfo);
}

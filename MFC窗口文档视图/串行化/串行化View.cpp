
// 串行化View.cpp : C串行化View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "串行化.h"
#endif

#include "串行化Doc.h"
#include "串行化View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// C串行化View

IMPLEMENT_DYNCREATE(C串行化View, CView)

BEGIN_MESSAGE_MAP(C串行化View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// C串行化View 构造/析构

C串行化View::C串行化View()
{
	// TODO: 在此处添加构造代码

}

C串行化View::~C串行化View()
{
}

BOOL C串行化View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// C串行化View 绘制

void C串行化View::OnDraw(CDC* /*pDC*/)
{
	C串行化Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// C串行化View 打印

BOOL C串行化View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void C串行化View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void C串行化View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// C串行化View 诊断

#ifdef _DEBUG
void C串行化View::AssertValid() const
{
	CView::AssertValid();
}

void C串行化View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

C串行化Doc* C串行化View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(C串行化Doc)));
	return (C串行化Doc*)m_pDocument;
}
#endif //_DEBUG


// C串行化View 消息处理程序

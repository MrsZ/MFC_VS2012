
// 静态拆分View.cpp : C静态拆分View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "静态拆分.h"
#endif

#include "静态拆分Doc.h"
#include "静态拆分View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// C静态拆分View

IMPLEMENT_DYNCREATE(C静态拆分View, CView)

BEGIN_MESSAGE_MAP(C静态拆分View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// C静态拆分View 构造/析构

C静态拆分View::C静态拆分View()
{
	// TODO: 在此处添加构造代码

}

C静态拆分View::~C静态拆分View()
{
}

BOOL C静态拆分View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// C静态拆分View 绘制

void C静态拆分View::OnDraw(CDC* /*pDC*/)
{
	C静态拆分Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// C静态拆分View 打印

BOOL C静态拆分View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void C静态拆分View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void C静态拆分View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// C静态拆分View 诊断

#ifdef _DEBUG
void C静态拆分View::AssertValid() const
{
	CView::AssertValid();
}

void C静态拆分View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

C静态拆分Doc* C静态拆分View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(C静态拆分Doc)));
	return (C静态拆分Doc*)m_pDocument;
}
#endif //_DEBUG


// C静态拆分View 消息处理程序

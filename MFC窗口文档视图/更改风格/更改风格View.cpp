
// 更改风格View.cpp : C更改风格View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "更改风格.h"
#endif

#include "更改风格Doc.h"
#include "更改风格View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// C更改风格View

IMPLEMENT_DYNCREATE(C更改风格View, CView)

BEGIN_MESSAGE_MAP(C更改风格View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// C更改风格View 构造/析构

C更改风格View::C更改风格View()
{
	// TODO: 在此处添加构造代码

}

C更改风格View::~C更改风格View()
{
}

BOOL C更改风格View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// C更改风格View 绘制

void C更改风格View::OnDraw(CDC* /*pDC*/)
{
	C更改风格Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// C更改风格View 打印

BOOL C更改风格View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void C更改风格View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void C更改风格View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// C更改风格View 诊断

#ifdef _DEBUG
void C更改风格View::AssertValid() const
{
	CView::AssertValid();
}

void C更改风格View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

C更改风格Doc* C更改风格View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(C更改风格Doc)));
	return (C更改风格Doc*)m_pDocument;
}
#endif //_DEBUG


// C更改风格View 消息处理程序

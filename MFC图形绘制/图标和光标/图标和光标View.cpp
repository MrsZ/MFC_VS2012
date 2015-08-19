
// 图标和光标View.cpp : C图标和光标View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "图标和光标.h"
#endif

#include "图标和光标Doc.h"
#include "图标和光标View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// C图标和光标View

IMPLEMENT_DYNCREATE(C图标和光标View, CView)

BEGIN_MESSAGE_MAP(C图标和光标View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// C图标和光标View 构造/析构

C图标和光标View::C图标和光标View()
{
	// TODO: 在此处添加构造代码

}

C图标和光标View::~C图标和光标View()
{
}

BOOL C图标和光标View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// C图标和光标View 绘制

void C图标和光标View::OnDraw(CDC* /*pDC*/)
{
	C图标和光标Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// C图标和光标View 打印

BOOL C图标和光标View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void C图标和光标View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void C图标和光标View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// C图标和光标View 诊断

#ifdef _DEBUG
void C图标和光标View::AssertValid() const
{
	CView::AssertValid();
}

void C图标和光标View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

C图标和光标Doc* C图标和光标View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(C图标和光标Doc)));
	return (C图标和光标Doc*)m_pDocument;
}
#endif //_DEBUG


// C图标和光标View 消息处理程序

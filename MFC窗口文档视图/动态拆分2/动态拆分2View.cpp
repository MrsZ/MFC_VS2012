
// 动态拆分2View.cpp : C动态拆分2View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "动态拆分2.h"
#endif

#include "动态拆分2Doc.h"
#include "动态拆分2View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// C动态拆分2View

IMPLEMENT_DYNCREATE(C动态拆分2View, CView)

BEGIN_MESSAGE_MAP(C动态拆分2View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// C动态拆分2View 构造/析构

C动态拆分2View::C动态拆分2View()
{
	// TODO: 在此处添加构造代码

}

C动态拆分2View::~C动态拆分2View()
{
}

BOOL C动态拆分2View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// C动态拆分2View 绘制

void C动态拆分2View::OnDraw(CDC* /*pDC*/)
{
	C动态拆分2Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// C动态拆分2View 打印

BOOL C动态拆分2View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void C动态拆分2View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void C动态拆分2View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// C动态拆分2View 诊断

#ifdef _DEBUG
void C动态拆分2View::AssertValid() const
{
	CView::AssertValid();
}

void C动态拆分2View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

C动态拆分2Doc* C动态拆分2View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(C动态拆分2Doc)));
	return (C动态拆分2Doc*)m_pDocument;
}
#endif //_DEBUG


// C动态拆分2View 消息处理程序

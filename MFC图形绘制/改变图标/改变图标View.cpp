
// 改变图标View.cpp : C改变图标View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "改变图标.h"
#endif

#include "改变图标Doc.h"
#include "改变图标View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// C改变图标View

IMPLEMENT_DYNCREATE(C改变图标View, CView)

BEGIN_MESSAGE_MAP(C改变图标View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// C改变图标View 构造/析构

C改变图标View::C改变图标View()
{
	// TODO: 在此处添加构造代码

}

C改变图标View::~C改变图标View()
{
}

BOOL C改变图标View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// C改变图标View 绘制

void C改变图标View::OnDraw(CDC* /*pDC*/)
{
	C改变图标Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// C改变图标View 打印

BOOL C改变图标View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void C改变图标View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void C改变图标View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// C改变图标View 诊断

#ifdef _DEBUG
void C改变图标View::AssertValid() const
{
	CView::AssertValid();
}

void C改变图标View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

C改变图标Doc* C改变图标View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(C改变图标Doc)));
	return (C改变图标Doc*)m_pDocument;
}
#endif //_DEBUG


// C改变图标View 消息处理程序

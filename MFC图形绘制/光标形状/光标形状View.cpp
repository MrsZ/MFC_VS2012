
// 光标形状View.cpp : C光标形状View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "光标形状.h"
#endif

#include "光标形状Doc.h"
#include "光标形状View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// C光标形状View

IMPLEMENT_DYNCREATE(C光标形状View, CView)

BEGIN_MESSAGE_MAP(C光标形状View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// C光标形状View 构造/析构

C光标形状View::C光标形状View()
{
	// TODO: 在此处添加构造代码

}

C光标形状View::~C光标形状View()
{
}

BOOL C光标形状View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// C光标形状View 绘制

void C光标形状View::OnDraw(CDC* /*pDC*/)
{
	C光标形状Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// C光标形状View 打印

BOOL C光标形状View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void C光标形状View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void C光标形状View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// C光标形状View 诊断

#ifdef _DEBUG
void C光标形状View::AssertValid() const
{
	CView::AssertValid();
}

void C光标形状View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

C光标形状Doc* C光标形状View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(C光标形状Doc)));
	return (C光标形状Doc*)m_pDocument;
}
#endif //_DEBUG


// C光标形状View 消息处理程序

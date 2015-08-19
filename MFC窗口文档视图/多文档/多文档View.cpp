
// 多文档View.cpp : C多文档View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "多文档.h"
#endif

#include "多文档Doc.h"
#include "多文档View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// C多文档View

IMPLEMENT_DYNCREATE(C多文档View, CView)

BEGIN_MESSAGE_MAP(C多文档View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// C多文档View 构造/析构

C多文档View::C多文档View()
{
	// TODO: 在此处添加构造代码

}

C多文档View::~C多文档View()
{
}

BOOL C多文档View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// C多文档View 绘制

void C多文档View::OnDraw(CDC* /*pDC*/)
{
	C多文档Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// C多文档View 打印

BOOL C多文档View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void C多文档View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void C多文档View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// C多文档View 诊断

#ifdef _DEBUG
void C多文档View::AssertValid() const
{
	CView::AssertValid();
}

void C多文档View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

C多文档Doc* C多文档View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(C多文档Doc)));
	return (C多文档Doc*)m_pDocument;
}
#endif //_DEBUG


// C多文档View 消息处理程序

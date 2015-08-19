
// 对话框与控件View.cpp : C对话框与控件View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "对话框与控件.h"
#endif

#include "对话框与控件Doc.h"
#include "对话框与控件View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// C对话框与控件View

IMPLEMENT_DYNCREATE(C对话框与控件View, CView)

BEGIN_MESSAGE_MAP(C对话框与控件View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// C对话框与控件View 构造/析构

C对话框与控件View::C对话框与控件View()
{
	// TODO: 在此处添加构造代码

}

C对话框与控件View::~C对话框与控件View()
{
}

BOOL C对话框与控件View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// C对话框与控件View 绘制

void C对话框与控件View::OnDraw(CDC* /*pDC*/)
{
	C对话框与控件Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// C对话框与控件View 打印

BOOL C对话框与控件View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void C对话框与控件View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void C对话框与控件View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// C对话框与控件View 诊断

#ifdef _DEBUG
void C对话框与控件View::AssertValid() const
{
	CView::AssertValid();
}

void C对话框与控件View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

C对话框与控件Doc* C对话框与控件View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(C对话框与控件Doc)));
	return (C对话框与控件Doc*)m_pDocument;
}
#endif //_DEBUG


// C对话框与控件View 消息处理程序

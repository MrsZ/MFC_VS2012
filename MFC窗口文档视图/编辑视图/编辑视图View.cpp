
// 编辑视图View.cpp : C编辑视图View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "编辑视图.h"
#endif

#include "编辑视图Doc.h"
#include "编辑视图View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// C编辑视图View

IMPLEMENT_DYNCREATE(C编辑视图View, CEditView)

BEGIN_MESSAGE_MAP(C编辑视图View, CEditView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CEditView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CEditView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CEditView::OnFilePrintPreview)
END_MESSAGE_MAP()

// C编辑视图View 构造/析构

C编辑视图View::C编辑视图View()
{
	// TODO: 在此处添加构造代码

}

C编辑视图View::~C编辑视图View()
{
}

BOOL C编辑视图View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	BOOL bPreCreated = CEditView::PreCreateWindow(cs);
	cs.style &= ~(ES_AUTOHSCROLL|WS_HSCROLL);	// 启用换行

	return bPreCreated;
}


// C编辑视图View 打印

BOOL C编辑视图View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认 CEditView 准备
	return CEditView::OnPreparePrinting(pInfo);
}

void C编辑视图View::OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo)
{
	// 默认 CEditView 开始打印
	CEditView::OnBeginPrinting(pDC, pInfo);
}

void C编辑视图View::OnEndPrinting(CDC* pDC, CPrintInfo* pInfo)
{
	// 默认 CEditView 结束打印
	CEditView::OnEndPrinting(pDC, pInfo);
}


// C编辑视图View 诊断

#ifdef _DEBUG
void C编辑视图View::AssertValid() const
{
	CEditView::AssertValid();
}

void C编辑视图View::Dump(CDumpContext& dc) const
{
	CEditView::Dump(dc);
}

C编辑视图Doc* C编辑视图View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(C编辑视图Doc)));
	return (C编辑视图Doc*)m_pDocument;
}
#endif //_DEBUG


// C编辑视图View 消息处理程序

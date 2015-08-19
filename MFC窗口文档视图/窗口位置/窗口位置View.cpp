
// 窗口位置View.cpp : C窗口位置View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "窗口位置.h"
#endif

#include "窗口位置Doc.h"
#include "窗口位置View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// C窗口位置View

IMPLEMENT_DYNCREATE(C窗口位置View, CView)

BEGIN_MESSAGE_MAP(C窗口位置View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// C窗口位置View 构造/析构

C窗口位置View::C窗口位置View()
{
	// TODO: 在此处添加构造代码

}

C窗口位置View::~C窗口位置View()
{
}

BOOL C窗口位置View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// C窗口位置View 绘制

void C窗口位置View::OnDraw(CDC* /*pDC*/)
{
	C窗口位置Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// C窗口位置View 打印

BOOL C窗口位置View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void C窗口位置View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void C窗口位置View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// C窗口位置View 诊断

#ifdef _DEBUG
void C窗口位置View::AssertValid() const
{
	CView::AssertValid();
}

void C窗口位置View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

C窗口位置Doc* C窗口位置View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(C窗口位置Doc)));
	return (C窗口位置Doc*)m_pDocument;
}
#endif //_DEBUG


// C窗口位置View 消息处理程序

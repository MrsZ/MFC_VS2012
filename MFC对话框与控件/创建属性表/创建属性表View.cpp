
// 创建属性表View.cpp : C创建属性表View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "创建属性表.h"
#endif

#include "创建属性表Doc.h"
#include "创建属性表View.h"
#include "Sheet.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// C创建属性表View

IMPLEMENT_DYNCREATE(C创建属性表View, CView)

BEGIN_MESSAGE_MAP(C创建属性表View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_COMMAND(ID_SHEET, &C创建属性表View::OnSheet)
END_MESSAGE_MAP()

// C创建属性表View 构造/析构

C创建属性表View::C创建属性表View()
{
	// TODO: 在此处添加构造代码

}

C创建属性表View::~C创建属性表View()
{
}

BOOL C创建属性表View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// C创建属性表View 绘制

void C创建属性表View::OnDraw(CDC* /*pDC*/)
{
	C创建属性表Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// C创建属性表View 打印

BOOL C创建属性表View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void C创建属性表View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void C创建属性表View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// C创建属性表View 诊断

#ifdef _DEBUG
void C创建属性表View::AssertValid() const
{
	CView::AssertValid();
}

void C创建属性表View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

C创建属性表Doc* C创建属性表View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(C创建属性表Doc)));
	return (C创建属性表Doc*)m_pDocument;
}
#endif //_DEBUG


// C创建属性表View 消息处理程序


void C创建属性表View::OnSheet()
{
	// TODO: 在此添加命令处理程序代码
	CSheet sheet("PropertySheet",this ,0);
	sheet.m_page2.m_red=0;
	sheet.DoModal();
}

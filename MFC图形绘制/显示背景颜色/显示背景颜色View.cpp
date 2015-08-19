
// 显示背景颜色View.cpp : C显示背景颜色View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "显示背景颜色.h"
#endif

#include "显示背景颜色Doc.h"
#include "显示背景颜色View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

#define RED RGB(255,0,0)
#define GREEN RGB(0,255,0)
#define BLUE RGB(0,0,255)
#define BLACK RGB(0,0,0)

// C显示背景颜色View

IMPLEMENT_DYNCREATE(C显示背景颜色View, CView)

BEGIN_MESSAGE_MAP(C显示背景颜色View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// C显示背景颜色View 构造/析构

C显示背景颜色View::C显示背景颜色View()
{
	// TODO: 在此处添加构造代码

}

C显示背景颜色View::~C显示背景颜色View()
{
}

BOOL C显示背景颜色View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// C显示背景颜色View 绘制

void C显示背景颜色View::OnDraw(CDC* pDC)
{
	C显示背景颜色Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	GetClientRect(r);
	if(r.right>750&&r.right<1000||r.bottom>750&&r.bottom<1000)
		pDC->FillSolidRect(r,RED);
	else if(r.right>500&&r.right<750||r.bottom>500&&r.bottom<750)
		pDC->FillSolidRect(r,GREEN);
	else if(r.right<500||r.bottom<500)
		pDC->FillSolidRect(r,BLUE);
	else
		pDC->FillSolidRect(r,BLACK);
	// TODO: 在此处为本机数据添加绘制代码
}


// C显示背景颜色View 打印

BOOL C显示背景颜色View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void C显示背景颜色View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void C显示背景颜色View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// C显示背景颜色View 诊断

#ifdef _DEBUG
void C显示背景颜色View::AssertValid() const
{
	CView::AssertValid();
}

void C显示背景颜色View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

C显示背景颜色Doc* C显示背景颜色View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(C显示背景颜色Doc)));
	return (C显示背景颜色Doc*)m_pDocument;
}
#endif //_DEBUG


// C显示背景颜色View 消息处理程序

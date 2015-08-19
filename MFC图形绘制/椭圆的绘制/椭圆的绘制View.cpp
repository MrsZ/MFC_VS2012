
// 椭圆的绘制View.cpp : C椭圆的绘制View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "椭圆的绘制.h"
#endif

#include "椭圆的绘制Doc.h"
#include "椭圆的绘制View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// C椭圆的绘制View

IMPLEMENT_DYNCREATE(C椭圆的绘制View, CView)

BEGIN_MESSAGE_MAP(C椭圆的绘制View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// C椭圆的绘制View 构造/析构

C椭圆的绘制View::C椭圆的绘制View()
{
	// TODO: 在此处添加构造代码

}

C椭圆的绘制View::~C椭圆的绘制View()
{
}

BOOL C椭圆的绘制View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// C椭圆的绘制View 绘制

void C椭圆的绘制View::OnDraw(CDC* pDC)
{
	C椭圆的绘制Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
	CRect rectClient;
	GetClientRect(rectClient);
	pDC->SetMapMode(MM_ANISOTROPIC);
	pDC->SetWindowExt(1000,1000);
	pDC->SetViewportExt(rectClient.right,-rectClient.bottom);
	pDC->SetViewportOrg(rectClient.right/2,rectClient.bottom/2);
	pDC->Ellipse(CRect(-500,-500,500,500));
}


// C椭圆的绘制View 打印

BOOL C椭圆的绘制View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void C椭圆的绘制View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void C椭圆的绘制View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// C椭圆的绘制View 诊断

#ifdef _DEBUG
void C椭圆的绘制View::AssertValid() const
{
	CView::AssertValid();
}

void C椭圆的绘制View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

C椭圆的绘制Doc* C椭圆的绘制View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(C椭圆的绘制Doc)));
	return (C椭圆的绘制Doc*)m_pDocument;
}
#endif //_DEBUG


// C椭圆的绘制View 消息处理程序

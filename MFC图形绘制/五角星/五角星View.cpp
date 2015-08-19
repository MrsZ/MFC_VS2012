
// 五角星View.cpp : C五角星View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "五角星.h"
#endif

#include "五角星Doc.h"
#include "五角星View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// C五角星View

IMPLEMENT_DYNCREATE(C五角星View, CView)

BEGIN_MESSAGE_MAP(C五角星View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// C五角星View 构造/析构

C五角星View::C五角星View()
{
	// TODO: 在此处添加构造代码

}

C五角星View::~C五角星View()
{
}

BOOL C五角星View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// C五角星View 绘制

void C五角星View::OnDraw(CDC* pDC)
{
	C五角星Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
	POINT pt[5]={{47,10},{30,90},{90,35},{10,30},{75,85}};
	CBrush brush(HS_FDIAGONAL,RGB(255,0,0));
	CBrush *oldbrush=pDC->SelectObject(&brush);
	pDC->SetPolyFillMode(ALTERNATE);
	pDC->Polygon(pt,5);
	for(int i=0;i<5;i++)
		pt[i].x+=80;
	pDC->SetPolyFillMode(WINDING);
	pDC->Polygon(pt,5);
	pDC->SelectObject(oldbrush);
	brush.DeleteObject();
}


// C五角星View 打印

BOOL C五角星View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void C五角星View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void C五角星View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// C五角星View 诊断

#ifdef _DEBUG
void C五角星View::AssertValid() const
{
	CView::AssertValid();
}

void C五角星View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

C五角星Doc* C五角星View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(C五角星Doc)));
	return (C五角星Doc*)m_pDocument;
}
#endif //_DEBUG


// C五角星View 消息处理程序

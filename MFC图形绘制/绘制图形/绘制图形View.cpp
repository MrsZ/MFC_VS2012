
// 绘制图形View.cpp : C绘制图形View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "绘制图形.h"
#endif

#include "绘制图形Doc.h"
#include "绘制图形View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// C绘制图形View

IMPLEMENT_DYNCREATE(C绘制图形View, CView)

BEGIN_MESSAGE_MAP(C绘制图形View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// C绘制图形View 构造/析构

C绘制图形View::C绘制图形View()
{
	// TODO: 在此处添加构造代码

}

C绘制图形View::~C绘制图形View()
{
}

BOOL C绘制图形View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// C绘制图形View 绘制

void C绘制图形View::OnDraw(CDC* pDC)
{
	C绘制图形Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
	CPen pen(PS_SOLID,1,RGB(255,0,0));
	CPen *pOldPen=pDC->SelectObject(&pen);
	
	pDC->TextOutA(20,20,"点");
	pDC->SetPixel(100,40,RGB(255,0,0));
	
	pDC->TextOutA(320,40,"线段");
	pDC->MoveTo(400,40);
	pDC->LineTo(500,40);
	
	pDC->TextOutA(20,170,"折线");
	POINT polyline[4]={{240,240},{80,120},{240,120},{80,240}};
	pDC->Polyline(polyline,4);

	pDC->TextOutA(320,170,"矩形");
	pDC->Rectangle(390,110,600,230);

	pDC->TextOutA(20,320,"椭圆");
	pDC->Ellipse(80,260,280,380);

	pDC->TextOutA(320,320,"多边形");
	POINT polygon[3]={{380,330},{530,260},{500,360}};
	pDC->Polygon(polygon,3);

	pDC->SelectObject(pOldPen);
}


// C绘制图形View 打印

BOOL C绘制图形View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void C绘制图形View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void C绘制图形View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// C绘制图形View 诊断

#ifdef _DEBUG
void C绘制图形View::AssertValid() const
{
	CView::AssertValid();
}

void C绘制图形View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

C绘制图形Doc* C绘制图形View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(C绘制图形Doc)));
	return (C绘制图形Doc*)m_pDocument;
}
#endif //_DEBUG


// C绘制图形View 消息处理程序

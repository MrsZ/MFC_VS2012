
// 工具条绘图View.cpp : C工具条绘图View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "工具条绘图.h"
#endif

#include "工具条绘图Doc.h"
#include "工具条绘图View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

#define RED RGB(255,0,0)
#define GREEN RGB(0,255,0)
#define BLUE RGB(0,0,255)

// C工具条绘图View

IMPLEMENT_DYNCREATE(C工具条绘图View, CView)

BEGIN_MESSAGE_MAP(C工具条绘图View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
	ON_COMMAND_RANGE(ID_BUTTONRED,ID_BUTTON_PENWILD,OnPenChioce)
END_MESSAGE_MAP()

// C工具条绘图View 构造/析构

C工具条绘图View::C工具条绘图View()
	:PenStarte(0)
{
	// TODO: 在此处添加构造代码
	MyPenWild=1;
	PenStyle=PS_SOLID;
}

C工具条绘图View::~C工具条绘图View()
{
}

BOOL C工具条绘图View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// C工具条绘图View 绘制

void C工具条绘图View::OnDraw(CDC* /*pDC*/)
{
	C工具条绘图Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// C工具条绘图View 打印

BOOL C工具条绘图View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void C工具条绘图View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void C工具条绘图View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// C工具条绘图View 诊断

#ifdef _DEBUG
void C工具条绘图View::AssertValid() const
{
	CView::AssertValid();
}

void C工具条绘图View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

C工具条绘图Doc* C工具条绘图View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(C工具条绘图Doc)));
	return (C工具条绘图Doc*)m_pDocument;
}
#endif //_DEBUG


// C工具条绘图View 消息处理程序


void C工具条绘图View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CRect r;
	if(PenStarte==0)
	{
		StartPt.x=StartPt.y;
		StartPt.x=StartPt.y;
	}
	else if(PenStarte==1)
	{
		Rect.left=point.x;
		Rect.top=point.y;
	}
	else
	{
	}
	CView::OnLButtonDown(nFlags, point);
}


void C工具条绘图View::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	if(PenStarte==0)
		StartPt.x=-1;
	else if(PenStarte==1)
	{
		Rect.right=point.x;
		Rect.bottom=point.y;
		CDC *pDC=GetDC();
		CPen RectPen(PS_DASH,1,m_colors);
		pDC->SelectObject(&RectPen);
		pDC->MoveTo(Rect.left,Rect.top);
		pDC->LineTo(Rect.right,Rect.top);
		pDC->LineTo(Rect.right,Rect.bottom);
		pDC->LineTo(Rect.left,Rect.bottom);
		pDC->LineTo(Rect.left,Rect.top);
		ReleaseDC(pDC);
		PenStarte=0;
	}
	CView::OnLButtonUp(nFlags, point);
}


void C工具条绘图View::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CClientDC dc(this);
	dc.SelectObject(&Pen);
	EndPt.x=point.x;
	EndPt.y=point.y;
	if(StartPt.x>=0)
	{
		dc.MoveTo(StartPt.x,StartPt.y);
		dc.LineTo(EndPt);
		StartPt.x=EndPt.x;
		StartPt.y=EndPt.y;
	}
	CView::OnMouseMove(nFlags, point);
}
void C工具条绘图View::OnPenChioce(UINT nID)
{
	switch(nID)
	{
	case ID_BUTTONRED:
		m_colors=RED;break;
	case ID_BUTTON_GREEN:
		m_colors=GREEN;break;
	case ID_BUTTON_BLUE:
		m_colors=BLUE;break;
	case ID_BUTTONDASH:
		PenStyle=PS_DASH;break;
	case ID_BUTTON_SOLID:
		PenStyle=PS_SOLID;break;
	case ID_BUTTONRECT:
		PenStarte=1;break;
	case ID_BUTTONFILL:
		FillMyRect();break;
	case ID_BUTTON_PENCOLORS:
		MyColorsDlg();break;
	case ID_BUTTON_PENWILD:
		WildDlg();break;
	}
	Pen.DeleteObject();
	Pen.CreatePen(PenStyle,MyPenWild,m_colors);
}

void C工具条绘图View::FillMyRect()
{
	CDC *pDC=GetDC();
	CBrush Brush;
	Brush.CreateSolidBrush(m_colors);
	pDC->FillRect(&Rect,&Brush);
	ReleaseDC(pDC);
}
void C工具条绘图View::MyColorsDlg()
{
	CColorDialog dlg;
	if(IDOK==dlg.DoModal())
	{
		m_colors=dlg.GetColor();
		Pen.DeleteObject();
		Pen.CreatePen(PenStyle,1,m_colors);
	}
}
void C工具条绘图View::WildDlg()
{
	CPENWILDDLG Dlg;
	if(IDOK==Dlg.DoModal())
	{
		MyPenWild=Dlg.m_penwild;
	}
}
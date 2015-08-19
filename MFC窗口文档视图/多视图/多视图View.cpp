
// 多视图View.cpp : C多视图View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "多视图.h"
#endif

#include "多视图Doc.h"
#include "多视图View.h"
#include "Line.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// C多视图View

IMPLEMENT_DYNCREATE(C多视图View, CView)

BEGIN_MESSAGE_MAP(C多视图View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
END_MESSAGE_MAP()

// C多视图View 构造/析构

C多视图View::C多视图View()
	: m_ptEnd(0)
{
	// TODO: 在此处添加构造代码
	m_ptStart=0;
}

C多视图View::~C多视图View()
{
}

BOOL C多视图View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// C多视图View 绘制

void C多视图View::OnDraw(CDC* pDC)
{
	C多视图Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	/*if (!pDoc)
		return;*/

	// TODO: 在此处为本机数据添加绘制代码
	CObList *pList=(CObList*)pDoc->GetLineList();
	POSITION pos=pList->GetHeadPosition();
	while(pos!=NULL)
	{
		CLine *pLine=(CLine *)(pList->GetNext(pos));
		pLine->Draw(pDC);
	}
}


// C多视图View 打印

BOOL C多视图View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void C多视图View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void C多视图View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// C多视图View 诊断

#ifdef _DEBUG
void C多视图View::AssertValid() const
{
	CView::AssertValid();
}

void C多视图View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

C多视图Doc* C多视图View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(C多视图Doc)));
	return (C多视图Doc*)m_pDocument;
}
#endif //_DEBUG


// C多视图View 消息处理程序


void C多视图View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	SetCapture();
	m_ptStart=m_ptEnd=point;
	CView::OnLButtonDown(nFlags, point);
}


void C多视图View::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	if(GetCapture()!=this)return;
	CClientDC dc(this);
	m_ptEnd=point;
	dc.MoveTo(m_ptStart);
	dc.LineTo(m_ptEnd);
	if(m_ptStart!=m_ptEnd)
	{
		CLine *pLine=new CLine(m_ptStart,m_ptEnd);
		C多视图Doc* pDoc = GetDocument();
		CObList *pList=(CObList*)pDoc->GetLineList();
		pList->AddTail(pLine);
		pDoc->UpdateAllViews(this,NULL,NULL);
		pDoc->SetModifiedFlag(TRUE);
	}
	ReleaseCapture();
	CView::OnLButtonUp(nFlags, point);
}


void C多视图View::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	if(GetCapture()!=this)
		return;
	CClientDC dc(this);
	CPen newPen(1,1,RGB(0,0,255));
	CPen *oldPen=dc.SelectObject(&newPen);
	int nOldMode=dc.SetROP2(R2_NOTXORPEN);
	dc.MoveTo(m_ptStart);
	dc.LineTo(m_ptEnd);
	m_ptEnd=point;
	dc.MoveTo(m_ptStart);
	dc.LineTo(m_ptEnd);
	dc.SelectObject(oldPen);
	dc.SetROP2(nOldMode);
	CView::OnMouseMove(nFlags, point);
}

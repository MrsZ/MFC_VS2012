
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
#include "Line.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// C绘制图形View

IMPLEMENT_DYNCREATE(C绘制图形View, CScrollView)

BEGIN_MESSAGE_MAP(C绘制图形View, CScrollView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CScrollView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CScrollView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CScrollView::OnFilePrintPreview)
	ON_WM_LBUTTONDOWN()
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONUP()
END_MESSAGE_MAP()

// C绘制图形View 构造/析构

C绘制图形View::C绘制图形View()
{
	// TODO: 在此处添加构造代码
	m_ptEnd=0;
	m_ptStart=0;
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
	/*if (!pDoc)
		return;
*/
	// TODO: 在此处为本机数据添加绘制代码
	CObList *pList=(CObList*)pDoc->GetLineList();
	POSITION pos=pList->GetHeadPosition();
	while(pos!=NULL)
	{
		CLine *pLine=(CLine*)(pList->GetNext(pos));
		pLine->DrawLine(pDC);
	}
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


void C绘制图形View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	SetCapture();//捕捉鼠标
	m_ptStart=m_ptEnd=point;
	ptOrg=GetScrollPosition();//获得当前工作区原点的坐标
	CView::OnLButtonDown(nFlags, point);
}


void C绘制图形View::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	if(GetCapture()!=this)
		return;//若捕捉的鼠标信息的窗口不是当前视图则返回
	CClientDC dc(this);
	CPen newPen(1,1,RGB(0,0,255));
	CPen *oldPen=dc.SelectObject(&newPen);
	int nOldMode=dc.SetROP2(R2_NOTXORPEN);//设置绘图模式,擦掉刚才画的线段
	dc.MoveTo(m_ptStart);
	dc.LineTo(m_ptEnd);
	m_ptEnd=point;
	dc.MoveTo(m_ptStart);
	dc.LineTo(m_ptEnd);
	dc.SelectObject(oldPen);//恢复原先的画笔
	dc.SetROP2(nOldMode);//恢复原先的绘图模式
	CView::OnMouseMove(nFlags, point);
}


void C绘制图形View::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	if(GetCapture()!=this)return;
	CClientDC dc(this);
	m_ptEnd=point;
	dc.MoveTo(m_ptStart);
	dc.LineTo(m_ptEnd);
	m_ptStart+=ptOrg;
	m_ptEnd+=ptOrg;
	if(m_ptStart!=m_ptEnd)
	{
		CLine *pLine=new CLine(m_ptStart,m_ptEnd);
		C绘制图形Doc *pDoc=GetDocument();//获取与视图类相关联的文档
		CObList *pList=(CObList*)pDoc->GetLineList();//获取线段的链表
		pList->AddTail(pLine);//将新的线段假如到链表
		pDoc->UpdateAllViews(this,NULL,NULL);//更新视图
		pDoc->SetModifiedFlag(true);//设置文档修改标志
	}
	ReleaseCapture();
	CView::OnLButtonUp(nFlags, point);
}


void C绘制图形View::OnInitialUpdate()
{
	CScrollView::OnInitialUpdate();

	// TODO: 在此添加专用代码和/或调用基类
	CSize Totalsize;
	Totalsize.cx=Totalsize.cy=2000;
	SetScrollSizes(MM_TEXT,Totalsize);
}

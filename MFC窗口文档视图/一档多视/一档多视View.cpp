
// 一档多视View.cpp : C一档多视View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "一档多视.h"
#endif

#include "一档多视Doc.h"
#include "一档多视View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// C一档多视View

IMPLEMENT_DYNCREATE(C一档多视View, CFormView)

BEGIN_MESSAGE_MAP(C一档多视View, CFormView)
	ON_EN_CHANGE(IDC_EDIT1, &C一档多视View::OnChangeEdit)
END_MESSAGE_MAP()

// C一档多视View 构造/析构

C一档多视View::C一档多视View()
	: CFormView(C一档多视View::IDD)
	, m_CoorX(0)
	, m_CoorY(0)
{
	// TODO: 在此处添加构造代码
	m_bEditOK=false;
}

C一档多视View::~C一档多视View()
{
}

void C一档多视View::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_CoorX);
	DDX_Text(pDX, IDC_EDIT2, m_CoorY);
	DDX_Control(pDX, IDC_SPIN1, m_SpinX);
	DDX_Control(pDX, IDC_SPIN2, m_SpinY);
}

BOOL C一档多视View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CFormView::PreCreateWindow(cs);
}

void C一档多视View::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	ResizeParentToFit();
	C一档多视Doc *pDoc=(C一档多视Doc*)GetDocument();
	m_CoorX=pDoc->m_ptRect.x;
	m_CoorY=pDoc->m_ptRect.y;
	m_SpinX.SetRange(0,1024);
	m_SpinY.SetRange(0,768);
	UpdateData(false);
	m_bEditOK=true;
}


// C一档多视View 诊断

#ifdef _DEBUG
void C一档多视View::AssertValid() const
{
	CFormView::AssertValid();
}

void C一档多视View::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

C一档多视Doc* C一档多视View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(C一档多视Doc)));
	return (C一档多视Doc*)m_pDocument;
}
#endif //_DEBUG


// C一档多视View 消息处理程序


void C一档多视View::OnChangeEdit()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CFormView::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	if(!m_bEditOK)return;

	// TODO:  在此添加控件通知处理程序代码
	UpdateData(true);
	C一档多视Doc *pDoc=(C一档多视Doc *)GetDocument();
	pDoc->m_ptRect.x=m_CoorX;
	pDoc->m_ptRect.y=m_CoorY;
	CPoint pt(m_CoorX,m_CoorY);
	GetDocument()->UpdateAllViews(NULL,2,(CObject *)&pt);
}


void C一档多视View::OnUpdate(CView* pSender, LPARAM lHint, CObject* pHint)
{
	// TODO: 在此添加专用代码和/或调用基类
	if(lHint==1)
	{
		CPoint *pPoint =(CPoint *)pHint;
		m_CoorX=pPoint->x;
		m_CoorY=pPoint->y;
		UpdateData(false);
		C一档多视Doc *pDoc=(C一档多视Doc *)GetDocument();
		pDoc->m_ptRect=*pPoint;
	}
}
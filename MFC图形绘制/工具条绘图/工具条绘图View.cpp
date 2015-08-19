
// ��������ͼView.cpp : C��������ͼView ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "��������ͼ.h"
#endif

#include "��������ͼDoc.h"
#include "��������ͼView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

#define RED RGB(255,0,0)
#define GREEN RGB(0,255,0)
#define BLUE RGB(0,0,255)

// C��������ͼView

IMPLEMENT_DYNCREATE(C��������ͼView, CView)

BEGIN_MESSAGE_MAP(C��������ͼView, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
	ON_COMMAND_RANGE(ID_BUTTONRED,ID_BUTTON_PENWILD,OnPenChioce)
END_MESSAGE_MAP()

// C��������ͼView ����/����

C��������ͼView::C��������ͼView()
	:PenStarte(0)
{
	// TODO: �ڴ˴���ӹ������
	MyPenWild=1;
	PenStyle=PS_SOLID;
}

C��������ͼView::~C��������ͼView()
{
}

BOOL C��������ͼView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// C��������ͼView ����

void C��������ͼView::OnDraw(CDC* /*pDC*/)
{
	C��������ͼDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// C��������ͼView ��ӡ

BOOL C��������ͼView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void C��������ͼView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void C��������ͼView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}


// C��������ͼView ���

#ifdef _DEBUG
void C��������ͼView::AssertValid() const
{
	CView::AssertValid();
}

void C��������ͼView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

C��������ͼDoc* C��������ͼView::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(C��������ͼDoc)));
	return (C��������ͼDoc*)m_pDocument;
}
#endif //_DEBUG


// C��������ͼView ��Ϣ�������


void C��������ͼView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
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


void C��������ͼView::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
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


void C��������ͼView::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
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
void C��������ͼView::OnPenChioce(UINT nID)
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

void C��������ͼView::FillMyRect()
{
	CDC *pDC=GetDC();
	CBrush Brush;
	Brush.CreateSolidBrush(m_colors);
	pDC->FillRect(&Rect,&Brush);
	ReleaseDC(pDC);
}
void C��������ͼView::MyColorsDlg()
{
	CColorDialog dlg;
	if(IDOK==dlg.DoModal())
	{
		m_colors=dlg.GetColor();
		Pen.DeleteObject();
		Pen.CreatePen(PenStyle,1,m_colors);
	}
}
void C��������ͼView::WildDlg()
{
	CPENWILDDLG Dlg;
	if(IDOK==Dlg.DoModal())
	{
		MyPenWild=Dlg.m_penwild;
	}
}
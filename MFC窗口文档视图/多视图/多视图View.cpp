
// ����ͼView.cpp : C����ͼView ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "����ͼ.h"
#endif

#include "����ͼDoc.h"
#include "����ͼView.h"
#include "Line.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// C����ͼView

IMPLEMENT_DYNCREATE(C����ͼView, CView)

BEGIN_MESSAGE_MAP(C����ͼView, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
END_MESSAGE_MAP()

// C����ͼView ����/����

C����ͼView::C����ͼView()
	: m_ptEnd(0)
{
	// TODO: �ڴ˴���ӹ������
	m_ptStart=0;
}

C����ͼView::~C����ͼView()
{
}

BOOL C����ͼView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// C����ͼView ����

void C����ͼView::OnDraw(CDC* pDC)
{
	C����ͼDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	/*if (!pDoc)
		return;*/

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
	CObList *pList=(CObList*)pDoc->GetLineList();
	POSITION pos=pList->GetHeadPosition();
	while(pos!=NULL)
	{
		CLine *pLine=(CLine *)(pList->GetNext(pos));
		pLine->Draw(pDC);
	}
}


// C����ͼView ��ӡ

BOOL C����ͼView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void C����ͼView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void C����ͼView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}


// C����ͼView ���

#ifdef _DEBUG
void C����ͼView::AssertValid() const
{
	CView::AssertValid();
}

void C����ͼView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

C����ͼDoc* C����ͼView::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(C����ͼDoc)));
	return (C����ͼDoc*)m_pDocument;
}
#endif //_DEBUG


// C����ͼView ��Ϣ�������


void C����ͼView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	SetCapture();
	m_ptStart=m_ptEnd=point;
	CView::OnLButtonDown(nFlags, point);
}


void C����ͼView::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	if(GetCapture()!=this)return;
	CClientDC dc(this);
	m_ptEnd=point;
	dc.MoveTo(m_ptStart);
	dc.LineTo(m_ptEnd);
	if(m_ptStart!=m_ptEnd)
	{
		CLine *pLine=new CLine(m_ptStart,m_ptEnd);
		C����ͼDoc* pDoc = GetDocument();
		CObList *pList=(CObList*)pDoc->GetLineList();
		pList->AddTail(pLine);
		pDoc->UpdateAllViews(this,NULL,NULL);
		pDoc->SetModifiedFlag(TRUE);
	}
	ReleaseCapture();
	CView::OnLButtonUp(nFlags, point);
}


void C����ͼView::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
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

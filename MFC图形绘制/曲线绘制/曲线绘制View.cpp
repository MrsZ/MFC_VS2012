
// ���߻���View.cpp : C���߻���View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "���߻���.h"
#endif

#include "���߻���Doc.h"
#include "���߻���View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// C���߻���View

IMPLEMENT_DYNCREATE(C���߻���View, CView)

BEGIN_MESSAGE_MAP(C���߻���View, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// C���߻���View ����/����

C���߻���View::C���߻���View()
{
	// TODO: �ڴ˴���ӹ������

}

C���߻���View::~C���߻���View()
{
}

BOOL C���߻���View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// C���߻���View ����

void C���߻���View::OnDraw(CDC* pDC)
{
	C���߻���Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	int data[20]={19,21,32,40,41,39,42,35,33,23,21,20,24,11,9,19,22,32,40,42};
	CRect rc;
	GetClientRect(rc);
	//��СCRect
	rc.DeflateRect(50,50);
	int gridXnums=10;
	int gridYnums=8;
	int dx=rc.Width()/gridXnums;
	int dy=rc.Height()/gridYnums;
	CRect gridRect(rc.left,rc.top,rc.left+dx*gridXnums,rc.top+dy*gridYnums);
	CPen gridPen(0,0,RGB(0,100,200));
	CPen *oldPen=pDC->SelectObject(&gridPen);
	for(int i=0;i<=gridXnums;i++)
	{
		pDC->MoveTo(gridRect.left+i*dx,gridRect.bottom);
		pDC->LineTo(gridRect.left+i*dx,gridRect.top);
	}
	for(int j=0;j<=gridYnums;j++)
	{
		pDC->MoveTo(gridRect.left,gridRect.top+j*dy);
		pDC->LineTo(gridRect.right,gridRect.top+j*dy);
	}
	pDC->SelectObject(oldPen);
	gridPen.Detach();
	gridPen.CreatePen(0,0,RGB(0,0,200));
	pDC->SelectObject(&gridPen);
	CBrush gridBrush(RGB(255,0,0));
	CBrush *oldBrush=pDC->SelectObject(&gridBrush);
	POINT ptRect[4]={{-3,-3},{-3,3},{3,3},{3,-3}},ptDraw[4];
	int deta;
	POINT pt[256];
	int nCount=20;
	deta=gridRect.Width()/nCount;
	for(int i=0;i<nCount;i++)
	{
		pt[i].x=gridRect.left+i*deta;
		pt[i].y=gridRect.bottom-(int)(data[i]/60.0*gridRect.Height());
		for(int j=0;j<4;j++)
		{
			ptDraw[j].x=ptRect[j].x+pt[i].x;
			ptDraw[j].y=ptRect[j].y+pt[i].y;
		}
		pDC->Polygon(ptDraw,4);
	}
	pDC->Polyline(pt,nCount);
	pDC->SelectObject(oldPen);
	pDC->SelectObject(oldBrush);

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// C���߻���View ��ӡ

BOOL C���߻���View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void C���߻���View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void C���߻���View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}


// C���߻���View ���

#ifdef _DEBUG
void C���߻���View::AssertValid() const
{
	CView::AssertValid();
}

void C���߻���View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

C���߻���Doc* C���߻���View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(C���߻���Doc)));
	return (C���߻���Doc*)m_pDocument;
}
#endif //_DEBUG


// C���߻���View ��Ϣ�������

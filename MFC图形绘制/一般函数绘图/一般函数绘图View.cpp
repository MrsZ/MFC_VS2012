
// һ�㺯����ͼView.cpp : Cһ�㺯����ͼView ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "һ�㺯����ͼ.h"
#endif

#include "һ�㺯����ͼDoc.h"
#include "һ�㺯����ͼView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Cһ�㺯����ͼView

IMPLEMENT_DYNCREATE(Cһ�㺯����ͼView, CView)

BEGIN_MESSAGE_MAP(Cһ�㺯����ͼView, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// Cһ�㺯����ͼView ����/����

Cһ�㺯����ͼView::Cһ�㺯����ͼView()
{
	// TODO: �ڴ˴���ӹ������

}

Cһ�㺯����ͼView::~Cһ�㺯����ͼView()
{
}

BOOL Cһ�㺯����ͼView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// Cһ�㺯����ͼView ����

void Cһ�㺯����ͼView::OnDraw(CDC* /*pDC*/)
{
	Cһ�㺯����ͼDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// Cһ�㺯����ͼView ��ӡ

BOOL Cһ�㺯����ͼView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void Cһ�㺯����ͼView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void Cһ�㺯����ͼView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}


// Cһ�㺯����ͼView ���

#ifdef _DEBUG
void Cһ�㺯����ͼView::AssertValid() const
{
	CView::AssertValid();
}

void Cһ�㺯����ͼView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

Cһ�㺯����ͼDoc* Cһ�㺯����ͼView::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Cһ�㺯����ͼDoc)));
	return (Cһ�㺯����ͼDoc*)m_pDocument;
}
#endif //_DEBUG


// Cһ�㺯����ͼView ��Ϣ�������


void Cһ�㺯����ͼView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	CRect rect(0,0,100,100);
	CDC *pDC=GetDC();
	pDC->Rectangle(rect);
	ReleaseDC(pDC);

	CView::OnLButtonDown(nFlags, point);
}

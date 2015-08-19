
// ����View.cpp : C����View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "����.h"
#endif

#include "����Doc.h"
#include "����View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// C����View

IMPLEMENT_DYNCREATE(C����View, CView)

BEGIN_MESSAGE_MAP(C����View, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_PAINT()
END_MESSAGE_MAP()

// C����View ����/����

C����View::C����View()
{
	// TODO: �ڴ˴���ӹ������

}

C����View::~C����View()
{
}

BOOL C����View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// C����View ����

void C����View::OnDraw(CDC* /*pDC*/)
{
	C����Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// C����View ��ӡ

BOOL C����View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void C����View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void C����View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}


// C����View ���

#ifdef _DEBUG
void C����View::AssertValid() const
{
	CView::AssertValid();
}

void C����View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

C����Doc* C����View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(C����Doc)));
	return (C����Doc*)m_pDocument;
}
#endif //_DEBUG


// C����View ��Ϣ�������


void C����View::OnPaint()
{
	CPaintDC dc(this); // device context for painting
//	@TG
//#3073
		// TODO: �ڴ˴������Ϣ����������
		// ��Ϊ��ͼ��Ϣ���� CView::OnPaint()
	CDC *pDC=GetDC();
	CPen newPen;
	newPen.CreatePen(PS_SOLID,6,RGB(255,0,0));
	CBrush newBrush;
	newBrush.CreateSolidBrush(RGB(0,255,0));
	CPen *poldpen=pDC->SelectObject(&newPen);
	CBrush *poldbrush=pDC->SelectObject(&newBrush);
	pDC->MoveTo(10,10);
	pDC->LineTo(100,100);
	pDC->Rectangle(120,120,200,200);
	pDC->SelectObject(poldpen);
	pDC->SelectObject(poldbrush);
	ReleaseDC(pDC);
}

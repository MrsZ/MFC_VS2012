
// ��ʾ��ͼView.cpp : C��ʾ��ͼView ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "��ʾ��ͼ.h"
#endif

#include "��ʾ��ͼDoc.h"
#include "��ʾ��ͼView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// C��ʾ��ͼView

IMPLEMENT_DYNCREATE(C��ʾ��ͼView, CView)

BEGIN_MESSAGE_MAP(C��ʾ��ͼView, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// C��ʾ��ͼView ����/����

C��ʾ��ͼView::C��ʾ��ͼView()
{
	// TODO: �ڴ˴���ӹ������

}

C��ʾ��ͼView::~C��ʾ��ͼView()
{
}

BOOL C��ʾ��ͼView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// C��ʾ��ͼView ����

void C��ʾ��ͼView::OnDraw(CDC* pDC)
{
	C��ʾ��ͼDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	//ѡ��ǳ��ɫ��ˢ
	pDC->SelectStockObject(LTGRAY_BRUSH);
	CRect rect(10,10,200,70);
	pDC->Rectangle(rect);
	pDC->TextOutA(20,80,"���ǻ����ͼ�γ�����");
	pDC->TextOutA(20,100,"Ŭ��ѧ��Virtual c++");
	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// C��ʾ��ͼView ��ӡ

BOOL C��ʾ��ͼView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void C��ʾ��ͼView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void C��ʾ��ͼView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}


// C��ʾ��ͼView ���

#ifdef _DEBUG
void C��ʾ��ͼView::AssertValid() const
{
	CView::AssertValid();
}

void C��ʾ��ͼView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

C��ʾ��ͼDoc* C��ʾ��ͼView::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(C��ʾ��ͼDoc)));
	return (C��ʾ��ͼDoc*)m_pDocument;
}
#endif //_DEBUG


// C��ʾ��ͼView ��Ϣ�������

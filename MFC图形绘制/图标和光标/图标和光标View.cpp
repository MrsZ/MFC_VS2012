
// ͼ��͹��View.cpp : Cͼ��͹��View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "ͼ��͹��.h"
#endif

#include "ͼ��͹��Doc.h"
#include "ͼ��͹��View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Cͼ��͹��View

IMPLEMENT_DYNCREATE(Cͼ��͹��View, CView)

BEGIN_MESSAGE_MAP(Cͼ��͹��View, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// Cͼ��͹��View ����/����

Cͼ��͹��View::Cͼ��͹��View()
{
	// TODO: �ڴ˴���ӹ������

}

Cͼ��͹��View::~Cͼ��͹��View()
{
}

BOOL Cͼ��͹��View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// Cͼ��͹��View ����

void Cͼ��͹��View::OnDraw(CDC* /*pDC*/)
{
	Cͼ��͹��Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// Cͼ��͹��View ��ӡ

BOOL Cͼ��͹��View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void Cͼ��͹��View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void Cͼ��͹��View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}


// Cͼ��͹��View ���

#ifdef _DEBUG
void Cͼ��͹��View::AssertValid() const
{
	CView::AssertValid();
}

void Cͼ��͹��View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

Cͼ��͹��Doc* Cͼ��͹��View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Cͼ��͹��Doc)));
	return (Cͼ��͹��Doc*)m_pDocument;
}
#endif //_DEBUG


// Cͼ��͹��View ��Ϣ�������

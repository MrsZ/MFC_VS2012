
// ��ʾλͼView.cpp : C��ʾλͼView ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "��ʾλͼ.h"
#endif

#include "��ʾλͼDoc.h"
#include "��ʾλͼView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// C��ʾλͼView

IMPLEMENT_DYNCREATE(C��ʾλͼView, CView)

BEGIN_MESSAGE_MAP(C��ʾλͼView, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// C��ʾλͼView ����/����

C��ʾλͼView::C��ʾλͼView()
{
	// TODO: �ڴ˴���ӹ������

}

C��ʾλͼView::~C��ʾλͼView()
{
}

BOOL C��ʾλͼView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// C��ʾλͼView ����

void C��ʾλͼView::OnDraw(CDC* pDC)
{
	C��ʾλͼDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
	CBitmap m_bmp;
	m_bmp.LoadBitmapW(IDB_BITMAP1);
	BITMAP bm;
	m_bmp.GetObject(sizeof(BITMAP),&bm);
	CDC dcMem;
	dcMem.CreateCompatibleDC(pDC);
	CBitmap *pOldbmp=dcMem.SelectObject(&m_bmp);
	pDC->BitBlt(60,60,bm.bmWidth,bm.bmHeight,&dcMem,0,0,SRCCOPY);
	dcMem.SelectObject(pOldbmp);
}


// C��ʾλͼView ��ӡ

BOOL C��ʾλͼView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void C��ʾλͼView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void C��ʾλͼView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}


// C��ʾλͼView ���

#ifdef _DEBUG
void C��ʾλͼView::AssertValid() const
{
	CView::AssertValid();
}

void C��ʾλͼView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

C��ʾλͼDoc* C��ʾλͼView::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(C��ʾλͼDoc)));
	return (C��ʾλͼDoc*)m_pDocument;
}
#endif //_DEBUG


// C��ʾλͼView ��Ϣ�������


// ��ʾ������ɫView.cpp : C��ʾ������ɫView ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "��ʾ������ɫ.h"
#endif

#include "��ʾ������ɫDoc.h"
#include "��ʾ������ɫView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

#define RED RGB(255,0,0)
#define GREEN RGB(0,255,0)
#define BLUE RGB(0,0,255)
#define BLACK RGB(0,0,0)

// C��ʾ������ɫView

IMPLEMENT_DYNCREATE(C��ʾ������ɫView, CView)

BEGIN_MESSAGE_MAP(C��ʾ������ɫView, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// C��ʾ������ɫView ����/����

C��ʾ������ɫView::C��ʾ������ɫView()
{
	// TODO: �ڴ˴���ӹ������

}

C��ʾ������ɫView::~C��ʾ������ɫView()
{
}

BOOL C��ʾ������ɫView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// C��ʾ������ɫView ����

void C��ʾ������ɫView::OnDraw(CDC* pDC)
{
	C��ʾ������ɫDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	GetClientRect(r);
	if(r.right>750&&r.right<1000||r.bottom>750&&r.bottom<1000)
		pDC->FillSolidRect(r,RED);
	else if(r.right>500&&r.right<750||r.bottom>500&&r.bottom<750)
		pDC->FillSolidRect(r,GREEN);
	else if(r.right<500||r.bottom<500)
		pDC->FillSolidRect(r,BLUE);
	else
		pDC->FillSolidRect(r,BLACK);
	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// C��ʾ������ɫView ��ӡ

BOOL C��ʾ������ɫView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void C��ʾ������ɫView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void C��ʾ������ɫView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}


// C��ʾ������ɫView ���

#ifdef _DEBUG
void C��ʾ������ɫView::AssertValid() const
{
	CView::AssertValid();
}

void C��ʾ������ɫView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

C��ʾ������ɫDoc* C��ʾ������ɫView::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(C��ʾ������ɫDoc)));
	return (C��ʾ������ɫDoc*)m_pDocument;
}
#endif //_DEBUG


// C��ʾ������ɫView ��Ϣ�������


// ���л�View.cpp : C���л�View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "���л�.h"
#endif

#include "���л�Doc.h"
#include "���л�View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// C���л�View

IMPLEMENT_DYNCREATE(C���л�View, CView)

BEGIN_MESSAGE_MAP(C���л�View, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// C���л�View ����/����

C���л�View::C���л�View()
{
	// TODO: �ڴ˴���ӹ������

}

C���л�View::~C���л�View()
{
}

BOOL C���л�View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// C���л�View ����

void C���л�View::OnDraw(CDC* /*pDC*/)
{
	C���л�Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// C���л�View ��ӡ

BOOL C���л�View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void C���л�View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void C���л�View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}


// C���л�View ���

#ifdef _DEBUG
void C���л�View::AssertValid() const
{
	CView::AssertValid();
}

void C���л�View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

C���л�Doc* C���л�View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(C���л�Doc)));
	return (C���л�Doc*)m_pDocument;
}
#endif //_DEBUG


// C���л�View ��Ϣ�������

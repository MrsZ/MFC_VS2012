
// ���ĵ�View.cpp : C���ĵ�View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "���ĵ�.h"
#endif

#include "���ĵ�Doc.h"
#include "���ĵ�View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// C���ĵ�View

IMPLEMENT_DYNCREATE(C���ĵ�View, CView)

BEGIN_MESSAGE_MAP(C���ĵ�View, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// C���ĵ�View ����/����

C���ĵ�View::C���ĵ�View()
{
	// TODO: �ڴ˴���ӹ������

}

C���ĵ�View::~C���ĵ�View()
{
}

BOOL C���ĵ�View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// C���ĵ�View ����

void C���ĵ�View::OnDraw(CDC* /*pDC*/)
{
	C���ĵ�Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// C���ĵ�View ��ӡ

BOOL C���ĵ�View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void C���ĵ�View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void C���ĵ�View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}


// C���ĵ�View ���

#ifdef _DEBUG
void C���ĵ�View::AssertValid() const
{
	CView::AssertValid();
}

void C���ĵ�View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

C���ĵ�Doc* C���ĵ�View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(C���ĵ�Doc)));
	return (C���ĵ�Doc*)m_pDocument;
}
#endif //_DEBUG


// C���ĵ�View ��Ϣ�������

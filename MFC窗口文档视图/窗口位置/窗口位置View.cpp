
// ����λ��View.cpp : C����λ��View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "����λ��.h"
#endif

#include "����λ��Doc.h"
#include "����λ��View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// C����λ��View

IMPLEMENT_DYNCREATE(C����λ��View, CView)

BEGIN_MESSAGE_MAP(C����λ��View, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// C����λ��View ����/����

C����λ��View::C����λ��View()
{
	// TODO: �ڴ˴���ӹ������

}

C����λ��View::~C����λ��View()
{
}

BOOL C����λ��View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// C����λ��View ����

void C����λ��View::OnDraw(CDC* /*pDC*/)
{
	C����λ��Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// C����λ��View ��ӡ

BOOL C����λ��View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void C����λ��View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void C����λ��View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}


// C����λ��View ���

#ifdef _DEBUG
void C����λ��View::AssertValid() const
{
	CView::AssertValid();
}

void C����λ��View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

C����λ��Doc* C����λ��View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(C����λ��Doc)));
	return (C����λ��Doc*)m_pDocument;
}
#endif //_DEBUG


// C����λ��View ��Ϣ�������


// ��̬���2View.cpp : C��̬���2View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "��̬���2.h"
#endif

#include "��̬���2Doc.h"
#include "��̬���2View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// C��̬���2View

IMPLEMENT_DYNCREATE(C��̬���2View, CView)

BEGIN_MESSAGE_MAP(C��̬���2View, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// C��̬���2View ����/����

C��̬���2View::C��̬���2View()
{
	// TODO: �ڴ˴���ӹ������

}

C��̬���2View::~C��̬���2View()
{
}

BOOL C��̬���2View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// C��̬���2View ����

void C��̬���2View::OnDraw(CDC* /*pDC*/)
{
	C��̬���2Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// C��̬���2View ��ӡ

BOOL C��̬���2View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void C��̬���2View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void C��̬���2View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}


// C��̬���2View ���

#ifdef _DEBUG
void C��̬���2View::AssertValid() const
{
	CView::AssertValid();
}

void C��̬���2View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

C��̬���2Doc* C��̬���2View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(C��̬���2Doc)));
	return (C��̬���2Doc*)m_pDocument;
}
#endif //_DEBUG


// C��̬���2View ��Ϣ�������


// ���ķ��View.cpp : C���ķ��View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "���ķ��.h"
#endif

#include "���ķ��Doc.h"
#include "���ķ��View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// C���ķ��View

IMPLEMENT_DYNCREATE(C���ķ��View, CView)

BEGIN_MESSAGE_MAP(C���ķ��View, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// C���ķ��View ����/����

C���ķ��View::C���ķ��View()
{
	// TODO: �ڴ˴���ӹ������

}

C���ķ��View::~C���ķ��View()
{
}

BOOL C���ķ��View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// C���ķ��View ����

void C���ķ��View::OnDraw(CDC* /*pDC*/)
{
	C���ķ��Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// C���ķ��View ��ӡ

BOOL C���ķ��View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void C���ķ��View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void C���ķ��View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}


// C���ķ��View ���

#ifdef _DEBUG
void C���ķ��View::AssertValid() const
{
	CView::AssertValid();
}

void C���ķ��View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

C���ķ��Doc* C���ķ��View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(C���ķ��Doc)));
	return (C���ķ��Doc*)m_pDocument;
}
#endif //_DEBUG


// C���ķ��View ��Ϣ�������

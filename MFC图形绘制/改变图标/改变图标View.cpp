
// �ı�ͼ��View.cpp : C�ı�ͼ��View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "�ı�ͼ��.h"
#endif

#include "�ı�ͼ��Doc.h"
#include "�ı�ͼ��View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// C�ı�ͼ��View

IMPLEMENT_DYNCREATE(C�ı�ͼ��View, CView)

BEGIN_MESSAGE_MAP(C�ı�ͼ��View, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// C�ı�ͼ��View ����/����

C�ı�ͼ��View::C�ı�ͼ��View()
{
	// TODO: �ڴ˴���ӹ������

}

C�ı�ͼ��View::~C�ı�ͼ��View()
{
}

BOOL C�ı�ͼ��View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// C�ı�ͼ��View ����

void C�ı�ͼ��View::OnDraw(CDC* /*pDC*/)
{
	C�ı�ͼ��Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// C�ı�ͼ��View ��ӡ

BOOL C�ı�ͼ��View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void C�ı�ͼ��View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void C�ı�ͼ��View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}


// C�ı�ͼ��View ���

#ifdef _DEBUG
void C�ı�ͼ��View::AssertValid() const
{
	CView::AssertValid();
}

void C�ı�ͼ��View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

C�ı�ͼ��Doc* C�ı�ͼ��View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(C�ı�ͼ��Doc)));
	return (C�ı�ͼ��Doc*)m_pDocument;
}
#endif //_DEBUG


// C�ı�ͼ��View ��Ϣ�������

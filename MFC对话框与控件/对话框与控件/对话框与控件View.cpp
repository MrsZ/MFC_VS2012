
// �Ի�����ؼ�View.cpp : C�Ի�����ؼ�View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "�Ի�����ؼ�.h"
#endif

#include "�Ի�����ؼ�Doc.h"
#include "�Ի�����ؼ�View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// C�Ի�����ؼ�View

IMPLEMENT_DYNCREATE(C�Ի�����ؼ�View, CView)

BEGIN_MESSAGE_MAP(C�Ի�����ؼ�View, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// C�Ի�����ؼ�View ����/����

C�Ի�����ؼ�View::C�Ի�����ؼ�View()
{
	// TODO: �ڴ˴���ӹ������

}

C�Ի�����ؼ�View::~C�Ի�����ؼ�View()
{
}

BOOL C�Ի�����ؼ�View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// C�Ի�����ؼ�View ����

void C�Ի�����ؼ�View::OnDraw(CDC* /*pDC*/)
{
	C�Ի�����ؼ�Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// C�Ի�����ؼ�View ��ӡ

BOOL C�Ի�����ؼ�View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void C�Ի�����ؼ�View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void C�Ի�����ؼ�View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}


// C�Ի�����ؼ�View ���

#ifdef _DEBUG
void C�Ի�����ؼ�View::AssertValid() const
{
	CView::AssertValid();
}

void C�Ի�����ؼ�View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

C�Ի�����ؼ�Doc* C�Ի�����ؼ�View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(C�Ի�����ؼ�Doc)));
	return (C�Ի�����ؼ�Doc*)m_pDocument;
}
#endif //_DEBUG


// C�Ի�����ؼ�View ��Ϣ�������

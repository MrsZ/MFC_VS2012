
// ͨ�öԻ���View.cpp : Cͨ�öԻ���View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "ͨ�öԻ���.h"
#endif

#include "ͨ�öԻ���Doc.h"
#include "ͨ�öԻ���View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Cͨ�öԻ���View

IMPLEMENT_DYNCREATE(Cͨ�öԻ���View, CView)

BEGIN_MESSAGE_MAP(Cͨ�öԻ���View, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// Cͨ�öԻ���View ����/����

Cͨ�öԻ���View::Cͨ�öԻ���View()
{
	// TODO: �ڴ˴���ӹ������

}

Cͨ�öԻ���View::~Cͨ�öԻ���View()
{
}

BOOL Cͨ�öԻ���View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// Cͨ�öԻ���View ����

void Cͨ�öԻ���View::OnDraw(CDC* /*pDC*/)
{
	Cͨ�öԻ���Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// Cͨ�öԻ���View ��ӡ

BOOL Cͨ�öԻ���View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void Cͨ�öԻ���View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void Cͨ�öԻ���View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}


// Cͨ�öԻ���View ���

#ifdef _DEBUG
void Cͨ�öԻ���View::AssertValid() const
{
	CView::AssertValid();
}

void Cͨ�öԻ���View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

Cͨ�öԻ���Doc* Cͨ�öԻ���View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Cͨ�öԻ���Doc)));
	return (Cͨ�öԻ���Doc*)m_pDocument;
}
#endif //_DEBUG


// Cͨ�öԻ���View ��Ϣ�������


// ��Բ�Ļ���View.cpp : C��Բ�Ļ���View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "��Բ�Ļ���.h"
#endif

#include "��Բ�Ļ���Doc.h"
#include "��Բ�Ļ���View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// C��Բ�Ļ���View

IMPLEMENT_DYNCREATE(C��Բ�Ļ���View, CView)

BEGIN_MESSAGE_MAP(C��Բ�Ļ���View, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// C��Բ�Ļ���View ����/����

C��Բ�Ļ���View::C��Բ�Ļ���View()
{
	// TODO: �ڴ˴���ӹ������

}

C��Բ�Ļ���View::~C��Բ�Ļ���View()
{
}

BOOL C��Բ�Ļ���View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// C��Բ�Ļ���View ����

void C��Բ�Ļ���View::OnDraw(CDC* pDC)
{
	C��Բ�Ļ���Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
	CRect rectClient;
	GetClientRect(rectClient);
	pDC->SetMapMode(MM_ANISOTROPIC);
	pDC->SetWindowExt(1000,1000);
	pDC->SetViewportExt(rectClient.right,-rectClient.bottom);
	pDC->SetViewportOrg(rectClient.right/2,rectClient.bottom/2);
	pDC->Ellipse(CRect(-500,-500,500,500));
}


// C��Բ�Ļ���View ��ӡ

BOOL C��Բ�Ļ���View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void C��Բ�Ļ���View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void C��Բ�Ļ���View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}


// C��Բ�Ļ���View ���

#ifdef _DEBUG
void C��Բ�Ļ���View::AssertValid() const
{
	CView::AssertValid();
}

void C��Բ�Ļ���View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

C��Բ�Ļ���Doc* C��Բ�Ļ���View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(C��Բ�Ļ���Doc)));
	return (C��Բ�Ļ���Doc*)m_pDocument;
}
#endif //_DEBUG


// C��Բ�Ļ���View ��Ϣ�������

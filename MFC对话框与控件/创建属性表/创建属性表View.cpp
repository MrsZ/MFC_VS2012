
// �������Ա�View.cpp : C�������Ա�View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "�������Ա�.h"
#endif

#include "�������Ա�Doc.h"
#include "�������Ա�View.h"
#include "Sheet.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// C�������Ա�View

IMPLEMENT_DYNCREATE(C�������Ա�View, CView)

BEGIN_MESSAGE_MAP(C�������Ա�View, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_COMMAND(ID_SHEET, &C�������Ա�View::OnSheet)
END_MESSAGE_MAP()

// C�������Ա�View ����/����

C�������Ա�View::C�������Ա�View()
{
	// TODO: �ڴ˴���ӹ������

}

C�������Ա�View::~C�������Ա�View()
{
}

BOOL C�������Ա�View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// C�������Ա�View ����

void C�������Ա�View::OnDraw(CDC* /*pDC*/)
{
	C�������Ա�Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// C�������Ա�View ��ӡ

BOOL C�������Ա�View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void C�������Ա�View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void C�������Ա�View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}


// C�������Ա�View ���

#ifdef _DEBUG
void C�������Ա�View::AssertValid() const
{
	CView::AssertValid();
}

void C�������Ա�View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

C�������Ա�Doc* C�������Ա�View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(C�������Ա�Doc)));
	return (C�������Ա�Doc*)m_pDocument;
}
#endif //_DEBUG


// C�������Ա�View ��Ϣ�������


void C�������Ա�View::OnSheet()
{
	// TODO: �ڴ���������������
	CSheet sheet("PropertySheet",this ,0);
	sheet.m_page2.m_red=0;
	sheet.DoModal();
}

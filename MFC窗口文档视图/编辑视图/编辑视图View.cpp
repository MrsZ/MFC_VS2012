
// �༭��ͼView.cpp : C�༭��ͼView ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "�༭��ͼ.h"
#endif

#include "�༭��ͼDoc.h"
#include "�༭��ͼView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// C�༭��ͼView

IMPLEMENT_DYNCREATE(C�༭��ͼView, CEditView)

BEGIN_MESSAGE_MAP(C�༭��ͼView, CEditView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CEditView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CEditView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CEditView::OnFilePrintPreview)
END_MESSAGE_MAP()

// C�༭��ͼView ����/����

C�༭��ͼView::C�༭��ͼView()
{
	// TODO: �ڴ˴���ӹ������

}

C�༭��ͼView::~C�༭��ͼView()
{
}

BOOL C�༭��ͼView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	BOOL bPreCreated = CEditView::PreCreateWindow(cs);
	cs.style &= ~(ES_AUTOHSCROLL|WS_HSCROLL);	// ���û���

	return bPreCreated;
}


// C�༭��ͼView ��ӡ

BOOL C�༭��ͼView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ�� CEditView ׼��
	return CEditView::OnPreparePrinting(pInfo);
}

void C�༭��ͼView::OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo)
{
	// Ĭ�� CEditView ��ʼ��ӡ
	CEditView::OnBeginPrinting(pDC, pInfo);
}

void C�༭��ͼView::OnEndPrinting(CDC* pDC, CPrintInfo* pInfo)
{
	// Ĭ�� CEditView ������ӡ
	CEditView::OnEndPrinting(pDC, pInfo);
}


// C�༭��ͼView ���

#ifdef _DEBUG
void C�༭��ͼView::AssertValid() const
{
	CEditView::AssertValid();
}

void C�༭��ͼView::Dump(CDumpContext& dc) const
{
	CEditView::Dump(dc);
}

C�༭��ͼDoc* C�༭��ͼView::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(C�༭��ͼDoc)));
	return (C�༭��ͼDoc*)m_pDocument;
}
#endif //_DEBUG


// C�༭��ͼView ��Ϣ�������

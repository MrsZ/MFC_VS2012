
// �����ı�View.cpp : C�����ı�View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "�����ı�.h"
#endif

#include "�����ı�Doc.h"
#include "�����ı�View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// C�����ı�View

IMPLEMENT_DYNCREATE(C�����ı�View, CView)

BEGIN_MESSAGE_MAP(C�����ı�View, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// C�����ı�View ����/����

C�����ı�View::C�����ı�View()
{
	// TODO: �ڴ˴���ӹ������

}

C�����ı�View::~C�����ı�View()
{
}

BOOL C�����ı�View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// C�����ı�View ����

void C�����ı�View::OnDraw(CDC* pDC)
{
	C�����ı�Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
	CRect rc(10,10,200,140);
	pDC->Rectangle(rc);
	pDC->DrawText("�����ı�����",rc,DT_CENTER|DT_VCENTER|DT_SINGLELINE);
	rc.OffsetRect(200,0);
	pDC->Rectangle(rc);
	int nTab=40;
	pDC->TabbedTextOutA(rc.left,rc.top,"����\tTab\t�ı�\tʾ��",1,&nTab,rc.left);
	nTab=80;
	pDC->TabbedTextOutA(rc.left,rc.top+20,"����\tTab\t�ı�\tʾ��",1,&nTab,rc.left);
	pDC->TabbedTextOutA(rc.left,rc.top+40,"����\tTab\t�ı�\tʾ��",0,NULL,0);
}


// C�����ı�View ��ӡ

BOOL C�����ı�View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void C�����ı�View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void C�����ı�View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}


// C�����ı�View ���

#ifdef _DEBUG
void C�����ı�View::AssertValid() const
{
	CView::AssertValid();
}

void C�����ı�View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

C�����ı�Doc* C�����ı�View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(C�����ı�Doc)));
	return (C�����ı�Doc*)m_pDocument;
}
#endif //_DEBUG


// C�����ı�View ��Ϣ�������

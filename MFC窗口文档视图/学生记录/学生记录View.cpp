
// ѧ����¼View.cpp : Cѧ����¼View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "ѧ����¼.h"
#endif

#include "ѧ����¼Doc.h"
#include "ѧ����¼View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Cѧ����¼View

IMPLEMENT_DYNCREATE(Cѧ����¼View, CView)

BEGIN_MESSAGE_MAP(Cѧ����¼View, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// Cѧ����¼View ����/����

Cѧ����¼View::Cѧ����¼View()
{
	// TODO: �ڴ˴���ӹ������

}

Cѧ����¼View::~Cѧ����¼View()
{
}

BOOL Cѧ����¼View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// Cѧ����¼View ����

void Cѧ����¼View::OnDraw(CDC* pDC)
{
	Cѧ����¼Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	/*if (!pDoc)
		return;*/

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
	int y=0;
	for(int nIndex=0;nIndex<pDoc->GetAllRecNum();nIndex++)
	{
		pDoc->GetStudentAt(nIndex)->Display(y,pDC);
		y+=16;
	}
}


// Cѧ����¼View ��ӡ

BOOL Cѧ����¼View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void Cѧ����¼View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void Cѧ����¼View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}


// Cѧ����¼View ���

#ifdef _DEBUG
void Cѧ����¼View::AssertValid() const
{
	CView::AssertValid();
}

void Cѧ����¼View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

Cѧ����¼Doc* Cѧ����¼View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Cѧ����¼Doc)));
	return (Cѧ����¼Doc*)m_pDocument;
}
#endif //_DEBUG


// Cѧ����¼View ��Ϣ�������

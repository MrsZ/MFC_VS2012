
// ����ͼ��View.cpp : C����ͼ��View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "����ͼ��.h"
#endif

#include "����ͼ��Doc.h"
#include "����ͼ��View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// C����ͼ��View

IMPLEMENT_DYNCREATE(C����ͼ��View, CView)

BEGIN_MESSAGE_MAP(C����ͼ��View, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// C����ͼ��View ����/����

C����ͼ��View::C����ͼ��View()
{
	// TODO: �ڴ˴���ӹ������

}

C����ͼ��View::~C����ͼ��View()
{
}

BOOL C����ͼ��View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// C����ͼ��View ����

void C����ͼ��View::OnDraw(CDC* pDC)
{
	C����ͼ��Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
	CPen pen(PS_SOLID,1,RGB(255,0,0));
	CPen *pOldPen=pDC->SelectObject(&pen);
	
	pDC->TextOutA(20,20,"��");
	pDC->SetPixel(100,40,RGB(255,0,0));
	
	pDC->TextOutA(320,40,"�߶�");
	pDC->MoveTo(400,40);
	pDC->LineTo(500,40);
	
	pDC->TextOutA(20,170,"����");
	POINT polyline[4]={{240,240},{80,120},{240,120},{80,240}};
	pDC->Polyline(polyline,4);

	pDC->TextOutA(320,170,"����");
	pDC->Rectangle(390,110,600,230);

	pDC->TextOutA(20,320,"��Բ");
	pDC->Ellipse(80,260,280,380);

	pDC->TextOutA(320,320,"�����");
	POINT polygon[3]={{380,330},{530,260},{500,360}};
	pDC->Polygon(polygon,3);

	pDC->SelectObject(pOldPen);
}


// C����ͼ��View ��ӡ

BOOL C����ͼ��View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void C����ͼ��View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void C����ͼ��View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}


// C����ͼ��View ���

#ifdef _DEBUG
void C����ͼ��View::AssertValid() const
{
	CView::AssertValid();
}

void C����ͼ��View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

C����ͼ��Doc* C����ͼ��View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(C����ͼ��Doc)));
	return (C����ͼ��Doc*)m_pDocument;
}
#endif //_DEBUG


// C����ͼ��View ��Ϣ�������

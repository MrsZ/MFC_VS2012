
// ������ʾView.cpp : C������ʾView ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "������ʾ.h"
#endif

#include "������ʾDoc.h"
#include "������ʾView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// C������ʾView

IMPLEMENT_DYNCREATE(C������ʾView, CView)

BEGIN_MESSAGE_MAP(C������ʾView, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// C������ʾView ����/����

C������ʾView::C������ʾView()
{
	// TODO: �ڴ˴���ӹ������

}

C������ʾView::~C������ʾView()
{
}

BOOL C������ʾView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// C������ʾView ����

void C������ʾView::OnDraw(CDC* pDC)
{
	C������ʾDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
	pDC->SetBkColor(RGB(240,240,250));
	pDC->SetTextColor(RGB(255,0,0));
	int ny=260;
	int ndl=40;
	for(int i=32;i>=20;i-=4)
	{
		FontOut(pDC,ny,i,ndl);
	}
}


// C������ʾView ��ӡ

BOOL C������ʾView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void C������ʾView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void C������ʾView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}


// C������ʾView ���

#ifdef _DEBUG
void C������ʾView::AssertValid() const
{
	CView::AssertValid();
}

void C������ʾView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

C������ʾDoc* C������ʾView::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(C������ʾDoc)));
	return (C������ʾDoc*)m_pDocument;
}
#endif //_DEBUG


// C������ʾView ��Ϣ�������


void C������ʾView::FontOut(CDC * pDC, int & nHeight, int nPoints, int dline)
{
	TEXTMETRIC textM;
	CFont font;
	CString str;
	font.CreateFontA(-nPoints,0,dline,0,400,FALSE,FALSE,0,ANSI_CHARSET,OUT_DEFAULT_PRECIS,CLIP_DEFAULT_PRECIS,
		DEFAULT_QUALITY,DEFAULT_PITCH|FF_SWISS,"����");
	CFont *poldfont=(CFont *)pDC->SelectObject(&font);
	pDC->GetTextMetrics(&textM);
	str.Format("����%d����������",nPoints);
	pDC->TextOutA(20,nHeight,str);
	nHeight-=textM.tmHeight+textM.tmExternalLeading;
	pDC->SelectObject(poldfont);
}

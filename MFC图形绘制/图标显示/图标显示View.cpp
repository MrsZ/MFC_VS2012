
// ͼ����ʾView.cpp : Cͼ����ʾView ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "ͼ����ʾ.h"
#endif

#include "ͼ����ʾDoc.h"
#include "ͼ����ʾView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Cͼ����ʾView

IMPLEMENT_DYNCREATE(Cͼ����ʾView, CView)

BEGIN_MESSAGE_MAP(Cͼ����ʾView, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// Cͼ����ʾView ����/����

Cͼ����ʾView::Cͼ����ʾView()
{
	// TODO: �ڴ˴���ӹ������

}

Cͼ����ʾView::~Cͼ����ʾView()
{
}

BOOL Cͼ����ʾView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// Cͼ����ʾView ����

void Cͼ����ʾView::OnDraw(CDC* pDC)
{
	Cͼ����ʾDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
	HICON myicon;
	myicon=AfxGetApp()->LoadIconW(IDI_MYICON);
	pDC->DrawIcon(100,100,myicon);
	DestroyIcon(myicon);
}


// Cͼ����ʾView ��ӡ

BOOL Cͼ����ʾView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void Cͼ����ʾView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void Cͼ����ʾView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}


// Cͼ����ʾView ���

#ifdef _DEBUG
void Cͼ����ʾView::AssertValid() const
{
	CView::AssertValid();
}

void Cͼ����ʾView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

Cͼ����ʾDoc* Cͼ����ʾView::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Cͼ����ʾDoc)));
	return (Cͼ����ʾDoc*)m_pDocument;
}
#endif //_DEBUG


// Cͼ����ʾView ��Ϣ�������

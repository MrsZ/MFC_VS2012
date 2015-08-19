
// ��ɫ��View.cpp : C��ɫ��View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "��ɫ��.h"
#endif

#include "��ɫ��Doc.h"
#include "��ɫ��View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// C��ɫ��View

IMPLEMENT_DYNCREATE(C��ɫ��View, CView)

BEGIN_MESSAGE_MAP(C��ɫ��View, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// C��ɫ��View ����/����

C��ɫ��View::C��ɫ��View()
{
	// TODO: �ڴ˴���ӹ������

}

C��ɫ��View::~C��ɫ��View()
{
}

BOOL C��ɫ��View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// C��ɫ��View ����

void C��ɫ��View::OnDraw(CDC* pDC)
{
	C��ɫ��Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
	CPalette m_Palette;
	CBrush brush,*pOldBrush;
	int x,y;
	pDC->SelectPalette(&m_Palette,FALSE);
	pDC->RealizePalette();
	pDC->SelectStockObject(BLACK_PEN);
	for(int i=0;i<256;i++)
	{
		x=(i%16)*16;
		y=(i/16)*16;
		brush.CreateSolidBrush(PALETTEINDEX(i));
		pOldBrush =pDC->SelectObject(&brush);
		pDC->Rectangle(x,y,x+16,y+16);
		pDC->SelectObject(pOldBrush);
		brush.DeleteObject();
	}
}


// C��ɫ��View ��ӡ

BOOL C��ɫ��View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void C��ɫ��View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void C��ɫ��View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}


// C��ɫ��View ���

#ifdef _DEBUG
void C��ɫ��View::AssertValid() const
{
	CView::AssertValid();
}

void C��ɫ��View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

C��ɫ��Doc* C��ɫ��View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(C��ɫ��Doc)));
	return (C��ɫ��Doc*)m_pDocument;
}
#endif //_DEBUG


// C��ɫ��View ��Ϣ�������

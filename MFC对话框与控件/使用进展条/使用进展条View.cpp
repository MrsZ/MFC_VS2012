
// ʹ�ý�չ��View.cpp : Cʹ�ý�չ��View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "ʹ�ý�չ��.h"
#endif

#include "ʹ�ý�չ��Doc.h"
#include "ʹ�ý�չ��View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Cʹ�ý�չ��View

IMPLEMENT_DYNCREATE(Cʹ�ý�չ��View, CView)

BEGIN_MESSAGE_MAP(Cʹ�ý�չ��View, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &Cʹ�ý�չ��View::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// Cʹ�ý�չ��View ����/����

Cʹ�ý�չ��View::Cʹ�ý�չ��View()
{
	// TODO: �ڴ˴���ӹ������

}

Cʹ�ý�չ��View::~Cʹ�ý�չ��View()
{
}

BOOL Cʹ�ý�չ��View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// Cʹ�ý�չ��View ����

void Cʹ�ý�չ��View::OnDraw(CDC* /*pDC*/)
{
	Cʹ�ý�չ��Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// Cʹ�ý�չ��View ��ӡ


void Cʹ�ý�չ��View::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL Cʹ�ý�չ��View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void Cʹ�ý�չ��View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void Cʹ�ý�չ��View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}

void Cʹ�ý�չ��View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void Cʹ�ý�չ��View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// Cʹ�ý�չ��View ���

#ifdef _DEBUG
void Cʹ�ý�չ��View::AssertValid() const
{
	CView::AssertValid();
}

void Cʹ�ý�չ��View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

Cʹ�ý�չ��Doc* Cʹ�ý�չ��View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Cʹ�ý�չ��Doc)));
	return (Cʹ�ý�չ��Doc*)m_pDocument;
}
#endif //_DEBUG


// Cʹ�ý�չ��View ��Ϣ�������

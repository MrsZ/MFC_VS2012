
// ��Create���������ؼ�View.cpp : C��Create���������ؼ�View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "��Create���������ؼ�.h"
#endif

#include "��Create���������ؼ�Doc.h"
#include "��Create���������ؼ�View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// C��Create���������ؼ�View

IMPLEMENT_DYNCREATE(C��Create���������ؼ�View, CView)

BEGIN_MESSAGE_MAP(C��Create���������ؼ�View, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &C��Create���������ؼ�View::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// C��Create���������ؼ�View ����/����

C��Create���������ؼ�View::C��Create���������ؼ�View()
{
	// TODO: �ڴ˴���ӹ������

}

C��Create���������ؼ�View::~C��Create���������ؼ�View()
{
}

BOOL C��Create���������ؼ�View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// C��Create���������ؼ�View ����

void C��Create���������ؼ�View::OnDraw(CDC* /*pDC*/)
{
	C��Create���������ؼ�Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// C��Create���������ؼ�View ��ӡ


void C��Create���������ؼ�View::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL C��Create���������ؼ�View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void C��Create���������ؼ�View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void C��Create���������ؼ�View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}

void C��Create���������ؼ�View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void C��Create���������ؼ�View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// C��Create���������ؼ�View ���

#ifdef _DEBUG
void C��Create���������ؼ�View::AssertValid() const
{
	CView::AssertValid();
}

void C��Create���������ؼ�View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

C��Create���������ؼ�Doc* C��Create���������ؼ�View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(C��Create���������ؼ�Doc)));
	return (C��Create���������ؼ�Doc*)m_pDocument;
}
#endif //_DEBUG


// C��Create���������ؼ�View ��Ϣ�������

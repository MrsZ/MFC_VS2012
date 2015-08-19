
// ����ɼ�View.cpp : C����ɼ�View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "����ɼ�.h"
#endif

#include "����ɼ�Doc.h"
#include "����ɼ�View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// C����ɼ�View

IMPLEMENT_DYNCREATE(C����ɼ�View, CView)

BEGIN_MESSAGE_MAP(C����ɼ�View, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &C����ɼ�View::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// C����ɼ�View ����/����

C����ɼ�View::C����ɼ�View()
{
	// TODO: �ڴ˴���ӹ������

}

C����ɼ�View::~C����ɼ�View()
{
}

BOOL C����ɼ�View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// C����ɼ�View ����

void C����ɼ�View::OnDraw(CDC* /*pDC*/)
{
	C����ɼ�Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// C����ɼ�View ��ӡ


void C����ɼ�View::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL C����ɼ�View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void C����ɼ�View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void C����ɼ�View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}

void C����ɼ�View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void C����ɼ�View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// C����ɼ�View ���

#ifdef _DEBUG
void C����ɼ�View::AssertValid() const
{
	CView::AssertValid();
}

void C����ɼ�View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

C����ɼ�Doc* C����ɼ�View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(C����ɼ�Doc)));
	return (C����ɼ�Doc*)m_pDocument;
}
#endif //_DEBUG


// C����ɼ�View ��Ϣ�������

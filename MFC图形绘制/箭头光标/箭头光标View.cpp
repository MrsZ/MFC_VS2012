
// ��ͷ���View.cpp : C��ͷ���View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "��ͷ���.h"
#endif

#include "��ͷ���Doc.h"
#include "��ͷ���View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// C��ͷ���View

IMPLEMENT_DYNCREATE(C��ͷ���View, CView)

BEGIN_MESSAGE_MAP(C��ͷ���View, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_SETCURSOR()
END_MESSAGE_MAP()

// C��ͷ���View ����/����

C��ͷ���View::C��ͷ���View()
{
	// TODO: �ڴ˴���ӹ������

}

C��ͷ���View::~C��ͷ���View()
{
}

BOOL C��ͷ���View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// C��ͷ���View ����

void C��ͷ���View::OnDraw(CDC* /*pDC*/)
{
	C��ͷ���Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// C��ͷ���View ��ӡ

BOOL C��ͷ���View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void C��ͷ���View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void C��ͷ���View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}


// C��ͷ���View ���

#ifdef _DEBUG
void C��ͷ���View::AssertValid() const
{
	CView::AssertValid();
}

void C��ͷ���View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

C��ͷ���Doc* C��ͷ���View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(C��ͷ���Doc)));
	return (C��ͷ���Doc*)m_pDocument;
}
#endif //_DEBUG


// C��ͷ���View ��Ϣ�������


BOOL C��ͷ���View::OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ

	HCURSOR m_cursor;
	m_cursor=AfxGetApp()->LoadStandardCursor(IDC_SIZENS);
	SetCursor(m_cursor);
	return true;
	//return CView::OnSetCursor(pWnd, nHitTest, message);
}

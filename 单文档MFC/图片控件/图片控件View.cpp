
// ͼƬ�ؼ�View.cpp : CͼƬ�ؼ�View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "ͼƬ�ؼ�.h"
#endif

#include "ͼƬ�ؼ�Doc.h"
#include "ͼƬ�ؼ�View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CͼƬ�ؼ�View

IMPLEMENT_DYNCREATE(CͼƬ�ؼ�View, CView)

BEGIN_MESSAGE_MAP(CͼƬ�ؼ�View, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CͼƬ�ؼ�View::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_COMMAND(ID_DLG, &CͼƬ�ؼ�View::OnDlg)
END_MESSAGE_MAP()

// CͼƬ�ؼ�View ����/����

CͼƬ�ؼ�View::CͼƬ�ؼ�View()
{
	// TODO: �ڴ˴���ӹ������

}

CͼƬ�ؼ�View::~CͼƬ�ؼ�View()
{
}

BOOL CͼƬ�ؼ�View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CͼƬ�ؼ�View ����

void CͼƬ�ؼ�View::OnDraw(CDC* /*pDC*/)
{
	CͼƬ�ؼ�Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// CͼƬ�ؼ�View ��ӡ


void CͼƬ�ؼ�View::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CͼƬ�ؼ�View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void CͼƬ�ؼ�View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void CͼƬ�ؼ�View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}

void CͼƬ�ؼ�View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CͼƬ�ؼ�View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CͼƬ�ؼ�View ���

#ifdef _DEBUG
void CͼƬ�ؼ�View::AssertValid() const
{
	CView::AssertValid();
}

void CͼƬ�ؼ�View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CͼƬ�ؼ�Doc* CͼƬ�ؼ�View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CͼƬ�ؼ�Doc)));
	return (CͼƬ�ؼ�Doc*)m_pDocument;
}
#endif //_DEBUG


// CͼƬ�ؼ�View ��Ϣ�������


void CͼƬ�ؼ�View::OnDlg()
{
	// TODO: �ڴ���������������
	dlg=new CMyDlg(this);
	dlg->Create(IDD_DIALOG1);
	dlg->ShowWindow(SW_RESTORE);
}

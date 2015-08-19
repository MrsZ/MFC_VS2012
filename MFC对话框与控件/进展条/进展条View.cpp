
// ��չ��View.cpp : C��չ��View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "��չ��.h"
#endif

#include "��չ��Doc.h"
#include "��չ��View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// C��չ��View

IMPLEMENT_DYNCREATE(C��չ��View, CView)

BEGIN_MESSAGE_MAP(C��չ��View, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &C��չ��View::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_WM_CREATE()
	ON_COMMAND(IDC_START,OnStart)
	ON_WM_TIMER()
END_MESSAGE_MAP()

// C��չ��View ����/����

C��չ��View::C��չ��View()
{
	// TODO: �ڴ˴���ӹ������

}

C��չ��View::~C��չ��View()
{
}

BOOL C��չ��View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// C��չ��View ����

void C��չ��View::OnDraw(CDC* /*pDC*/)
{
	C��չ��Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// C��չ��View ��ӡ


void C��չ��View::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL C��չ��View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void C��չ��View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void C��չ��View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}

void C��չ��View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void C��չ��View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// C��չ��View ���

#ifdef _DEBUG
void C��չ��View::AssertValid() const
{
	CView::AssertValid();
}

void C��չ��View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

C��չ��Doc* C��չ��View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(C��չ��Doc)));
	return (C��չ��Doc*)m_pDocument;
}
#endif //_DEBUG


// C��չ��View ��Ϣ�������


void C��չ��View::CreateProgressBar(void)
{
	m_progress.Create(WS_CHILD|WS_BORDER|WS_VISIBLE,CRect(100,30,400,60),this,IDC_PROGRESS);
	m_progress.SetRange(1,100);
	m_progress.SetStep(10);
	m_progress.SetPos(0);
}


void C��չ��View::CreateButton(void)
{
	m_progressBtn.Create("Start",WS_CHILD|WS_BORDER|WS_VISIBLE,CRect(210,70,300,100),this,IDC_START);
}


BOOL C��չ��View::Create(LPCTSTR lpszClassName, LPCTSTR lpszWindowName, DWORD dwStyle, const RECT& rect, CWnd* pParentWnd, UINT nID, CCreateContext* pContext)
{
	// TODO: �ڴ����ר�ô����/����û���
	
	return CView::Create(lpszClassName, lpszWindowName, dwStyle, rect, pParentWnd, nID, pContext);
}


BOOL C��չ��View::CreateEx(DWORD dwExStyle, LPCTSTR lpszClassName, LPCTSTR lpszWindowName, DWORD dwStyle, const RECT& rect, CWnd* pParentWnd, UINT nID, LPVOID lpParam)
{
	// TODO: �ڴ����ר�ô����/����û���

	return CView::CreateEx(dwExStyle, lpszClassName, lpszWindowName, dwStyle, rect, pParentWnd, nID, lpParam);
}


int C��չ��View::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  �ڴ������ר�õĴ�������
	CreateProgressBar();
	CreateButton();

	return 0;
}

void C��չ��View::OnStart()
{
	SetTimer(IDC_START,1000,NULL);
}

void C��չ��View::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	m_progress.StepIt();
	CView::OnTimer(nIDEvent);
}

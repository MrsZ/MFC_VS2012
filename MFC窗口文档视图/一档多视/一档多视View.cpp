
// һ������View.cpp : Cһ������View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "һ������.h"
#endif

#include "һ������Doc.h"
#include "һ������View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Cһ������View

IMPLEMENT_DYNCREATE(Cһ������View, CFormView)

BEGIN_MESSAGE_MAP(Cһ������View, CFormView)
	ON_EN_CHANGE(IDC_EDIT1, &Cһ������View::OnChangeEdit)
END_MESSAGE_MAP()

// Cһ������View ����/����

Cһ������View::Cһ������View()
	: CFormView(Cһ������View::IDD)
	, m_CoorX(0)
	, m_CoorY(0)
{
	// TODO: �ڴ˴���ӹ������
	m_bEditOK=false;
}

Cһ������View::~Cһ������View()
{
}

void Cһ������View::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_CoorX);
	DDX_Text(pDX, IDC_EDIT2, m_CoorY);
	DDX_Control(pDX, IDC_SPIN1, m_SpinX);
	DDX_Control(pDX, IDC_SPIN2, m_SpinY);
}

BOOL Cһ������View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CFormView::PreCreateWindow(cs);
}

void Cһ������View::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	ResizeParentToFit();
	Cһ������Doc *pDoc=(Cһ������Doc*)GetDocument();
	m_CoorX=pDoc->m_ptRect.x;
	m_CoorY=pDoc->m_ptRect.y;
	m_SpinX.SetRange(0,1024);
	m_SpinY.SetRange(0,768);
	UpdateData(false);
	m_bEditOK=true;
}


// Cһ������View ���

#ifdef _DEBUG
void Cһ������View::AssertValid() const
{
	CFormView::AssertValid();
}

void Cһ������View::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

Cһ������Doc* Cһ������View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Cһ������Doc)));
	return (Cһ������Doc*)m_pDocument;
}
#endif //_DEBUG


// Cһ������View ��Ϣ�������


void Cһ������View::OnChangeEdit()
{
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
	// ���ʹ�֪ͨ��������д CFormView::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

	if(!m_bEditOK)return;

	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	UpdateData(true);
	Cһ������Doc *pDoc=(Cһ������Doc *)GetDocument();
	pDoc->m_ptRect.x=m_CoorX;
	pDoc->m_ptRect.y=m_CoorY;
	CPoint pt(m_CoorX,m_CoorY);
	GetDocument()->UpdateAllViews(NULL,2,(CObject *)&pt);
}


void Cһ������View::OnUpdate(CView* pSender, LPARAM lHint, CObject* pHint)
{
	// TODO: �ڴ����ר�ô����/����û���
	if(lHint==1)
	{
		CPoint *pPoint =(CPoint *)pHint;
		m_CoorX=pPoint->x;
		m_CoorY=pPoint->y;
		UpdateData(false);
		Cһ������Doc *pDoc=(Cһ������Doc *)GetDocument();
		pDoc->m_ptRect=*pPoint;
	}
}
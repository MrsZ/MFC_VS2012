
// ����ͼ��View.cpp : C����ͼ��View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "����ͼ��.h"
#endif

#include "����ͼ��Doc.h"
#include "����ͼ��View.h"
#include "Line.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// C����ͼ��View

IMPLEMENT_DYNCREATE(C����ͼ��View, CScrollView)

BEGIN_MESSAGE_MAP(C����ͼ��View, CScrollView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CScrollView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CScrollView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CScrollView::OnFilePrintPreview)
	ON_WM_LBUTTONDOWN()
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONUP()
END_MESSAGE_MAP()

// C����ͼ��View ����/����

C����ͼ��View::C����ͼ��View()
{
	// TODO: �ڴ˴���ӹ������
	m_ptEnd=0;
	m_ptStart=0;
}

C����ͼ��View::~C����ͼ��View()
{
}

BOOL C����ͼ��View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// C����ͼ��View ����

void C����ͼ��View::OnDraw(CDC* pDC)
{
	C����ͼ��Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	/*if (!pDoc)
		return;
*/
	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
	CObList *pList=(CObList*)pDoc->GetLineList();
	POSITION pos=pList->GetHeadPosition();
	while(pos!=NULL)
	{
		CLine *pLine=(CLine*)(pList->GetNext(pos));
		pLine->DrawLine(pDC);
	}
}


// C����ͼ��View ��ӡ

BOOL C����ͼ��View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void C����ͼ��View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void C����ͼ��View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}


// C����ͼ��View ���

#ifdef _DEBUG
void C����ͼ��View::AssertValid() const
{
	CView::AssertValid();
}

void C����ͼ��View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

C����ͼ��Doc* C����ͼ��View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(C����ͼ��Doc)));
	return (C����ͼ��Doc*)m_pDocument;
}
#endif //_DEBUG


// C����ͼ��View ��Ϣ�������


void C����ͼ��View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	SetCapture();//��׽���
	m_ptStart=m_ptEnd=point;
	ptOrg=GetScrollPosition();//��õ�ǰ������ԭ�������
	CView::OnLButtonDown(nFlags, point);
}


void C����ͼ��View::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	if(GetCapture()!=this)
		return;//����׽�������Ϣ�Ĵ��ڲ��ǵ�ǰ��ͼ�򷵻�
	CClientDC dc(this);
	CPen newPen(1,1,RGB(0,0,255));
	CPen *oldPen=dc.SelectObject(&newPen);
	int nOldMode=dc.SetROP2(R2_NOTXORPEN);//���û�ͼģʽ,�����ղŻ����߶�
	dc.MoveTo(m_ptStart);
	dc.LineTo(m_ptEnd);
	m_ptEnd=point;
	dc.MoveTo(m_ptStart);
	dc.LineTo(m_ptEnd);
	dc.SelectObject(oldPen);//�ָ�ԭ�ȵĻ���
	dc.SetROP2(nOldMode);//�ָ�ԭ�ȵĻ�ͼģʽ
	CView::OnMouseMove(nFlags, point);
}


void C����ͼ��View::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	if(GetCapture()!=this)return;
	CClientDC dc(this);
	m_ptEnd=point;
	dc.MoveTo(m_ptStart);
	dc.LineTo(m_ptEnd);
	m_ptStart+=ptOrg;
	m_ptEnd+=ptOrg;
	if(m_ptStart!=m_ptEnd)
	{
		CLine *pLine=new CLine(m_ptStart,m_ptEnd);
		C����ͼ��Doc *pDoc=GetDocument();//��ȡ����ͼ����������ĵ�
		CObList *pList=(CObList*)pDoc->GetLineList();//��ȡ�߶ε�����
		pList->AddTail(pLine);//���µ��߶μ��絽����
		pDoc->UpdateAllViews(this,NULL,NULL);//������ͼ
		pDoc->SetModifiedFlag(true);//�����ĵ��޸ı�־
	}
	ReleaseCapture();
	CView::OnLButtonUp(nFlags, point);
}


void C����ͼ��View::OnInitialUpdate()
{
	CScrollView::OnInitialUpdate();

	// TODO: �ڴ����ר�ô����/����û���
	CSize Totalsize;
	Totalsize.cx=Totalsize.cy=2000;
	SetScrollSizes(MM_TEXT,Totalsize);
}

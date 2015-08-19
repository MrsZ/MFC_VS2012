
// ��������View.cpp : C��������View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "��������.h"
#endif

#include "��������Doc.h"
#include "��������View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// C��������View

IMPLEMENT_DYNCREATE(C��������View, CScrollView)

BEGIN_MESSAGE_MAP(C��������View, CScrollView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CScrollView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CScrollView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CScrollView::OnFilePrintPreview)
	ON_WM_LBUTTONDBLCLK()
END_MESSAGE_MAP()

// C��������View ����/����

C��������View::C��������View()
{
	// TODO: �ڴ˴���ӹ������
	memset(&m_lfText,0,sizeof(LOGFONT));
	m_lfText.lfHeight=-12;
	m_lfText.lfCharSet=GB2312_CHARSET;
	strcmp(m_lfText.lfFaceName,"����");
}

C��������View::~C��������View()
{
}

BOOL C��������View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CScrollView::PreCreateWindow(cs);
}

// C��������View ����

void C��������View::OnDraw(CDC* pDC)
{
	C��������Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
	CFont cf;
	cf.CreateFontIndirectA(&m_lfText);
	CFont *oldFont=pDC->SelectObject(&cf);
	//����ÿ�еĸ߶�
	TEXTMETRIC tm;
	pDC->GetTextMetrics(&tm);
	int lineHeight=tm.tmHeight+tm.tmExternalLeading;
	int y=0;
	//һ��tab����Ϊ4���ַ�
	int tab=tm.tmAveCharWidth*4;
	int lineMaxWidth=0;
	CString str;
	CSize lineSize(0,0);
	for(int i=0;i<pDoc->m_strContents.GetSize();i++)
	{
		str=pDoc->m_strContents.GetAt(i);
		pDC->TabbedTextOutA(0,y,str,1,&tab,0);
		str=str+"A";
		lineSize=pDC->GetTabbedTextExtentA(str,1,&tab);
		if(lineMaxWidth<lineSize.cx)
			lineMaxWidth=lineSize.cx;
		y+=lineHeight;
	}
	pDC->SelectObject(oldFont);
	int nLines=pDoc->m_strContents.GetSize()+1;
	CSize sizeTotal;
	sizeTotal.cx=lineMaxWidth;
	sizeTotal.cy=lineHeight*nLines;
	SetScrollSizes(MM_TEXT,sizeTotal);
}

void C��������View::OnInitialUpdate()
{
	CScrollView::OnInitialUpdate();

	CSize sizeTotal;
	// TODO: �������ͼ�ĺϼƴ�С
	sizeTotal.cx = sizeTotal.cy = 100;
	SetScrollSizes(MM_TEXT, sizeTotal);
}


// C��������View ��ӡ

BOOL C��������View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void C��������View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void C��������View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}


// C��������View ���

#ifdef _DEBUG
void C��������View::AssertValid() const
{
	CScrollView::AssertValid();
}

void C��������View::Dump(CDumpContext& dc) const
{
	CScrollView::Dump(dc);
}

C��������Doc* C��������View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(C��������Doc)));
	return (C��������Doc*)m_pDocument;
}
#endif //_DEBUG


// C��������View ��Ϣ�������


void C��������View::OnLButtonDblClk(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	CFontDialog dlg(&m_lfText);
	if(dlg.DoModal()==IDOK)
	{
		dlg.GetCurrentFont(&m_lfText);
		Invalidate();
	}
	CScrollView::OnLButtonDblClk(nFlags, point);
}

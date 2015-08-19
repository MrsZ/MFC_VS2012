// PositionView.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "����ͼ��.h"
#include "PositionView.h"
#include "Line.h"
#include "����ͼ��Doc.h"

// CPositionView

IMPLEMENT_DYNCREATE(CPositionView, CScrollView)

CPositionView::CPositionView()
{

}

CPositionView::~CPositionView()
{
}


BEGIN_MESSAGE_MAP(CPositionView, CScrollView)
END_MESSAGE_MAP()


// CPositionView ��ͼ

void CPositionView::OnInitialUpdate()
{
	CScrollView::OnInitialUpdate();

	CSize sizeTotal;
	// TODO: �������ͼ�ĺϼƴ�С
	sizeTotal.cx = sizeTotal.cy = 1000;
	SetScrollSizes(MM_TEXT, sizeTotal);
}

void CPositionView::OnDraw(CDC* pDC)
{
	//CDocument* pDoc = GetDocument();
	// TODO: �ڴ���ӻ��ƴ���
	C����ͼ��Doc *pDoc=(C����ͼ��Doc *)GetDocument();
	CObList *pList=(CObList *)pDoc->GetLineList();
	POSITION pos=pList->GetHeadPosition();
	CString zuobiao;
	int i=1;
	while(pos!=NULL)
	{
		CLine *pLine=(CLine *)(pList->GetNext(pos));
		zuobiao.Format("�߶�%d�������յ�ֱ��ǣ�%d,%d),(%d,%d)",i,pLine->m_Start.x,pLine->m_Start.y,
			pLine->m_End.x,pLine->m_End.y);
		pDC->TextOutA(10,20*i,zuobiao);
		i++;
	}
}


// CPositionView ���

#ifdef _DEBUG
void CPositionView::AssertValid() const
{
	CScrollView::AssertValid();
}

#ifndef _WIN32_WCE
void CPositionView::Dump(CDumpContext& dc) const
{
	CScrollView::Dump(dc);
}
#endif
#endif //_DEBUG


// CPositionView ��Ϣ�������

// PositionView.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "����ͼ.h"
#include "PositionView.h"
#include "����ͼDoc.h"
#include "Line.h"

// CPositionView

IMPLEMENT_DYNCREATE(CPositionView, CView)

CPositionView::CPositionView()
{

}

CPositionView::~CPositionView()
{
}

BEGIN_MESSAGE_MAP(CPositionView, CView)
END_MESSAGE_MAP()


// CPositionView ��ͼ

void CPositionView::OnDraw(CDC* pDC)
{
	//CDocument* pDoc = GetDocument();
	// TODO: �ڴ���ӻ��ƴ���
	C����ͼDoc *pDoc=(C����ͼDoc *)GetDocument();
	ASSERT_VALID(pDoc);
	CObList *pList=(CObList *)pDoc->GetLineList();
	POSITION pos=pList->GetHeadPosition();
	CString zuobiao;
	int i=1;
	while(pos!=NULL)
	{
		CLine *pLine=(CLine*)(pList->GetNext(pos));
		zuobiao.Format("�߶�%d�������յ�ֱ���:(%d,%d),(%d,%d)",i,pLine->m_Start.x,
			pLine->m_Start.y,pLine->m_End.x,pLine->m_End.y);
		pDC->TextOutA(10,20*i,zuobiao);
		i++;
	}
}


// CPositionView ���

#ifdef _DEBUG
void CPositionView::AssertValid() const
{
	CView::AssertValid();
}

#ifndef _WIN32_WCE
void CPositionView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}
#endif
#endif //_DEBUG


// CPositionView ��Ϣ�������

// DemoView.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "DemoView.h"


// CDemoView

IMPLEMENT_DYNCREATE(CDemoView, CView)

CDemoView::CDemoView()
{

}

CDemoView::~CDemoView()
{
}

BEGIN_MESSAGE_MAP(CDemoView, CView)
END_MESSAGE_MAP()


// CDemoView ��ͼ

void CDemoView::OnDraw(CDC* pDC)
{
	CDocument* pDoc = GetDocument();
	
	// TODO: �ڴ���ӻ��ƴ���
}


// CDemoView ���

#ifdef _DEBUG
void CDemoView::AssertValid() const
{
	CView::AssertValid();
}

#ifndef _WIN32_WCE
void CDemoView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}
#endif
#endif //_DEBUG


// CDemoView ��Ϣ�������

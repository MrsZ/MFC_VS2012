// SwitchView2.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "�л�����.h"
#include "SwitchView2.h"


// CSwitchView2

IMPLEMENT_DYNCREATE(CSwitchView2, CView)

CSwitchView2::CSwitchView2()
{

}

CSwitchView2::~CSwitchView2()
{
}

BEGIN_MESSAGE_MAP(CSwitchView2, CView)
END_MESSAGE_MAP()


// CSwitchView2 ��ͼ

void CSwitchView2::OnDraw(CDC* pDC)
{
	CDocument* pDoc = GetDocument();
	// TODO: �ڴ���ӻ��ƴ���
}


// CSwitchView2 ���

#ifdef _DEBUG
void CSwitchView2::AssertValid() const
{
	CView::AssertValid();
}

#ifndef _WIN32_WCE
void CSwitchView2::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}
#endif
#endif //_DEBUG


// CSwitchView2 ��Ϣ�������


void CSwitchView2::OnPrint(CDC* pDC, CPrintInfo* pInfo)
{
	// TODO: �ڴ����ר�ô����/����û���
	CPaintDC dc(this);
	dc.TextOutA(0,0,"�л�����2",10);
	//CView::OnPrint(pDC, pInfo);
}

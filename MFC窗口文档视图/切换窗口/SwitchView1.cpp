// SwitchView1.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "SwitchView1.h"


// CSwitchView1

IMPLEMENT_DYNCREATE(CSwitchView1, CView)

CSwitchView1::CSwitchView1()
{

}

CSwitchView1::~CSwitchView1()
{
}

BEGIN_MESSAGE_MAP(CSwitchView1, CView)
END_MESSAGE_MAP()


// CSwitchView1 ��ͼ

void CSwitchView1::OnDraw(CDC* pDC)
{
	CDocument* pDoc = GetDocument();
	// TODO: �ڴ���ӻ��ƴ���
}


// CSwitchView1 ���

#ifdef _DEBUG
void CSwitchView1::AssertValid() const
{
	CView::AssertValid();
}

#ifndef _WIN32_WCE
void CSwitchView1::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}
#endif
#endif //_DEBUG


// CSwitchView1 ��Ϣ�������


void CSwitchView1::OnPrint(CDC* pDC, CPrintInfo* pInfo)
{
	// TODO: �ڴ����ר�ô����/����û���
	CPaintDC dc(this);
	dc.TextOutA(0,0,"�л�����1",10);
	//CView::OnPrint(pDC, pInfo);
}

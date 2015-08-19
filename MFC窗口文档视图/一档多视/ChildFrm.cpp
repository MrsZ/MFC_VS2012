
// ChildFrm.cpp : CChildFrame ���ʵ��
//

#include "stdafx.h"
#include "һ������.h"

#include "ChildFrm.h"
#include "һ������View.h"
#include "DrawView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CChildFrame

IMPLEMENT_DYNCREATE(CChildFrame, CMDIChildWnd)

BEGIN_MESSAGE_MAP(CChildFrame, CMDIChildWnd)
END_MESSAGE_MAP()

// CChildFrame ����/����

CChildFrame::CChildFrame()
{
	// TODO: �ڴ���ӳ�Ա��ʼ������
}

CChildFrame::~CChildFrame()
{
}


BOOL CChildFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸� CREATESTRUCT cs ���޸Ĵ��������ʽ
	if( !CMDIChildWnd::PreCreateWindow(cs) )
		return FALSE;

	return TRUE;
}

// CChildFrame ���

#ifdef _DEBUG
void CChildFrame::AssertValid() const
{
	CMDIChildWnd::AssertValid();
}

void CChildFrame::Dump(CDumpContext& dc) const
{
	CMDIChildWnd::Dump(dc);
}
#endif //_DEBUG

// CChildFrame ��Ϣ�������


BOOL CChildFrame::OnCreateClient(LPCREATESTRUCT lpcs, CCreateContext* pContext)
{
	// TODO: �ڴ����ר�ô����/����û���
	CRect rect;
	GetWindowRect(&rect);
	bool bRes=m_wndSplitter.CreateStatic(this,1,2);
	m_wndSplitter.CreateView(0,0,RUNTIME_CLASS(Cһ������View),CSize(0,0),pContext);
	m_wndSplitter.CreateView(0,1,RUNTIME_CLASS(CDrawView),CSize(0,0),pContext);
	m_wndSplitter.SetColumnInfo(0,rect.Width()/2,10);
	m_wndSplitter.SetColumnInfo(1,rect.Width()/2,10);
	m_wndSplitter.RecalcLayout();
	return bRes;
	//return CMDIChildWnd::OnCreateClient(lpcs, pContext);
}

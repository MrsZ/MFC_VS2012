
// MainFrm.cpp : CMainFrame ���ʵ��
//

#include "stdafx.h"
#include "�л�����.h"

#include "MainFrm.h"
#include "SwitchView1.h"
#include "SwitchView2.h"
#include "�л�����View.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CMainFrame

IMPLEMENT_DYNCREATE(CMainFrame, CFrameWnd)

const int  iMaxUserToolbars = 10;
const UINT uiFirstUserToolBarId = AFX_IDW_CONTROLBAR_FIRST + 40;
const UINT uiLastUserToolBarId = uiFirstUserToolBarId + iMaxUserToolbars - 1;

BEGIN_MESSAGE_MAP(CMainFrame, CFrameWnd)
	ON_WM_CREATE()
	ON_COMMAND(ID_SWITCH_VIEW1, &CMainFrame::OnSwitchView1)
	ON_UPDATE_COMMAND_UI(ID_SWITCH_VIEW1, &CMainFrame::OnUpdateSwitchView1)
	ON_COMMAND(ID_SWITCH_VIEW2, &CMainFrame::OnSwitchView2)
	ON_UPDATE_COMMAND_UI(ID_SWITCH_VIEW2, &CMainFrame::OnUpdateSwitchView2)
END_MESSAGE_MAP()

static UINT indicators[] =
{
	ID_SEPARATOR,           // ״̬��ָʾ��
	ID_INDICATOR_CAPS,
	ID_INDICATOR_NUM,
	ID_INDICATOR_SCRL,
};

// CMainFrame ����/����

CMainFrame::CMainFrame()
{
	// TODO: �ڴ���ӳ�Ա��ʼ������
}

CMainFrame::~CMainFrame()
{
}

int CMainFrame::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CFrameWnd::OnCreate(lpCreateStruct) == -1)
		return -1;

	if (!m_wndToolBar.CreateEx(this, TBSTYLE_FLAT, WS_CHILD | WS_VISIBLE | CBRS_TOP | CBRS_GRIPPER | CBRS_TOOLTIPS | CBRS_FLYBY | CBRS_SIZE_DYNAMIC) ||
		!m_wndToolBar.LoadToolBar(IDR_MAINFRAME))
	{
		TRACE0("δ�ܴ���������\n");
		return -1;      // δ�ܴ���
	}

	if (!m_wndStatusBar.Create(this))
	{
		TRACE0("δ�ܴ���״̬��\n");
		return -1;      // δ�ܴ���
	}
	m_wndStatusBar.SetIndicators(indicators, sizeof(indicators)/sizeof(UINT));

	// TODO: �������Ҫ��ͣ������������ɾ��������
	m_wndToolBar.EnableDocking(CBRS_ALIGN_ANY);
	EnableDocking(CBRS_ALIGN_ANY);
	DockControlBar(&m_wndToolBar);


	return 0;
}

BOOL CMainFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	if( !CFrameWnd::PreCreateWindow(cs) )
		return FALSE;
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return TRUE;
}

// CMainFrame ���

#ifdef _DEBUG
void CMainFrame::AssertValid() const
{
	CFrameWnd::AssertValid();
}

void CMainFrame::Dump(CDumpContext& dc) const
{
	CFrameWnd::Dump(dc);
}
#endif //_DEBUG


// CMainFrame ��Ϣ�������



void CMainFrame::OnSwitchView1()
{
	// TODO: �ڴ���������������
	CRect cr;
	GetClientRect(&cr);
	CSize paneSize1(3*cr.Width()/4,cr.Height());
	CCreateContext Context;
	Context.m_pNewViewClass=RUNTIME_CLASS(CSwitchView1);
	Context.m_pCurrentDoc=((C�л�����App*)AfxGetApp())->m_pDoc;
	Context.m_pCurrentFrame=this;
	Context.m_pNewDocTemplate=Context.m_pCurrentDoc->GetDocTemplate();
	Context.m_pLastView=(C�л�����View *)m_wndSplitter.GetPane(0,0);
	m_wndSplitter.DeleteView(0,1);
	m_wndSplitter.CreateView(0,1,RUNTIME_CLASS(CSwitchView1),paneSize1,&Context);
	CSwitchView1 *pView=(CSwitchView1 *)m_wndSplitter.GetPane(0,1);
	pView->GetParentFrame()->RecalcLayout();
	m_wndSplitter.RecalcLayout();
	pView->OnInitialUpdate();
	m_wndSplitter.SetActivePane(0,1);
}


void CMainFrame::OnUpdateSwitchView1(CCmdUI *pCmdUI)
{
	// TODO: �ڴ������������û����洦��������
	pCmdUI->Enable(!m_wndSplitter.GetPane(0,1)->IsKindOf(RUNTIME_CLASS(CSwitchView1)));
}


void CMainFrame::OnSwitchView2()
{
	// TODO: �ڴ���������������
	CRect cr;
	GetClientRect(&cr);
	CSize paneSize1(3*cr.Width()/4,cr.Height());
	CCreateContext Context;
	Context.m_pNewViewClass=RUNTIME_CLASS(CSwitchView2);
	Context.m_pCurrentDoc=((C�л�����App*)AfxGetApp())->m_pDoc;
	Context.m_pCurrentFrame=this;
	Context.m_pNewDocTemplate=Context.m_pCurrentDoc->GetDocTemplate();
	Context.m_pLastView=(C�л�����View *)m_wndSplitter.GetPane(0,0);
	m_wndSplitter.DeleteView(0,1);
	m_wndSplitter.CreateView(0,1,RUNTIME_CLASS(CSwitchView2),paneSize1,&Context);
	CSwitchView2 *pView=(CSwitchView2 *)m_wndSplitter.GetPane(0,1);
	pView->GetParentFrame()->RecalcLayout();
	m_wndSplitter.RecalcLayout();
	pView->OnInitialUpdate();
	m_wndSplitter.SetActivePane(0,1);
}


void CMainFrame::OnUpdateSwitchView2(CCmdUI *pCmdUI)
{
	// TODO: �ڴ������������û����洦��������
	pCmdUI->Enable(!m_wndSplitter.GetPane(0,1)->IsKindOf(RUNTIME_CLASS(CSwitchView2)));
}


BOOL CMainFrame::OnCreateClient(LPCREATESTRUCT lpcs, CCreateContext* pContext)
{
	// TODO: �ڴ����ר�ô����/����û���
	CRect cr;
	BOOL rc;
	if(!m_wndSplitter.CreateStatic(this,1,2))
	{
		TRACE0("Failed to create split bar");
		return false;
	}
	GetClientRect(&cr);
	CSize paneSize(cr.Width()/4,cr.Height());
	CSize paneSize1(3*cr.Width()/4,cr.Height());
	((C�л�����App *)AfxGetApp())->m_pDoc=(C�л�����Doc *)(pContext->m_pCurrentDoc);
	pContext->m_pCurrentFrame=this;
	rc=m_wndSplitter.CreateView(0,0,pContext->m_pNewViewClass,paneSize,pContext);
	if(!rc)return false;
	pContext->m_pNewViewClass=RUNTIME_CLASS(CSwitchView1);
	pContext->m_pCurrentDoc=((C�л�����App *)AfxGetApp())->m_pDoc;
	pContext->m_pCurrentFrame=this;
	rc=m_wndSplitter.CreateView(0,1,pContext->m_pNewViewClass,paneSize1,pContext);
	m_wndSplitter.RecalcLayout();
	m_wndSplitter.SetActivePane(0,1);
	return rc;

	//return CFrameWnd::OnCreateClient(lpcs, pContext);
}


// MainFrm.cpp : CMainFrame 类的实现
//

#include "stdafx.h"
#include "切换窗口.h"

#include "MainFrm.h"
#include "SwitchView1.h"
#include "SwitchView2.h"
#include "切换窗口View.h"


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
	ID_SEPARATOR,           // 状态行指示器
	ID_INDICATOR_CAPS,
	ID_INDICATOR_NUM,
	ID_INDICATOR_SCRL,
};

// CMainFrame 构造/析构

CMainFrame::CMainFrame()
{
	// TODO: 在此添加成员初始化代码
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
		TRACE0("未能创建工具栏\n");
		return -1;      // 未能创建
	}

	if (!m_wndStatusBar.Create(this))
	{
		TRACE0("未能创建状态栏\n");
		return -1;      // 未能创建
	}
	m_wndStatusBar.SetIndicators(indicators, sizeof(indicators)/sizeof(UINT));

	// TODO: 如果不需要可停靠工具栏，则删除这三行
	m_wndToolBar.EnableDocking(CBRS_ALIGN_ANY);
	EnableDocking(CBRS_ALIGN_ANY);
	DockControlBar(&m_wndToolBar);


	return 0;
}

BOOL CMainFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	if( !CFrameWnd::PreCreateWindow(cs) )
		return FALSE;
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return TRUE;
}

// CMainFrame 诊断

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


// CMainFrame 消息处理程序



void CMainFrame::OnSwitchView1()
{
	// TODO: 在此添加命令处理程序代码
	CRect cr;
	GetClientRect(&cr);
	CSize paneSize1(3*cr.Width()/4,cr.Height());
	CCreateContext Context;
	Context.m_pNewViewClass=RUNTIME_CLASS(CSwitchView1);
	Context.m_pCurrentDoc=((C切换窗口App*)AfxGetApp())->m_pDoc;
	Context.m_pCurrentFrame=this;
	Context.m_pNewDocTemplate=Context.m_pCurrentDoc->GetDocTemplate();
	Context.m_pLastView=(C切换窗口View *)m_wndSplitter.GetPane(0,0);
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
	// TODO: 在此添加命令更新用户界面处理程序代码
	pCmdUI->Enable(!m_wndSplitter.GetPane(0,1)->IsKindOf(RUNTIME_CLASS(CSwitchView1)));
}


void CMainFrame::OnSwitchView2()
{
	// TODO: 在此添加命令处理程序代码
	CRect cr;
	GetClientRect(&cr);
	CSize paneSize1(3*cr.Width()/4,cr.Height());
	CCreateContext Context;
	Context.m_pNewViewClass=RUNTIME_CLASS(CSwitchView2);
	Context.m_pCurrentDoc=((C切换窗口App*)AfxGetApp())->m_pDoc;
	Context.m_pCurrentFrame=this;
	Context.m_pNewDocTemplate=Context.m_pCurrentDoc->GetDocTemplate();
	Context.m_pLastView=(C切换窗口View *)m_wndSplitter.GetPane(0,0);
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
	// TODO: 在此添加命令更新用户界面处理程序代码
	pCmdUI->Enable(!m_wndSplitter.GetPane(0,1)->IsKindOf(RUNTIME_CLASS(CSwitchView2)));
}


BOOL CMainFrame::OnCreateClient(LPCREATESTRUCT lpcs, CCreateContext* pContext)
{
	// TODO: 在此添加专用代码和/或调用基类
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
	((C切换窗口App *)AfxGetApp())->m_pDoc=(C切换窗口Doc *)(pContext->m_pCurrentDoc);
	pContext->m_pCurrentFrame=this;
	rc=m_wndSplitter.CreateView(0,0,pContext->m_pNewViewClass,paneSize,pContext);
	if(!rc)return false;
	pContext->m_pNewViewClass=RUNTIME_CLASS(CSwitchView1);
	pContext->m_pCurrentDoc=((C切换窗口App *)AfxGetApp())->m_pDoc;
	pContext->m_pCurrentFrame=this;
	rc=m_wndSplitter.CreateView(0,1,pContext->m_pNewViewClass,paneSize1,pContext);
	m_wndSplitter.RecalcLayout();
	m_wndSplitter.SetActivePane(0,1);
	return rc;

	//return CFrameWnd::OnCreateClient(lpcs, pContext);
}

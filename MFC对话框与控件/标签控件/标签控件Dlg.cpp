
// 标签控件Dlg.cpp : 实现文件
//

#include "stdafx.h"
#include "标签控件.h"
#include "标签控件Dlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
public:
//	virtual BOOL OnInitDialog();
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// C标签控件Dlg 对话框



C标签控件Dlg::C标签控件Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(C标签控件Dlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void C标签控件Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_TAB1, m_Tab);
}

BEGIN_MESSAGE_MAP(C标签控件Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_NOTIFY(TCN_SELCHANGE, IDC_TAB1, &C标签控件Dlg::OnSelchangeTab1)
	ON_WM_DESTROY()
END_MESSAGE_MAP()


// C标签控件Dlg 消息处理程序

BOOL C标签控件Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码
	m_pTab1Dlg=new CTab1Dlg();
	m_pTab2Dlg=new CTab2Dlg();
	m_pTab3Dlg=new CTab3Dlg();
	//创建无模式对话框，指定标签控件为无模式对话框的父窗口
	m_pTab1Dlg->Create(IDD_DIALOG1,&m_Tab);
	m_pTab2Dlg->Create(IDD_DIALOG2,&m_Tab);
	m_pTab3Dlg->Create(IDD_DIALOG3,&m_Tab);
	//创建图像列表
	m_ImageList.Create(16,16,ILC_COLOR4|ILC_MASK,3,0);
	m_ImageList.Add(AfxGetApp()->LoadIconA(IDI_ICON1));
	m_ImageList.Add(AfxGetApp()->LoadIconA(IDI_ICON2));
	m_ImageList.Add(AfxGetApp()->LoadIconA(IDI_ICON3));
	m_Tab.SetImageList(&m_ImageList);
	m_Tab.InsertItem(0,"基本信息",0);
	m_Tab.InsertItem(1,"成绩",1);
	m_Tab.InsertItem(2,"备注",2);
	//设置标签的最小宽度
	m_Tab.SetMinTabWidth(80);
	//设置标签项和图标周围的间隔
	m_Tab.SetPadding(CSize(12,3));
	m_Tab.SetCurSel(0);
	DoTab(0);
	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void C标签控件Dlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void C标签控件Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR C标签控件Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void C标签控件Dlg::SetDlgState(CWnd *pWnd,BOOL bShow)
{
	pWnd->EnableWindow(bShow);
	if(bShow)
	{
		pWnd->ShowWindow(SW_SHOW);//显示
		pWnd->CenterWindow();//居中显示
	}
	else
		pWnd->ShowWindow(SW_HIDE);//隐藏
}
void C标签控件Dlg::DoTab(int nTab)
{
	if(nTab>2)nTab=2;
	if(nTab<0)nTab=0;
	BOOL bTab[3];
	bTab[0]=bTab[1]=bTab[2]=false;
	bTab[nTab]=true;
	SetDlgState(m_pTab1Dlg,bTab[0]);
	SetDlgState(m_pTab2Dlg,bTab[1]);
	SetDlgState(m_pTab3Dlg,bTab[2]);
}



void C标签控件Dlg::OnSelchangeTab1(NMHDR *pNMHDR, LRESULT *pResult)
{
	// TODO: 在此添加控件通知处理程序代码
	int nSelect=m_Tab.GetCurSel();
	if(nSelect>=0)DoTab(nSelect);
	*pResult = 0;
}




void C标签控件Dlg::OnDestroy()
{
	CDialogEx::OnDestroy();
	if(m_pTab1Dlg)delete m_pTab1Dlg;
	if(m_pTab2Dlg)delete m_pTab2Dlg;
	if(m_pTab3Dlg)delete m_pTab3Dlg;
	// TODO: 在此处添加消息处理程序代码
}

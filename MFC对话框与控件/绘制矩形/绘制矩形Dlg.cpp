
// 绘制矩形Dlg.cpp : 实现文件
//

#include "stdafx.h"
#include "绘制矩形.h"
#include "绘制矩形Dlg.h"
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


// C绘制矩形Dlg 对话框



C绘制矩形Dlg::C绘制矩形Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(C绘制矩形Dlg::IDD, pParent)
	, m_Length(0)
	, m_Width(0)
	, m_LineWidth(0)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void C绘制矩形Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_LENGTH, m_Length);
	DDX_Control(pDX, IDC_SPIN1, m_LengthSpin);
	DDX_Text(pDX, IDC_WIDTH, m_Width);
	DDX_Control(pDX, IDC_SPIN2, m_WidthSpin);
	DDX_Control(pDX, IDC_LINEWIDTHSLIDER, m_LineWidthSlider);
	DDX_Control(pDX, IDC_APPLY, m_Room);
	DDX_Slider(pDX, IDC_LINEWIDTHSLIDER, m_LineWidth);
}

BEGIN_MESSAGE_MAP(C绘制矩形Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_APPLY, &C绘制矩形Dlg::OnClickedApply)
	ON_BN_CLICKED(EXITBUTTON, &C绘制矩形Dlg::OnClickedExitbutton)
	ON_WM_HSCROLL()
END_MESSAGE_MAP()


// C绘制矩形Dlg 消息处理程序

BOOL C绘制矩形Dlg::OnInitDialog()
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
	m_WidthSpin.SetRange(10,100);
	m_WidthSpin.SetPos(0);
	m_LengthSpin.SetRange(10,100);
	m_LengthSpin.SetPos(0);
	m_LineWidthSlider.SetRange(1,10);
	m_LineWidthSlider.SetPos(0);
	m_LineWidthSlider.SetTicFreq(1);//设置滑动块刻度标尺，每一个单位一个标记
	SetDlgItemText(IDC_LINEWIDTH,"线宽:1");
	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void C绘制矩形Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void C绘制矩形Dlg::OnPaint()
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
HCURSOR C绘制矩形Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void C绘制矩形Dlg::OnClickedApply()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData();
	Invalidate();//使用户视图区无效，以清除上次画的图
	UpdateWindow();//刷新用户视图区域
	CClientDC dc(this);
	CPen mypen;
	mypen.CreatePen(PS_SOLID,m_LineWidth,RGB(255,0,0));//创建画笔
	CPen *pOldpen=dc.SelectObject(&mypen);//将画笔进入设备环境
	dc.Rectangle(70,10,150+m_Length,30+m_Width);//画一个矩形
	dc.SelectObject(pOldpen);//恢复原来的画笔
}


void C绘制矩形Dlg::OnClickedExitbutton()
{
	// TODO: 在此添加控件通知处理程序代码
	OnOK();
}


void C绘制矩形Dlg::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	UpdateData();
	CString LineWidth;
	LineWidth.Format("线宽:%d",m_LineWidth);
	SetDlgItemText(IDC_LINEWIDTH,LineWidth);
	CDialogEx::OnHScroll(nSBCode, nPos, pScrollBar);
}

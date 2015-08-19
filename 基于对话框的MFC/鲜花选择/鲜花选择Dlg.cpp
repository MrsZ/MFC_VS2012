
// 鲜花选择Dlg.cpp : 实现文件
//

#include "stdafx.h"
#include "鲜花选择.h"
#include "鲜花选择Dlg.h"
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


// C鲜花选择Dlg 对话框



C鲜花选择Dlg::C鲜花选择Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(C鲜花选择Dlg::IDD, pParent)
	, m_check1(false)
	, m_check2(false)
	, m_check3(false)
	, m_check4(false)
	, m_text(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void C鲜花选择Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_text);
}

BEGIN_MESSAGE_MAP(C鲜花选择Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_COMMAND(IDC_RADIO1, &C鲜花选择Dlg::OnRadio1)
	ON_COMMAND(IDC_RADIO2, &C鲜花选择Dlg::OnRadio2)
	ON_COMMAND(IDC_RADIO3, &C鲜花选择Dlg::OnRadio3)
	ON_COMMAND(IDC_RADIO4, &C鲜花选择Dlg::OnRadio4)
	ON_BN_CLICKED(IDC_CHECK1, &C鲜花选择Dlg::OnClickedCheck1)
	ON_BN_CLICKED(IDC_CHECK2, &C鲜花选择Dlg::OnClickedCheck2)
	ON_BN_CLICKED(IDC_CHECK3, &C鲜花选择Dlg::OnClickedCheck3)
	ON_BN_CLICKED(IDC_CHECK4, &C鲜花选择Dlg::OnClickedCheck4)
END_MESSAGE_MAP()


// C鲜花选择Dlg 消息处理程序

BOOL C鲜花选择Dlg::OnInitDialog()
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

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void C鲜花选择Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void C鲜花选择Dlg::OnPaint()
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
HCURSOR C鲜花选择Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


int n=0;
void C鲜花选择Dlg::OnRadio1()
{
	// TODO: 在此添加命令处理程序代码
	n=1;
	m_check1=true;
	m_check2=true;
	m_check3=true;
	m_check4=true;
	m_text="有4种花出售";
	UpdateData(false);
}


void C鲜花选择Dlg::OnRadio2()
{
	// TODO: 在此添加命令处理程序代码
	n=2;
	m_check1=true;
	m_check2=false;
	m_check3=true;
	m_check4=false;
	m_text="有2种花出售";
	UpdateData(false);
}


void C鲜花选择Dlg::OnRadio3()
{
	// TODO: 在此添加命令处理程序代码
	n=3;
	m_check1=false;
	m_check2=true;
	m_check3=false;
	m_check4=true;
	m_text="有2种花出售";
	UpdateData(false);
}


void C鲜花选择Dlg::OnRadio4()
{
	// TODO: 在此添加命令处理程序代码
	n=4;
	m_check1=true;
	m_check2=true;
	m_check3=true;
	m_check4=false;
	m_text="有3种花出售";
	UpdateData(false);
}


void C鲜花选择Dlg::OnClickedCheck1()
{
	// TODO: 在此添加控件通知处理程序代码
	if(n==3||n==0)
	{
		m_text="";
		m_check1=false;
		m_check2=false;
		m_check3=false;
		m_check4=false;
		UpdateData(false);
		return;
	}
	m_text="价格Price：$100.00";
	m_check1=true;
	m_check2=false;
	m_check3=false;
	m_check4=false;
	UpdateData(false);
}


void C鲜花选择Dlg::OnClickedCheck2()
{
	// TODO: 在此添加控件通知处理程序代码
	if(n==2||n==0)
	{
		m_text="";
		m_check1=false;
		m_check2=false;
		m_check3=false;
		m_check4=false;
		UpdateData(false);
		return;
	}
	m_text="价格Price：$110:00";
	m_check1=false;
	m_check2=true;
	m_check3=false;
	m_check4=false;
	UpdateData(false);
}


void C鲜花选择Dlg::OnClickedCheck3()
{
	// TODO: 在此添加控件通知处理程序代码
	if(n==3||n==0)
	{
		m_text="";
		m_check1=false;
		m_check2=false;
		m_check3=false;
		m_check4=false;
		UpdateData(false);
		return;
	}
	m_text="价格Price:$130.00";
	m_check1=false;
	m_check2=false;
	m_check2=true;
	m_check4=false;
	UpdateData(false);
}


void C鲜花选择Dlg::OnClickedCheck4()
{
	// TODO: 在此添加控件通知处理程序代码
	if(n==4||n==2||n==0)
	{
		m_text="";
		m_check1=false;
		m_check2=false;
		m_check3=false;
		m_check4=false;
		UpdateData(false);
		return;
	}
	m_text="价格Price:$150.00";
	m_check1=false;
	m_check2=false;
	m_check2=false;
	m_check4=true;
	UpdateData(false);
}

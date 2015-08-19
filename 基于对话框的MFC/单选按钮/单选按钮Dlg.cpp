
// 单选按钮Dlg.cpp : 实现文件
//

#include "stdafx.h"
#include "单选按钮.h"
#include "单选按钮Dlg.h"
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


// C单选按钮Dlg 对话框



C单选按钮Dlg::C单选按钮Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(C单选按钮Dlg::IDD, pParent)
	, m_text1(_T(""))
	, m_text2(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void C单选按钮Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_text1);
	DDX_Text(pDX, IDC_EDIT2, m_text2);
}

BEGIN_MESSAGE_MAP(C单选按钮Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_COMMAND(IDC_RADIO1, &C单选按钮Dlg::OnRadio1)
	ON_COMMAND(IDC_RADIO2, &C单选按钮Dlg::OnRadio2)
	ON_COMMAND(IDC_RADIO3, &C单选按钮Dlg::OnRadio3)
	ON_BN_CLICKED(IDC_RADIO4, &C单选按钮Dlg::OnClickedRadio4)
	ON_COMMAND(IDC_RADIO5, &C单选按钮Dlg::OnRadio5)
	ON_COMMAND(IDC_RADIO6, &C单选按钮Dlg::OnRadio6)
END_MESSAGE_MAP()


// C单选按钮Dlg 消息处理程序

BOOL C单选按钮Dlg::OnInitDialog()
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

void C单选按钮Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void C单选按钮Dlg::OnPaint()
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
HCURSOR C单选按钮Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void C单选按钮Dlg::OnRadio1()
{
	// TODO: 在此添加命令处理程序代码
	m_text1="你选择了第一个单选按钮";
	UpdateData(false);
}


void C单选按钮Dlg::OnRadio2()
{
	// TODO: 在此添加命令处理程序代码
	m_text1="你选择了第二个单选按钮";
	UpdateData(false);
}


void C单选按钮Dlg::OnRadio3()
{
	// TODO: 在此添加命令处理程序代码
	m_text1="你选择了第三个单选按钮";
	UpdateData(false);
}


void C单选按钮Dlg::OnClickedRadio4()
{
	// TODO: 在此添加控件通知处理程序代码
	m_text2="你选中了单选按钮4";
	UpdateData(false);
}


void C单选按钮Dlg::OnRadio5()
{
	// TODO: 在此添加命令处理程序代码
	m_text2="你选中了单选按钮5";
	UpdateData(false);
}


void C单选按钮Dlg::OnRadio6()
{
	// TODO: 在此添加命令处理程序代码
	m_text2="你选中了单选按钮6";
	UpdateData(false);
}

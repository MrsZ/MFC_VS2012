
// 成绩登记Dlg.cpp : 实现文件
//

#include "stdafx.h"
#include "成绩登记.h"
#include "成绩登记Dlg.h"
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


// C成绩登记Dlg 对话框



C成绩登记Dlg::C成绩登记Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(C成绩登记Dlg::IDD, pParent)
	, m_strName(_T(""))
	, m_nEng(0)
	, m_nMat(0)
	, m_nCom(0)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void C成绩登记Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST, m_List);
	DDX_Text(pDX, IDC_NAME, m_strName);
	DDV_MaxChars(pDX, m_strName, 20);
	DDX_Text(pDX, IDC_ENG, m_nEng);
	DDX_Text(pDX, IDC_MAT, m_nMat);
	DDX_Text(pDX, IDC_COM, m_nCom);
}

BEGIN_MESSAGE_MAP(C成绩登记Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_ADD, &C成绩登记Dlg::OnClickedAdd)
	ON_BN_CLICKED(IDC_DEL, &C成绩登记Dlg::OnClickedDel)
	ON_LBN_SELCHANGE(IDC_LIST, &C成绩登记Dlg::OnSelchangeList)
	ON_WM_DESTROY()
END_MESSAGE_MAP()


// C成绩登记Dlg 消息处理程序

BOOL C成绩登记Dlg::OnInitDialog()
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

void C成绩登记Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void C成绩登记Dlg::OnPaint()
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
HCURSOR C成绩登记Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void C成绩登记Dlg::OnClickedAdd()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(true);
	if(m_strName.IsEmpty())
	{
		MessageBox("姓名不能为空");
		return;
	}
	m_strName.TrimLeft();
	m_strName.TrimRight();
	if((m_List.FindString(-1,m_strName))!=LB_ERR)
	{
		MessageBox("列表框中已有相同名字，不能添加");
		return;
	}
	int nIndex=m_List.AddString(m_strName);
	SCORE data;
	data.scoreE=m_nEng;
	data.scoreM=m_nMat;
	data.scoreC=m_nCom;
	m_List.SetItemDataPtr(nIndex,new SCORE(data));
}


void C成绩登记Dlg::OnClickedDel()
{
	// TODO: 在此添加控件通知处理程序代码
	int nIndex=m_List.GetCurSel();
	if(nIndex!=LB_ERR)
	{
		m_List.DeleteString(nIndex);
		m_strName.Empty();
		m_nEng=m_nMat=m_nCom=0;
		UpdateData(false);
	}
	else
		MessageBox("当前没有选择项或列表框操作失败");
}


void C成绩登记Dlg::OnSelchangeList()
{
	// TODO: 在此添加控件通知处理程序代码
	int nIndex=m_List.GetCurSel();
	if(nIndex!=LB_ERR)
	{
		m_List.GetText(nIndex,m_strName);
		SCORE *data=(SCORE *)m_List.GetItemDataPtr(nIndex);
		m_nEng=data->scoreE;
		m_nMat=data->scoreM;
		m_nCom=data->scoreC;
		UpdateData(false);
	}
}


void C成绩登记Dlg::OnDestroy()
{
	for(int nIndex=m_List.GetCount()-1;nIndex>=0;nIndex--)
	{
		delete(SCORE *)m_List.GetItemDataPtr(nIndex);
	}
	CDialogEx::OnDestroy();

	// TODO: 在此处添加消息处理程序代码
}


// 列表框Dlg.cpp : 实现文件
//

#include "stdafx.h"
#include "列表框.h"
#include "列表框Dlg.h"
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


// C列表框Dlg 对话框



C列表框Dlg::C列表框Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(C列表框Dlg::IDD, pParent)
	, m_strName(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void C列表框Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_NAMELIST, m_NameList);
	DDX_Text(pDX, IDC_NAME, m_strName);
}

BEGIN_MESSAGE_MAP(C列表框Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_ADD, &C列表框Dlg::OnClickedAdd)
	ON_BN_CLICKED(IDC_DELETE, &C列表框Dlg::OnClickedDelete)
	ON_BN_CLICKED(IDC_EXITBUTTON, &C列表框Dlg::OnClickedExitbutton)
END_MESSAGE_MAP()


// C列表框Dlg 消息处理程序

BOOL C列表框Dlg::OnInitDialog()
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

void C列表框Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void C列表框Dlg::OnPaint()
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
HCURSOR C列表框Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void C列表框Dlg::OnClickedAdd()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData();
	if(m_strName.IsEmpty())
	{
		AfxMessageBox("请输入姓名");
		return;
	}
	m_strName.TrimLeft();//去掉字符串左边的换行符号、空格和控制字符
	m_strName.TrimRight();
	if(m_NameList.FindString(-1,m_strName)!=LB_ERR)
	{
		AfxMessageBox("该姓名已存在，请重新输入!");
		return;
	}
	int index;
	///将字符串加到列表框中
	index=m_NameList.AddString(m_strName);
	//将字符串与列表项关联起来
	m_NameList.SetItemDataPtr(index,new CString(m_strName));
}


void C列表框Dlg::OnClickedDelete()
{
	// TODO: 在此添加控件通知处理程序代码
	int index;
	index=m_NameList.GetCurSel();
	if(index!=LB_ERR)
	{
		//释放关联数据所占的内存空间
		delete (CString *)m_NameList.GetItemDataPtr(index);
		//删除列表框当前选项
		m_NameList.DeleteString(index);
		//在列表框中显示数据
		UpdateData(false);
	}
	else
		AfxMessageBox("没有选择列表框活选择失败！");
}


void C列表框Dlg::OnClickedExitbutton()
{
	// TODO: 在此添加控件通知处理程序代码
	//退出
	OnOK();
}

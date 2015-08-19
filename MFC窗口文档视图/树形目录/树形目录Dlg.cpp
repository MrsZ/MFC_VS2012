
// 树形目录Dlg.cpp : 实现文件
//

#include "stdafx.h"
#include "树形目录.h"
#include "树形目录Dlg.h"
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


// C树形目录Dlg 对话框



C树形目录Dlg::C树形目录Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(C树形目录Dlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void C树形目录Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_TREEVIEW, m_TreeCtrl);
}

BEGIN_MESSAGE_MAP(C树形目录Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_NOTIFY(TVN_SELCHANGED, IDC_TREEVIEW, &C树形目录Dlg::OnSelchangedTreeview)
END_MESSAGE_MAP()


// C树形目录Dlg 消息处理程序

BOOL C树形目录Dlg::OnInitDialog()
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
		TV_ITEM tvItem;
	tvItem.mask=TVIF_TEXT|TVIF_PARAM;
	tvItem.pszText="C:";
	tvItem.cchTextMax=2;
	TV_INSERTSTRUCT tvInsert;
	tvInsert.hParent=TVI_ROOT;
	tvInsert.hInsertAfter=TVI_LAST;
	tvInsert.item=tvItem;
	HTREEITEM hRoot=m_TreeCtrl.InsertItem(&tvInsert);

	tvItem.pszText="图形图像设计";
	tvItem.cchTextMax=6;
	tvInsert.hParent=hRoot;
	tvInsert.item=tvItem;
	m_TreeCtrl.InsertItem(&tvInsert);

	tvItem.pszText="动漫设计";
	tvItem.cchTextMax=7;
	tvInsert.hParent=hRoot;
	tvInsert.item=tvItem;
	m_TreeCtrl.InsertItem(&tvInsert);

	tvItem.pszText="D:";
	tvItem.cchTextMax=2;
	tvInsert.hParent=TVI_ROOT;
	tvInsert.item=tvItem;
	m_TreeCtrl.InsertItem(&tvInsert);

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void C树形目录Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void C树形目录Dlg::OnPaint()
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
HCURSOR C树形目录Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void C树形目录Dlg::OnSelchangedTreeview(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMTREEVIEW pNMTreeView = reinterpret_cast<LPNMTREEVIEW>(pNMHDR);
	//@TN
	//	*pResult = 0;
	//// TODO: 在此添加控件通知处理程序代码

	char str[20];
	CTreeCtrl *pTree=(CTreeCtrl *)GetDlgItem(IDC_TREEVIEW);
	HTREEITEM pSelected=pNMTreeView->itemNew.hItem;
	TV_ITEM item;
	item.mask=TVIF_HANDLE|TVIF_TEXT;
	item.hItem=pSelected;
	item.pszText=str;
	item.cchTextMax=20;
	VERIFY(pTree->GetItem(&item));
	SetDlgItemText(IDC_STATIC,str);
	*pResult = 0;
}

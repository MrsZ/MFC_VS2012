
// ����Ŀ¼Dlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "����Ŀ¼.h"
#include "����Ŀ¼Dlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �Ի�������
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
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


// C����Ŀ¼Dlg �Ի���



C����Ŀ¼Dlg::C����Ŀ¼Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(C����Ŀ¼Dlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void C����Ŀ¼Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_TREEVIEW, m_TreeCtrl);
}

BEGIN_MESSAGE_MAP(C����Ŀ¼Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_NOTIFY(TVN_SELCHANGED, IDC_TREEVIEW, &C����Ŀ¼Dlg::OnSelchangedTreeview)
END_MESSAGE_MAP()


// C����Ŀ¼Dlg ��Ϣ�������

BOOL C����Ŀ¼Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
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

	// ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������
		TV_ITEM tvItem;
	tvItem.mask=TVIF_TEXT|TVIF_PARAM;
	tvItem.pszText="C:";
	tvItem.cchTextMax=2;
	TV_INSERTSTRUCT tvInsert;
	tvInsert.hParent=TVI_ROOT;
	tvInsert.hInsertAfter=TVI_LAST;
	tvInsert.item=tvItem;
	HTREEITEM hRoot=m_TreeCtrl.InsertItem(&tvInsert);

	tvItem.pszText="ͼ��ͼ�����";
	tvItem.cchTextMax=6;
	tvInsert.hParent=hRoot;
	tvInsert.item=tvItem;
	m_TreeCtrl.InsertItem(&tvInsert);

	tvItem.pszText="�������";
	tvItem.cchTextMax=7;
	tvInsert.hParent=hRoot;
	tvInsert.item=tvItem;
	m_TreeCtrl.InsertItem(&tvInsert);

	tvItem.pszText="D:";
	tvItem.cchTextMax=2;
	tvInsert.hParent=TVI_ROOT;
	tvInsert.item=tvItem;
	m_TreeCtrl.InsertItem(&tvInsert);

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void C����Ŀ¼Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void C����Ŀ¼Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR C����Ŀ¼Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void C����Ŀ¼Dlg::OnSelchangedTreeview(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMTREEVIEW pNMTreeView = reinterpret_cast<LPNMTREEVIEW>(pNMHDR);
	//@TN
	//	*pResult = 0;
	//// TODO: �ڴ���ӿؼ�֪ͨ����������

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

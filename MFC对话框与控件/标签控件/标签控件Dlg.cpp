
// ��ǩ�ؼ�Dlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "��ǩ�ؼ�.h"
#include "��ǩ�ؼ�Dlg.h"
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


// C��ǩ�ؼ�Dlg �Ի���



C��ǩ�ؼ�Dlg::C��ǩ�ؼ�Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(C��ǩ�ؼ�Dlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void C��ǩ�ؼ�Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_TAB1, m_Tab);
}

BEGIN_MESSAGE_MAP(C��ǩ�ؼ�Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_NOTIFY(TCN_SELCHANGE, IDC_TAB1, &C��ǩ�ؼ�Dlg::OnSelchangeTab1)
	ON_WM_DESTROY()
END_MESSAGE_MAP()


// C��ǩ�ؼ�Dlg ��Ϣ�������

BOOL C��ǩ�ؼ�Dlg::OnInitDialog()
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
	m_pTab1Dlg=new CTab1Dlg();
	m_pTab2Dlg=new CTab2Dlg();
	m_pTab3Dlg=new CTab3Dlg();
	//������ģʽ�Ի���ָ����ǩ�ؼ�Ϊ��ģʽ�Ի���ĸ�����
	m_pTab1Dlg->Create(IDD_DIALOG1,&m_Tab);
	m_pTab2Dlg->Create(IDD_DIALOG2,&m_Tab);
	m_pTab3Dlg->Create(IDD_DIALOG3,&m_Tab);
	//����ͼ���б�
	m_ImageList.Create(16,16,ILC_COLOR4|ILC_MASK,3,0);
	m_ImageList.Add(AfxGetApp()->LoadIconA(IDI_ICON1));
	m_ImageList.Add(AfxGetApp()->LoadIconA(IDI_ICON2));
	m_ImageList.Add(AfxGetApp()->LoadIconA(IDI_ICON3));
	m_Tab.SetImageList(&m_ImageList);
	m_Tab.InsertItem(0,"������Ϣ",0);
	m_Tab.InsertItem(1,"�ɼ�",1);
	m_Tab.InsertItem(2,"��ע",2);
	//���ñ�ǩ����С���
	m_Tab.SetMinTabWidth(80);
	//���ñ�ǩ���ͼ����Χ�ļ��
	m_Tab.SetPadding(CSize(12,3));
	m_Tab.SetCurSel(0);
	DoTab(0);
	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void C��ǩ�ؼ�Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void C��ǩ�ؼ�Dlg::OnPaint()
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
HCURSOR C��ǩ�ؼ�Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void C��ǩ�ؼ�Dlg::SetDlgState(CWnd *pWnd,BOOL bShow)
{
	pWnd->EnableWindow(bShow);
	if(bShow)
	{
		pWnd->ShowWindow(SW_SHOW);//��ʾ
		pWnd->CenterWindow();//������ʾ
	}
	else
		pWnd->ShowWindow(SW_HIDE);//����
}
void C��ǩ�ؼ�Dlg::DoTab(int nTab)
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



void C��ǩ�ؼ�Dlg::OnSelchangeTab1(NMHDR *pNMHDR, LRESULT *pResult)
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	int nSelect=m_Tab.GetCurSel();
	if(nSelect>=0)DoTab(nSelect);
	*pResult = 0;
}




void C��ǩ�ؼ�Dlg::OnDestroy()
{
	CDialogEx::OnDestroy();
	if(m_pTab1Dlg)delete m_pTab1Dlg;
	if(m_pTab2Dlg)delete m_pTab2Dlg;
	if(m_pTab3Dlg)delete m_pTab3Dlg;
	// TODO: �ڴ˴������Ϣ����������
}

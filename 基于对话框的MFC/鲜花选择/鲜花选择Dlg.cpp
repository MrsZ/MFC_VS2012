
// �ʻ�ѡ��Dlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "�ʻ�ѡ��.h"
#include "�ʻ�ѡ��Dlg.h"
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


// C�ʻ�ѡ��Dlg �Ի���



C�ʻ�ѡ��Dlg::C�ʻ�ѡ��Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(C�ʻ�ѡ��Dlg::IDD, pParent)
	, m_check1(false)
	, m_check2(false)
	, m_check3(false)
	, m_check4(false)
	, m_text(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void C�ʻ�ѡ��Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_text);
}

BEGIN_MESSAGE_MAP(C�ʻ�ѡ��Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_COMMAND(IDC_RADIO1, &C�ʻ�ѡ��Dlg::OnRadio1)
	ON_COMMAND(IDC_RADIO2, &C�ʻ�ѡ��Dlg::OnRadio2)
	ON_COMMAND(IDC_RADIO3, &C�ʻ�ѡ��Dlg::OnRadio3)
	ON_COMMAND(IDC_RADIO4, &C�ʻ�ѡ��Dlg::OnRadio4)
	ON_BN_CLICKED(IDC_CHECK1, &C�ʻ�ѡ��Dlg::OnClickedCheck1)
	ON_BN_CLICKED(IDC_CHECK2, &C�ʻ�ѡ��Dlg::OnClickedCheck2)
	ON_BN_CLICKED(IDC_CHECK3, &C�ʻ�ѡ��Dlg::OnClickedCheck3)
	ON_BN_CLICKED(IDC_CHECK4, &C�ʻ�ѡ��Dlg::OnClickedCheck4)
END_MESSAGE_MAP()


// C�ʻ�ѡ��Dlg ��Ϣ�������

BOOL C�ʻ�ѡ��Dlg::OnInitDialog()
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

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void C�ʻ�ѡ��Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void C�ʻ�ѡ��Dlg::OnPaint()
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
HCURSOR C�ʻ�ѡ��Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


int n=0;
void C�ʻ�ѡ��Dlg::OnRadio1()
{
	// TODO: �ڴ���������������
	n=1;
	m_check1=true;
	m_check2=true;
	m_check3=true;
	m_check4=true;
	m_text="��4�ֻ�����";
	UpdateData(false);
}


void C�ʻ�ѡ��Dlg::OnRadio2()
{
	// TODO: �ڴ���������������
	n=2;
	m_check1=true;
	m_check2=false;
	m_check3=true;
	m_check4=false;
	m_text="��2�ֻ�����";
	UpdateData(false);
}


void C�ʻ�ѡ��Dlg::OnRadio3()
{
	// TODO: �ڴ���������������
	n=3;
	m_check1=false;
	m_check2=true;
	m_check3=false;
	m_check4=true;
	m_text="��2�ֻ�����";
	UpdateData(false);
}


void C�ʻ�ѡ��Dlg::OnRadio4()
{
	// TODO: �ڴ���������������
	n=4;
	m_check1=true;
	m_check2=true;
	m_check3=true;
	m_check4=false;
	m_text="��3�ֻ�����";
	UpdateData(false);
}


void C�ʻ�ѡ��Dlg::OnClickedCheck1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
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
	m_text="�۸�Price��$100.00";
	m_check1=true;
	m_check2=false;
	m_check3=false;
	m_check4=false;
	UpdateData(false);
}


void C�ʻ�ѡ��Dlg::OnClickedCheck2()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
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
	m_text="�۸�Price��$110:00";
	m_check1=false;
	m_check2=true;
	m_check3=false;
	m_check4=false;
	UpdateData(false);
}


void C�ʻ�ѡ��Dlg::OnClickedCheck3()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
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
	m_text="�۸�Price:$130.00";
	m_check1=false;
	m_check2=false;
	m_check2=true;
	m_check4=false;
	UpdateData(false);
}


void C�ʻ�ѡ��Dlg::OnClickedCheck4()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
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
	m_text="�۸�Price:$150.00";
	m_check1=false;
	m_check2=false;
	m_check2=false;
	m_check4=true;
	UpdateData(false);
}

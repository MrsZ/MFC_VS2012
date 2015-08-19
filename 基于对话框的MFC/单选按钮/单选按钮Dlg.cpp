
// ��ѡ��ťDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "��ѡ��ť.h"
#include "��ѡ��ťDlg.h"
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


// C��ѡ��ťDlg �Ի���



C��ѡ��ťDlg::C��ѡ��ťDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(C��ѡ��ťDlg::IDD, pParent)
	, m_text1(_T(""))
	, m_text2(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void C��ѡ��ťDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_text1);
	DDX_Text(pDX, IDC_EDIT2, m_text2);
}

BEGIN_MESSAGE_MAP(C��ѡ��ťDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_COMMAND(IDC_RADIO1, &C��ѡ��ťDlg::OnRadio1)
	ON_COMMAND(IDC_RADIO2, &C��ѡ��ťDlg::OnRadio2)
	ON_COMMAND(IDC_RADIO3, &C��ѡ��ťDlg::OnRadio3)
	ON_BN_CLICKED(IDC_RADIO4, &C��ѡ��ťDlg::OnClickedRadio4)
	ON_COMMAND(IDC_RADIO5, &C��ѡ��ťDlg::OnRadio5)
	ON_COMMAND(IDC_RADIO6, &C��ѡ��ťDlg::OnRadio6)
END_MESSAGE_MAP()


// C��ѡ��ťDlg ��Ϣ�������

BOOL C��ѡ��ťDlg::OnInitDialog()
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

void C��ѡ��ťDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void C��ѡ��ťDlg::OnPaint()
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
HCURSOR C��ѡ��ťDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void C��ѡ��ťDlg::OnRadio1()
{
	// TODO: �ڴ���������������
	m_text1="��ѡ���˵�һ����ѡ��ť";
	UpdateData(false);
}


void C��ѡ��ťDlg::OnRadio2()
{
	// TODO: �ڴ���������������
	m_text1="��ѡ���˵ڶ�����ѡ��ť";
	UpdateData(false);
}


void C��ѡ��ťDlg::OnRadio3()
{
	// TODO: �ڴ���������������
	m_text1="��ѡ���˵�������ѡ��ť";
	UpdateData(false);
}


void C��ѡ��ťDlg::OnClickedRadio4()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	m_text2="��ѡ���˵�ѡ��ť4";
	UpdateData(false);
}


void C��ѡ��ťDlg::OnRadio5()
{
	// TODO: �ڴ���������������
	m_text2="��ѡ���˵�ѡ��ť5";
	UpdateData(false);
}


void C��ѡ��ťDlg::OnRadio6()
{
	// TODO: �ڴ���������������
	m_text2="��ѡ���˵�ѡ��ť6";
	UpdateData(false);
}

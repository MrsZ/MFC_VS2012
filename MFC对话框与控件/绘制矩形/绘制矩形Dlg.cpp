
// ���ƾ���Dlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "���ƾ���.h"
#include "���ƾ���Dlg.h"
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


// C���ƾ���Dlg �Ի���



C���ƾ���Dlg::C���ƾ���Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(C���ƾ���Dlg::IDD, pParent)
	, m_Length(0)
	, m_Width(0)
	, m_LineWidth(0)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void C���ƾ���Dlg::DoDataExchange(CDataExchange* pDX)
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

BEGIN_MESSAGE_MAP(C���ƾ���Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_APPLY, &C���ƾ���Dlg::OnClickedApply)
	ON_BN_CLICKED(EXITBUTTON, &C���ƾ���Dlg::OnClickedExitbutton)
	ON_WM_HSCROLL()
END_MESSAGE_MAP()


// C���ƾ���Dlg ��Ϣ�������

BOOL C���ƾ���Dlg::OnInitDialog()
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
	m_WidthSpin.SetRange(10,100);
	m_WidthSpin.SetPos(0);
	m_LengthSpin.SetRange(10,100);
	m_LengthSpin.SetPos(0);
	m_LineWidthSlider.SetRange(1,10);
	m_LineWidthSlider.SetPos(0);
	m_LineWidthSlider.SetTicFreq(1);//���û�����̶ȱ�ߣ�ÿһ����λһ�����
	SetDlgItemText(IDC_LINEWIDTH,"�߿�:1");
	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void C���ƾ���Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void C���ƾ���Dlg::OnPaint()
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
HCURSOR C���ƾ���Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void C���ƾ���Dlg::OnClickedApply()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData();
	Invalidate();//ʹ�û���ͼ����Ч��������ϴλ���ͼ
	UpdateWindow();//ˢ���û���ͼ����
	CClientDC dc(this);
	CPen mypen;
	mypen.CreatePen(PS_SOLID,m_LineWidth,RGB(255,0,0));//��������
	CPen *pOldpen=dc.SelectObject(&mypen);//�����ʽ����豸����
	dc.Rectangle(70,10,150+m_Length,30+m_Width);//��һ������
	dc.SelectObject(pOldpen);//�ָ�ԭ���Ļ���
}


void C���ƾ���Dlg::OnClickedExitbutton()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	OnOK();
}


void C���ƾ���Dlg::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	UpdateData();
	CString LineWidth;
	LineWidth.Format("�߿�:%d",m_LineWidth);
	SetDlgItemText(IDC_LINEWIDTH,LineWidth);
	CDialogEx::OnHScroll(nSBCode, nPos, pScrollBar);
}

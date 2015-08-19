
// ������Dlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "������.h"
#include "������Dlg.h"
#include "afxdialogex.h"
#include "math.h"
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


// C������Dlg �Ի���



C������Dlg::C������Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(C������Dlg::IDD, pParent)
	, m_display(_T(""))
{
	m_first=0.0;
	m_second=0.0;
	m_operator=_T("+");
	m_coff=1.0;
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void C������Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_DISPLAY, m_display);
}

BEGIN_MESSAGE_MAP(C������Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON0, &C������Dlg::OnClickedButton0)
	ON_BN_CLICKED(IDC_BUTTON1, &C������Dlg::OnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &C������Dlg::OnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &C������Dlg::OnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON4, &C������Dlg::OnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON5, &C������Dlg::OnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON6, &C������Dlg::OnClickedButton6)
	ON_BN_CLICKED(IDC_BUTTON7, &C������Dlg::OnClickedButton7)
	ON_BN_CLICKED(IDC_BUTTON8, &C������Dlg::OnClickedButton8)
	ON_BN_CLICKED(IDC_BUTTON9, &C������Dlg::OnClickedButton9)
	ON_BN_CLICKED(IDC_BUTTON_ADD, &C������Dlg::OnClickedButtonAdd)
	ON_BN_CLICKED(IDC_BUTTON_CLEAR, &C������Dlg::OnClickedButtonClear)
	ON_BN_CLICKED(IDC_BUTTON_DIV, &C������Dlg::OnClickedButtonDiv)
	ON_BN_CLICKED(IDC_BUTTON_EQUAL, &C������Dlg::OnClickedButtonEqual)
	ON_BN_CLICKED(IDC_BUTTON_MINUS, &C������Dlg::OnClickedButtonMinus)
	ON_BN_CLICKED(IDC_BUTTON_MUTIPLY, &C������Dlg::OnClickedButtonMutiply)
	ON_BN_CLICKED(IDC_BUTTON_POINT, &C������Dlg::OnClickedButtonPoint)
	ON_BN_CLICKED(IDC_BUTTON_RECIPROCAL, &C������Dlg::OnClickedButtonReciprocal)
	ON_BN_CLICKED(IDC_BUTTON_SIGN, &C������Dlg::OnClickedButtonSign)
	ON_BN_CLICKED(IDC_BUTTON_SQRT, &C������Dlg::OnClickedButtonSqrt)
END_MESSAGE_MAP()


// C������Dlg ��Ϣ�������

BOOL C������Dlg::OnInitDialog()
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

void C������Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void C������Dlg::OnPaint()
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
HCURSOR C������Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void C������Dlg::OnClickedButton0()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	if(m_coff==1.0)m_second=m_second*10+0;
	else
	{
		m_second=m_second+0*m_coff;
		m_coff*=0.1;
	}
	UpdateDisplay(m_second);
}


void C������Dlg::OnClickedButton1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	if(m_coff==1.0)m_second=m_second*10+1;
	else
	{
		m_second=m_second+1*m_coff;
		m_coff*=0.1;
	}
	UpdateDisplay(m_second);
}


void C������Dlg::OnClickedButton2()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	if(m_coff==1.0)m_second=m_second*10+2;
	else
	{
		m_second=m_second+2*m_coff;
		m_coff*=0.1;
	}
	UpdateDisplay(m_second);
}


void C������Dlg::OnClickedButton3()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	if(m_coff==1.0)m_second=m_second*10+3;
	else
	{
		m_second=m_second+3*m_coff;
		m_coff*=0.1;
	}
	UpdateDisplay(m_second);
}


void C������Dlg::OnClickedButton4()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	if(m_coff==1.0)m_second=m_second*10+4;
	else
	{
		m_second=m_second+4*m_coff;
		m_coff*=0.1;
	}
	UpdateDisplay(m_second);
}


void C������Dlg::OnClickedButton5()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	if(m_coff==1.0)m_second=m_second*10+5;
	else
	{
		m_second=m_second+5*m_coff;
		m_coff*=0.1;
	}
	UpdateDisplay(m_second);
}


void C������Dlg::OnClickedButton6()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	if(m_coff==1.0)m_second=m_second*10+6;
	else
	{
		m_second=m_second+6*m_coff;
		m_coff*=0.1;
	}
	UpdateDisplay(m_second);
}


void C������Dlg::OnClickedButton7()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	if(m_coff==1.0)m_second=m_second*10+7;
	else
	{
		m_second=m_second+7*m_coff;
		m_coff*=0.1;
	}
	UpdateDisplay(m_second);
}


void C������Dlg::OnClickedButton8()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	if(m_coff==1.0)m_second=m_second*10+8;
	else
	{
		m_second=m_second+8*m_coff;
		m_coff*=0.1;
	}
	UpdateDisplay(m_second);
}


void C������Dlg::OnClickedButton9()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	if(m_coff==1.0)m_second=m_second*10+9;
	else
	{
		m_second=m_second+9*m_coff;
		m_coff*=0.1;
	}
	UpdateDisplay(m_second);
}


void C������Dlg::OnClickedButtonAdd()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	Calculate();
	m_operator="+";
}


void C������Dlg::OnClickedButtonClear()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	m_first=0;
	m_second=0;
	m_operator="+";
	m_coff=1;
	UpdateDisplay(0.0);
}


void C������Dlg::OnClickedButtonDiv()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	Calculate();
	m_operator="/";
}


void C������Dlg::OnClickedButtonEqual()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	Calculate();
	m_first=0;
	m_operator="+";
}


void C������Dlg::OnClickedButtonMinus()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	Calculate();
	m_operator="-";
}


void C������Dlg::OnClickedButtonMutiply()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	Calculate();
	m_operator="*";
}


void C������Dlg::OnClickedButtonPoint()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	m_coff=0.1;
}


void C������Dlg::OnClickedButtonReciprocal()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	if(fabs(m_second)<=0.000001)
	{
		m_display="��������Ϊ0";
		UpdateData(false);
		return;
	}
	m_second=1/m_second;
	UpdateDisplay(m_second);
}


void C������Dlg::OnClickedButtonSign()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	m_second=-m_second;
	UpdateDisplay(m_second);
}


void C������Dlg::OnClickedButtonSqrt()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	m_second=sqrt(m_second);
	UpdateDisplay(m_second);
}


void C������Dlg::UpdateDisplay(double IVal)
{
	m_display.Format(_T("%f"),IVal);
	int i=m_display.GetLength();
	while(m_display.GetAt(i-1)=='0')
	{
		m_display.Delete(i-1,1);
		i--;
	}
	UpdateData(false);
}


void C������Dlg::Calculate(void)
{
	switch(m_operator.GetAt(0))
	{
	case '+':m_first+=m_second;break;
	case '-':m_first-=m_second;break;
	case '*':m_first*=m_second;break;
	case '/':if(fabs(m_second)<=0.000001)
			 {
				 m_display="��������Ϊ0";
				 UpdateData(false);
				 return;
			 }
			 m_first/=m_second;break;
	}
	m_second=0;
	m_coff=1;
	UpdateDisplay(m_first);
}

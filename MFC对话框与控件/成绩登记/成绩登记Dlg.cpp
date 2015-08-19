
// �ɼ��Ǽ�Dlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "�ɼ��Ǽ�.h"
#include "�ɼ��Ǽ�Dlg.h"
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


// C�ɼ��Ǽ�Dlg �Ի���



C�ɼ��Ǽ�Dlg::C�ɼ��Ǽ�Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(C�ɼ��Ǽ�Dlg::IDD, pParent)
	, m_strName(_T(""))
	, m_nEng(0)
	, m_nMat(0)
	, m_nCom(0)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void C�ɼ��Ǽ�Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST, m_List);
	DDX_Text(pDX, IDC_NAME, m_strName);
	DDV_MaxChars(pDX, m_strName, 20);
	DDX_Text(pDX, IDC_ENG, m_nEng);
	DDX_Text(pDX, IDC_MAT, m_nMat);
	DDX_Text(pDX, IDC_COM, m_nCom);
}

BEGIN_MESSAGE_MAP(C�ɼ��Ǽ�Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_ADD, &C�ɼ��Ǽ�Dlg::OnClickedAdd)
	ON_BN_CLICKED(IDC_DEL, &C�ɼ��Ǽ�Dlg::OnClickedDel)
	ON_LBN_SELCHANGE(IDC_LIST, &C�ɼ��Ǽ�Dlg::OnSelchangeList)
	ON_WM_DESTROY()
END_MESSAGE_MAP()


// C�ɼ��Ǽ�Dlg ��Ϣ�������

BOOL C�ɼ��Ǽ�Dlg::OnInitDialog()
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

void C�ɼ��Ǽ�Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void C�ɼ��Ǽ�Dlg::OnPaint()
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
HCURSOR C�ɼ��Ǽ�Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void C�ɼ��Ǽ�Dlg::OnClickedAdd()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(true);
	if(m_strName.IsEmpty())
	{
		MessageBox("��������Ϊ��");
		return;
	}
	m_strName.TrimLeft();
	m_strName.TrimRight();
	if((m_List.FindString(-1,m_strName))!=LB_ERR)
	{
		MessageBox("�б����������ͬ���֣��������");
		return;
	}
	int nIndex=m_List.AddString(m_strName);
	SCORE data;
	data.scoreE=m_nEng;
	data.scoreM=m_nMat;
	data.scoreC=m_nCom;
	m_List.SetItemDataPtr(nIndex,new SCORE(data));
}


void C�ɼ��Ǽ�Dlg::OnClickedDel()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	int nIndex=m_List.GetCurSel();
	if(nIndex!=LB_ERR)
	{
		m_List.DeleteString(nIndex);
		m_strName.Empty();
		m_nEng=m_nMat=m_nCom=0;
		UpdateData(false);
	}
	else
		MessageBox("��ǰû��ѡ������б�����ʧ��");
}


void C�ɼ��Ǽ�Dlg::OnSelchangeList()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
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


void C�ɼ��Ǽ�Dlg::OnDestroy()
{
	for(int nIndex=m_List.GetCount()-1;nIndex>=0;nIndex--)
	{
		delete(SCORE *)m_List.GetItemDataPtr(nIndex);
	}
	CDialogEx::OnDestroy();

	// TODO: �ڴ˴������Ϣ����������
}

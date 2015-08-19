// ProgressDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "ʹ�ý�չ��.h"
#include "ProgressDlg.h"
#include "afxdialogex.h"


// CProgressDlg �Ի���

IMPLEMENT_DYNAMIC(CProgressDlg, CDialogEx)

CProgressDlg::CProgressDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CProgressDlg::IDD, pParent)
	, m_strPercent(_T(""))
{

}

CProgressDlg::~CProgressDlg()
{
}

void CProgressDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_STATIC_TEXT, m_strPercent);
	DDX_Control(pDX, IDC_PROGRESS1, m_Progress);
}


BEGIN_MESSAGE_MAP(CProgressDlg, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON_BACK, &CProgressDlg::OnClickedButtonBack)
	ON_BN_CLICKED(IDC_BUTTON_GOON, &CProgressDlg::OnClickedButtonGoon)
END_MESSAGE_MAP()


// CProgressDlg ��Ϣ�������


void CProgressDlg::UpdatePercentText(void)
{
	int nPos=m_Progress.GetPos();//��չ����ǰλ��
	int nLow,nUp;//�������ĩλ��
	m_Progress.GetRange(nLow,nUp);
	m_strPercent.Format("%4.0f%%",(float)nPos/(float)(nUp-nLow)*100);
	UpdateData(false);

}


void CProgressDlg::OnClickedButtonBack()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	int nPos=m_Progress.GetPos();
	int nLow,nUp;
	m_Progress.GetRange(nLow,nUp);
	nPos=nPos-5;
	if(nPos<nLow)nPos=nLow;
	m_Progress.SetPos(nPos);
	UpdatePercentText();
}


void CProgressDlg::OnClickedButtonGoon()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	m_Progress.StepIt();
	UpdatePercentText();
}


BOOL CProgressDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	m_Progress.SetRange(0,100);
	m_Progress.SetStep(5);
	m_Progress.SetPos(30);
	UpdatePercentText();
	return true;
}

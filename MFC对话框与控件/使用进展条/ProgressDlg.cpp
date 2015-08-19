// ProgressDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "使用进展条.h"
#include "ProgressDlg.h"
#include "afxdialogex.h"


// CProgressDlg 对话框

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


// CProgressDlg 消息处理程序


void CProgressDlg::UpdatePercentText(void)
{
	int nPos=m_Progress.GetPos();//进展条当前位置
	int nLow,nUp;//起初和最末位置
	m_Progress.GetRange(nLow,nUp);
	m_strPercent.Format("%4.0f%%",(float)nPos/(float)(nUp-nLow)*100);
	UpdateData(false);

}


void CProgressDlg::OnClickedButtonBack()
{
	// TODO: 在此添加控件通知处理程序代码
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
	// TODO: 在此添加控件通知处理程序代码
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

// CaddDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "学生记录.h"
#include "CaddDlg.h"
#include "afxdialogex.h"


// CaddDlg 对话框

IMPLEMENT_DYNAMIC(CaddDlg, CDialogEx)

CaddDlg::CaddDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CaddDlg::IDD, pParent)
	, m_strName(_T(""))
	, m_strID(_T(""))
	, m_feng(0)
	, m_fmat(0)
	, m_fcom(0)
{

}

CaddDlg::~CaddDlg()
{
}

void CaddDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_strName);
	DDV_MaxChars(pDX, m_strName, 20);
	DDX_Text(pDX, IDC_EDIT2, m_strID);
	DDV_MaxChars(pDX, m_strID, 20);
	DDX_Text(pDX, IDC_EDIT3, m_feng);
	DDX_Text(pDX, IDC_EDIT4, m_fmat);
	DDX_Text(pDX, IDC_EDIT5, m_fcom);
}


BEGIN_MESSAGE_MAP(CaddDlg, CDialogEx)
END_MESSAGE_MAP()


// CaddDlg 消息处理程序

// DlgIdentity.cpp : 实现文件
//

#include "stdafx.h"
#include "对话框与控件.h"
#include "DlgIdentity.h"
#include "afxdialogex.h"


// CDlgIdentity 对话框

IMPLEMENT_DYNAMIC(CDlgIdentity, CDialogEx)

CDlgIdentity::CDlgIdentity(CWnd* pParent /*=NULL*/)
	: CDialogEx(CDlgIdentity::IDD, pParent)
	, m_strUser(_T(""))
	, m_strPassword(_T(""))
{

}

CDlgIdentity::~CDlgIdentity()
{
}

void CDlgIdentity::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_USER, m_strUser);
	DDX_Text(pDX, IDC_EDIT_PASSWORD, m_strPassword);
}


BEGIN_MESSAGE_MAP(CDlgIdentity, CDialogEx)
END_MESSAGE_MAP()


// CDlgIdentity 消息处理程序

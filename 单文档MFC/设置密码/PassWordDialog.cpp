// PassWordDialog.cpp : 实现文件
//

#include "stdafx.h"
#include "设置密码.h"
#include "PassWordDialog.h"
#include "afxdialogex.h"


// CPassWordDialog 对话框

IMPLEMENT_DYNAMIC(CPassWordDialog, CDialogEx)

CPassWordDialog::CPassWordDialog(CWnd* pParent /*=NULL*/)
	: CDialogEx(CPassWordDialog::IDD, pParent)
	, m_password1(_T(""))
	, m_password2(_T(""))
{

}

CPassWordDialog::~CPassWordDialog()
{
}

void CPassWordDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_PASSWORD_EDIT1, m_password1);
	DDV_MaxChars(pDX, m_password1, 20);
	DDX_Text(pDX, IDC_PASSWORD_EDIT2, m_password2);
	DDV_MaxChars(pDX, m_password2, 20);
}


BEGIN_MESSAGE_MAP(CPassWordDialog, CDialogEx)
END_MESSAGE_MAP()


// CPassWordDialog 消息处理程序

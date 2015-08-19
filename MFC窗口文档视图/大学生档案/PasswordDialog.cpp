// PasswordDialog.cpp : 实现文件
//

#include "stdafx.h"
#include "大学生档案.h"
#include "PasswordDialog.h"
#include "afxdialogex.h"


// CPasswordDialog 对话框

IMPLEMENT_DYNAMIC(CPasswordDialog, CDialogEx)

CPasswordDialog::CPasswordDialog(CWnd* pParent /*=NULL*/)
	: CDialogEx(CPasswordDialog::IDD, pParent)
	, m_password1(_T(""))
	, m_password2(_T(""))
{

}

CPasswordDialog::~CPasswordDialog()
{
}

void CPasswordDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_PASSWORD_EDIT1, m_password1);
	DDX_Text(pDX, IDC_PASSWORD_EDIT2, m_password2);
}


BEGIN_MESSAGE_MAP(CPasswordDialog, CDialogEx)
END_MESSAGE_MAP()


// CPasswordDialog 消息处理程序

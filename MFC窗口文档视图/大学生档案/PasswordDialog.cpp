// PasswordDialog.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "��ѧ������.h"
#include "PasswordDialog.h"
#include "afxdialogex.h"


// CPasswordDialog �Ի���

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


// CPasswordDialog ��Ϣ�������

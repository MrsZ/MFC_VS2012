// PassWordDialog.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "��������.h"
#include "PassWordDialog.h"
#include "afxdialogex.h"


// CPassWordDialog �Ի���

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


// CPassWordDialog ��Ϣ�������

// InDlog.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "��ѧ������.h"
#include "InDlog.h"
#include "afxdialogex.h"


// CInDlog �Ի���

IMPLEMENT_DYNAMIC(CInDlog, CDialogEx)

CInDlog::CInDlog(CWnd* pParent /*=NULL*/)
	: CDialogEx(CInDlog::IDD, pParent)
	, m_num(_T(""))
{

}

CInDlog::~CInDlog()
{
}

void CInDlog::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_NUM, m_num);
}


BEGIN_MESSAGE_MAP(CInDlog, CDialogEx)
END_MESSAGE_MAP()


// CInDlog ��Ϣ�������

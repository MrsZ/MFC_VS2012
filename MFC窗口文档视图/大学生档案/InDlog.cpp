// InDlog.cpp : 实现文件
//

#include "stdafx.h"
#include "大学生档案.h"
#include "InDlog.h"
#include "afxdialogex.h"


// CInDlog 对话框

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


// CInDlog 消息处理程序

// MyDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "用Create函数创建控件.h"
#include "MyDlg.h"
#include "afxdialogex.h"


// CMyDlg 对话框

IMPLEMENT_DYNAMIC(CMyDlg, CDialogEx)

CMyDlg::CMyDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CMyDlg::IDD, pParent)
{

}

CMyDlg::~CMyDlg()
{
}

void CMyDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CMyDlg, CDialogEx)
END_MESSAGE_MAP()


// CMyDlg 消息处理程序


BOOL CMyDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();
//
//#5312
//
//	return TRUE;  // return TRUE unless you set the focus to a control
//#5313
//
//#5312
//
//	return TRUE;  // return TRUE unless you set the focus to a control
//#5313
//	// TODO:  在此添加额外的初始化
//
//	return TRUE;  // return TRUE unless you set the focus to a control
//#5313
//	return TRUE;  // return TRUE unless you set the focus to a control
//#5313
//	// 异常: OCX 属性页应返回 FALSE
	m_btnWnd=new CButton();
	m_btnWnd->Create("你好",WS_CHILD|WS_VISIBLE|BS_PUSHBUTTON,CRect(20,20,120,60),this,201);
	CFont *font =this->GetFont();
	m_btnWnd->SetFont(font);
	return true;
}

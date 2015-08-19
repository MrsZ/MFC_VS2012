// Tab1Dlg.cpp : 实现文件
//

#include "stdafx.h"
#include "标签控件.h"
#include "Tab1Dlg.h"
#include "afxdialogex.h"


// CTab1Dlg 对话框

IMPLEMENT_DYNAMIC(CTab1Dlg, CDialogEx)

CTab1Dlg::CTab1Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CTab1Dlg::IDD, pParent)
{

}

CTab1Dlg::~CTab1Dlg()
{
}

void CTab1Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CTab1Dlg, CDialogEx)
END_MESSAGE_MAP()


// CTab1Dlg 消息处理程序


BOOL CTab1Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	CheckRadioButton(IDC_RADIO_MAN,IDC_RADIO_WOMAN,IDC_RADIO_MAN);
	return true;
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
//	 TODO:  在此添加额外的初始化
//
//	return TRUE;  // return TRUE unless you set the focus to a control
//#5313
//	return TRUE;  // return TRUE unless you set the focus to a control
//#5313
//	 异常: OCX 属性页应返回 FALSE
}

// Tab3Dlg.cpp : 实现文件
//

#include "stdafx.h"
#include "标签控件.h"
#include "Tab3Dlg.h"
#include "afxdialogex.h"


// CTab3Dlg 对话框

IMPLEMENT_DYNAMIC(CTab3Dlg, CDialogEx)

CTab3Dlg::CTab3Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CTab3Dlg::IDD, pParent)
{

}

CTab3Dlg::~CTab3Dlg()
{
}

void CTab3Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CTab3Dlg, CDialogEx)
END_MESSAGE_MAP()


// CTab3Dlg 消息处理程序

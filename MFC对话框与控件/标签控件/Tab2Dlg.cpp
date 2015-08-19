// Tab2Dlg.cpp : 实现文件
//

#include "stdafx.h"
#include "标签控件.h"
#include "Tab2Dlg.h"
#include "afxdialogex.h"


// CTab2Dlg 对话框

IMPLEMENT_DYNAMIC(CTab2Dlg, CDialogEx)

CTab2Dlg::CTab2Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CTab2Dlg::IDD, pParent)
{

}

CTab2Dlg::~CTab2Dlg()
{
}

void CTab2Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CTab2Dlg, CDialogEx)
END_MESSAGE_MAP()


// CTab2Dlg 消息处理程序

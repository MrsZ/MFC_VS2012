// DlgButton.cpp : 实现文件
//

#include "stdafx.h"
#include "对话框与控件.h"
#include "DlgButton.h"
#include "afxdialogex.h"


// CDlgButton 对话框

IMPLEMENT_DYNAMIC(CDlgButton, CDialogEx)

CDlgButton::CDlgButton(CWnd* pParent /*=NULL*/)
	: CDialogEx(CDlgButton::IDD, pParent)
{

}

CDlgButton::~CDlgButton()
{
}

void CDlgButton::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_BITMAP, m_cBmp);
}


BEGIN_MESSAGE_MAP(CDlgButton, CDialogEx)
	ON_COMMAND(IDC_RADIO_SPORT, &CDlgButton::OnRadioSport)
	ON_COMMAND(IDC_RADIO_MUSIC, &CDlgButton::OnRadioMusic)
END_MESSAGE_MAP()


// CDlgButton 消息处理程序


void CDlgButton::OnRadioSport()
{
	// TODO: 在此添加命令处理程序代码
	cBmp.DeleteObject();//删除底层对象
	cBmp.LoadBitmapA(IDB_BITMAP1);//装载位图
	m_cBmp.SetBitmap(HBITMAP(cBmp));//给静态控件设置位图
}


void CDlgButton::OnRadioMusic()
{
	// TODO: 在此添加命令处理程序代码
	cBmp.DeleteObject();//删除底层对象
	cBmp.LoadBitmapA(IDB_BITMAP2);//装载位图
	m_cBmp.SetBitmap(HBITMAP(cBmp));//给静态控件设置位图
}


BOOL CDlgButton::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	cBmp.LoadBitmapA(IDB_BITMAP1);
	m_cBmp.SetBitmap(HBITMAP(cBmp));
	return true;
}

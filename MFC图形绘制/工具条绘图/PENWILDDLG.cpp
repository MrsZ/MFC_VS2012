// PENWILDDLG.cpp : 实现文件
//

#include "stdafx.h"
#include "工具条绘图.h"
#include "PENWILDDLG.h"
#include "afxdialogex.h"
#include "resource.h"

// CPENWILDDLG 对话框

IMPLEMENT_DYNAMIC(CPENWILDDLG, CDialog)

CPENWILDDLG::CPENWILDDLG(CWnd* pParent /*=NULL*/)
	: CDialog(CPENWILDDLG::IDD, pParent)
	, m_penwild(0)
{

}

CPENWILDDLG::~CPENWILDDLG()
{
}

void CPENWILDDLG::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT_WILD, m_cpenwild);
	DDX_Text(pDX, IDC_EDIT_WILD, m_penwild);
	DDX_Control(pDX, IDC_SPIN_WILD, m_cwildspin);
}


BEGIN_MESSAGE_MAP(CPENWILDDLG, CDialog)
END_MESSAGE_MAP()


// CPENWILDDLG 消息处理程序

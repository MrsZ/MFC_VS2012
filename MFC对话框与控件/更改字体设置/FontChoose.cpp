// FontChoose.cpp : 实现文件
//

#include "stdafx.h"
#include "更改字体设置.h"
#include "FontChoose.h"
#include "afxdialogex.h"


// CFontChoose 对话框

IMPLEMENT_DYNAMIC(CFontChoose, CPropertyPage)

CFontChoose::CFontChoose()
	: CPropertyPage(CFontChoose::IDD)
{

}

CFontChoose::~CFontChoose()
{
}

void CFontChoose::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_FONT_LIST, m_lstFont);
}


BEGIN_MESSAGE_MAP(CFontChoose, CPropertyPage)
END_MESSAGE_MAP()


// CFontChoose 消息处理程序


BOOL CFontChoose::OnInitDialog()
{
	CPropertyPage::OnInitDialog();
	CFont font;
	font.CreatePointFont(120,"楷体_GB2312");
	m_lstFont.SetFont(&font);
	//添加四种字体名称
	m_lstFont.AddString("Courier");
	m_lstFont.AddString("Time New Roman");
	m_lstFont.AddString("Arial");
	m_lstFont.AddString("楷体_GB2312");

	//设置列表框初始选中的字体为第一种字体
	m_lstFont.SetCurSel(0);
	return true;
}

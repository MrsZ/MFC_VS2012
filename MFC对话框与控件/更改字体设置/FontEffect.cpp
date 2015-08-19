// FontEffect.cpp : 实现文件
//

#include "stdafx.h"
#include "更改字体设置.h"
#include "FontEffect.h"
#include "afxdialogex.h"


// CFontEffect 对话框

IMPLEMENT_DYNAMIC(CFontEffect, CPropertyPage)

CFontEffect::CFontEffect()
	: CPropertyPage(CFontEffect::IDD)
	, m_bBold(FALSE)
	, m_bItalic(FALSE)
{

}

CFontEffect::~CFontEffect()
{
}

void CFontEffect::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
	DDX_Check(pDX, IDC_BOLD, m_bBold);
	DDX_Check(pDX, IDC_ITALIC, m_bItalic);
}


BEGIN_MESSAGE_MAP(CFontEffect, CPropertyPage)
END_MESSAGE_MAP()


// CFontEffect 消息处理程序

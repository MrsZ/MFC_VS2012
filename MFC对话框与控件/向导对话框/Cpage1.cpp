// Cpage1.cpp : 实现文件
//

#include "stdafx.h"
#include "向导对话框.h"
#include "Cpage1.h"
#include "afxdialogex.h"


// Cpage1 对话框

IMPLEMENT_DYNAMIC(Cpage1, CPropertyPage)

Cpage1::Cpage1()
	: CPropertyPage(Cpage1::IDD)
{

}

Cpage1::~Cpage1()
{
}

void Cpage1::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(Cpage1, CPropertyPage)
END_MESSAGE_MAP()


// Cpage1 消息处理程序


BOOL Cpage1::OnSetActive()
{
	// TODO: 在此添加专用代码和/或调用基类
	CPropertySheet *pSheet=(CPropertySheet *)GetParent();
	ASSERT_KINDOF(CPropertySheet,pSheet);
	pSheet->SetWizardButtons(PSWIZB_NEXT);
	return CPropertyPage::OnSetActive();
}

// Cpage2.cpp : 实现文件
//

#include "stdafx.h"
#include "向导对话框.h"
#include "Cpage2.h"
#include "afxdialogex.h"


// Cpage2 对话框

IMPLEMENT_DYNAMIC(Cpage2, CPropertyPage)

Cpage2::Cpage2()
	: CPropertyPage(Cpage2::IDD)
{

}

Cpage2::~Cpage2()
{
}

void Cpage2::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(Cpage2, CPropertyPage)
END_MESSAGE_MAP()


// Cpage2 消息处理程序


BOOL Cpage2::OnSetActive()
{
	// TODO: 在此添加专用代码和/或调用基类
	//获得属性单的指针
	CPropertySheet *pSheet=(CPropertySheet *)GetParent();
	//测试获取的指针
	ASSERT_KINDOF(CPropertySheet,pSheet);
	pSheet->SetWizardButtons(PSWIZB_NEXT|PSWIZB_BACK);
	return CPropertyPage::OnSetActive();
}

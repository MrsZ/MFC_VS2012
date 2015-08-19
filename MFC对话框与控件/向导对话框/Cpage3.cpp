// Cpage3.cpp : 实现文件
//

#include "stdafx.h"
#include "向导对话框.h"
#include "Cpage3.h"
#include "afxdialogex.h"


// Cpage3 对话框

IMPLEMENT_DYNAMIC(Cpage3, CPropertyPage)

Cpage3::Cpage3()
	: CPropertyPage(Cpage3::IDD)
{

}

Cpage3::~Cpage3()
{
}

void Cpage3::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(Cpage3, CPropertyPage)
END_MESSAGE_MAP()


// Cpage3 消息处理程序


BOOL Cpage3::OnSetActive()
{
	// TODO: 在此添加专用代码和/或调用基类
	//获得属性单的指针
	CPropertySheet *pSheet=(CPropertySheet *)GetParent();
	//测试获取的指针
	ASSERT_KINDOF(CPropertySheet,pSheet);
	pSheet->SetWizardButtons(PSWIZB_FINISH|PSWIZB_BACK);
	return CPropertyPage::OnSetActive();
}

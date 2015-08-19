// Cpage1.cpp : 实现文件
//

#include "stdafx.h"
#include "创建属性表.h"
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
	DDX_Control(pDX, IDC_PROGRESS, m_progress);
}


BEGIN_MESSAGE_MAP(Cpage1, CPropertyPage)
	ON_BN_CLICKED(IDC_STEP, &Cpage1::OnClickedStep)
END_MESSAGE_MAP()


// Cpage1 消息处理程序


BOOL Cpage1::OnInitDialog()
{
	CPropertyPage::OnInitDialog();
	m_progress.SetRange(1,100);
	m_progress.SetStep(15);
	m_progress.SetPos(30);
	return true;
}


void Cpage1::OnClickedStep()
{
	// TODO: 在此添加控件通知处理程序代码
	m_progress.StepIt();
}

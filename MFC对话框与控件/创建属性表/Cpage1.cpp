// Cpage1.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "�������Ա�.h"
#include "Cpage1.h"
#include "afxdialogex.h"


// Cpage1 �Ի���

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


// Cpage1 ��Ϣ�������


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
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	m_progress.StepIt();
}

// Cpage1.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "�򵼶Ի���.h"
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
}


BEGIN_MESSAGE_MAP(Cpage1, CPropertyPage)
END_MESSAGE_MAP()


// Cpage1 ��Ϣ�������


BOOL Cpage1::OnSetActive()
{
	// TODO: �ڴ����ר�ô����/����û���
	CPropertySheet *pSheet=(CPropertySheet *)GetParent();
	ASSERT_KINDOF(CPropertySheet,pSheet);
	pSheet->SetWizardButtons(PSWIZB_NEXT);
	return CPropertyPage::OnSetActive();
}

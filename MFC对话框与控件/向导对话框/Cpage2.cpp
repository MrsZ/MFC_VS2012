// Cpage2.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "�򵼶Ի���.h"
#include "Cpage2.h"
#include "afxdialogex.h"


// Cpage2 �Ի���

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


// Cpage2 ��Ϣ�������


BOOL Cpage2::OnSetActive()
{
	// TODO: �ڴ����ר�ô����/����û���
	//������Ե���ָ��
	CPropertySheet *pSheet=(CPropertySheet *)GetParent();
	//���Ի�ȡ��ָ��
	ASSERT_KINDOF(CPropertySheet,pSheet);
	pSheet->SetWizardButtons(PSWIZB_NEXT|PSWIZB_BACK);
	return CPropertyPage::OnSetActive();
}

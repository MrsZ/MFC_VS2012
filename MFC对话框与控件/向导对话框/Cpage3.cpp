// Cpage3.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "�򵼶Ի���.h"
#include "Cpage3.h"
#include "afxdialogex.h"


// Cpage3 �Ի���

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


// Cpage3 ��Ϣ�������


BOOL Cpage3::OnSetActive()
{
	// TODO: �ڴ����ר�ô����/����û���
	//������Ե���ָ��
	CPropertySheet *pSheet=(CPropertySheet *)GetParent();
	//���Ի�ȡ��ָ��
	ASSERT_KINDOF(CPropertySheet,pSheet);
	pSheet->SetWizardButtons(PSWIZB_FINISH|PSWIZB_BACK);
	return CPropertyPage::OnSetActive();
}

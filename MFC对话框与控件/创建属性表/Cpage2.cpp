// Cpage2.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "�������Ա�.h"
#include "Cpage2.h"
#include "afxdialogex.h"


// Cpage2 �Ի���

IMPLEMENT_DYNAMIC(Cpage2, CPropertyPage)

Cpage2::Cpage2()
	: CPropertyPage(Cpage2::IDD)
	, m_red(0)
{

}

Cpage2::~Cpage2()
{
}

void Cpage2::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
	DDX_Radio(pDX, IDC_RED, m_red);
}


BEGIN_MESSAGE_MAP(Cpage2, CPropertyPage)
END_MESSAGE_MAP()


// Cpage2 ��Ϣ�������

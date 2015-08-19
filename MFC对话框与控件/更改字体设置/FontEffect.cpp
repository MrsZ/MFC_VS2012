// FontEffect.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "������������.h"
#include "FontEffect.h"
#include "afxdialogex.h"


// CFontEffect �Ի���

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


// CFontEffect ��Ϣ�������

// FontSize.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "������������.h"
#include "FontSize.h"
#include "afxdialogex.h"


// CFontSize �Ի���

IMPLEMENT_DYNAMIC(CFontSize, CPropertyPage)

CFontSize::CFontSize()
	: CPropertyPage(CFontSize::IDD)
	, m_nHeight(10)
	, m_nWidth(10)
{

}

CFontSize::~CFontSize()
{
}

void CFontSize::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_FONT_HEIGHT, m_nHeight);
	DDX_Text(pDX, IDC_FONT_WIDTH, m_nWidth);
}


BEGIN_MESSAGE_MAP(CFontSize, CPropertyPage)
END_MESSAGE_MAP()


// CFontSize ��Ϣ�������

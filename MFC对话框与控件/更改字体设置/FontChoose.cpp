// FontChoose.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "������������.h"
#include "FontChoose.h"
#include "afxdialogex.h"


// CFontChoose �Ի���

IMPLEMENT_DYNAMIC(CFontChoose, CPropertyPage)

CFontChoose::CFontChoose()
	: CPropertyPage(CFontChoose::IDD)
{

}

CFontChoose::~CFontChoose()
{
}

void CFontChoose::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_FONT_LIST, m_lstFont);
}


BEGIN_MESSAGE_MAP(CFontChoose, CPropertyPage)
END_MESSAGE_MAP()


// CFontChoose ��Ϣ�������


BOOL CFontChoose::OnInitDialog()
{
	CPropertyPage::OnInitDialog();
	CFont font;
	font.CreatePointFont(120,"����_GB2312");
	m_lstFont.SetFont(&font);
	//���������������
	m_lstFont.AddString("Courier");
	m_lstFont.AddString("Time New Roman");
	m_lstFont.AddString("Arial");
	m_lstFont.AddString("����_GB2312");

	//�����б���ʼѡ�е�����Ϊ��һ������
	m_lstFont.SetCurSel(0);
	return true;
}

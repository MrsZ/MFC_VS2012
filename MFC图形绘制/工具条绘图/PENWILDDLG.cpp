// PENWILDDLG.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "��������ͼ.h"
#include "PENWILDDLG.h"
#include "afxdialogex.h"
#include "resource.h"

// CPENWILDDLG �Ի���

IMPLEMENT_DYNAMIC(CPENWILDDLG, CDialog)

CPENWILDDLG::CPENWILDDLG(CWnd* pParent /*=NULL*/)
	: CDialog(CPENWILDDLG::IDD, pParent)
	, m_penwild(0)
{

}

CPENWILDDLG::~CPENWILDDLG()
{
}

void CPENWILDDLG::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT_WILD, m_cpenwild);
	DDX_Text(pDX, IDC_EDIT_WILD, m_penwild);
	DDX_Control(pDX, IDC_SPIN_WILD, m_cwildspin);
}


BEGIN_MESSAGE_MAP(CPENWILDDLG, CDialog)
END_MESSAGE_MAP()


// CPENWILDDLG ��Ϣ�������

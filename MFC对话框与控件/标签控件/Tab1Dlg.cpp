// Tab1Dlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "��ǩ�ؼ�.h"
#include "Tab1Dlg.h"
#include "afxdialogex.h"


// CTab1Dlg �Ի���

IMPLEMENT_DYNAMIC(CTab1Dlg, CDialogEx)

CTab1Dlg::CTab1Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CTab1Dlg::IDD, pParent)
{

}

CTab1Dlg::~CTab1Dlg()
{
}

void CTab1Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CTab1Dlg, CDialogEx)
END_MESSAGE_MAP()


// CTab1Dlg ��Ϣ�������


BOOL CTab1Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	CheckRadioButton(IDC_RADIO_MAN,IDC_RADIO_WOMAN,IDC_RADIO_MAN);
	return true;
//
//#5312
//
//	return TRUE;  // return TRUE unless you set the focus to a control
//#5313
//
//#5312
//
//	return TRUE;  // return TRUE unless you set the focus to a control
//#5313
//	 TODO:  �ڴ���Ӷ���ĳ�ʼ��
//
//	return TRUE;  // return TRUE unless you set the focus to a control
//#5313
//	return TRUE;  // return TRUE unless you set the focus to a control
//#5313
//	 �쳣: OCX ����ҳӦ���� FALSE
}

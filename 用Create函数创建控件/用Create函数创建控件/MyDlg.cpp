// MyDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "��Create���������ؼ�.h"
#include "MyDlg.h"
#include "afxdialogex.h"


// CMyDlg �Ի���

IMPLEMENT_DYNAMIC(CMyDlg, CDialogEx)

CMyDlg::CMyDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CMyDlg::IDD, pParent)
{

}

CMyDlg::~CMyDlg()
{
}

void CMyDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CMyDlg, CDialogEx)
END_MESSAGE_MAP()


// CMyDlg ��Ϣ�������


BOOL CMyDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();
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
//	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
//
//	return TRUE;  // return TRUE unless you set the focus to a control
//#5313
//	return TRUE;  // return TRUE unless you set the focus to a control
//#5313
//	// �쳣: OCX ����ҳӦ���� FALSE
	m_btnWnd=new CButton();
	m_btnWnd->Create("���",WS_CHILD|WS_VISIBLE|BS_PUSHBUTTON,CRect(20,20,120,60),this,201);
	CFont *font =this->GetFont();
	m_btnWnd->SetFont(font);
	return true;
}

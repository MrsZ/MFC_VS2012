// InputDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "����ɼ�.h"
#include "InputDlg.h"
#include "afxdialogex.h"


// CInputDlg �Ի���

IMPLEMENT_DYNAMIC(CInputDlg, CDialogEx)

CInputDlg::CInputDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CInputDlg::IDD, pParent)
	, m_strName(_T(""))
	, m_strNo(_T(""))
	, m_fSeng(0)
	, m_fSmat(0)
	, m_fScom(0)
{

}

CInputDlg::~CInputDlg()
{
}

void CInputDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_NAME, m_strName);
	DDV_MaxChars(pDX, m_strName, 20);
	DDX_Text(pDX, IDC_EDIT_NO, m_strNo);
	DDV_MaxChars(pDX, m_strNo, 20);
	DDX_Text(pDX, IDC_EDIT_SENG, m_fSeng);
	DDX_Control(pDX, IDC_SPIN_SENG, m_spinSeng);
	DDX_Text(pDX, IDC_EDIT_SMAT, m_fSmat);
	DDX_Control(pDX, IDC_SPIN_SMAT, m_spinSmat);
	DDX_Text(pDX, IDC_EDIT_SCOM, m_fScom);
	DDX_Control(pDX, IDC_SPIN_SCOM, m_spinScom);
}


BEGIN_MESSAGE_MAP(CInputDlg, CDialogEx)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN_SENG, &CInputDlg::OnDeltaposSpinSeng)
END_MESSAGE_MAP()


// CInputDlg ��Ϣ�������


BOOL CInputDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	m_spinSeng.SetRange(0,100);
	m_spinSmat.SetRange(0,100);
	m_spinScom.SetRange(0,100);
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
//	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
//
//	return TRUE;  // return TRUE unless you set the focus to a control
//#5313
//	return TRUE;  // return TRUE unless you set the focus to a control
//#5313
//	// �쳣: OCX ����ҳӦ���� FALSE
}


void CInputDlg::OnDeltaposSpinSeng(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);
	
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(true);
	m_fSeng+=(float)pNMUpDown->iDelta*0.5f;
	if(m_fSeng<0)m_fSeng=0.0f;
	if(m_fSeng>100)m_fSeng=100.0f;
	UpdateData(false);
	*pResult = 0;
}

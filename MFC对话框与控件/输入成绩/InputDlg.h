#pragma once
#include "afxcmn.h"


// CInputDlg �Ի���

class CInputDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CInputDlg)

public:
	CInputDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CInputDlg();

// �Ի�������
	enum { IDD = IDD_INPUT };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CString m_strName;
	CString m_strNo;
	float m_fSeng;
	CSpinButtonCtrl m_spinSeng;
	float m_fSmat;
	CSpinButtonCtrl m_spinSmat;
	float m_fScom;
	CSpinButtonCtrl m_spinScom;
	virtual BOOL OnInitDialog();
	afx_msg void OnDeltaposSpinSeng(NMHDR *pNMHDR, LRESULT *pResult);
};

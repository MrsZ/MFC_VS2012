#pragma once
#include "afxcmn.h"


// CInputDlg 对话框

class CInputDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CInputDlg)

public:
	CInputDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CInputDlg();

// 对话框数据
	enum { IDD = IDD_INPUT };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

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

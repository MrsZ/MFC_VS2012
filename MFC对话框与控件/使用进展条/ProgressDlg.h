#pragma once
#include "afxcmn.h"


// CProgressDlg 对话框

class CProgressDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CProgressDlg)

public:
	CProgressDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CProgressDlg();

// 对话框数据
	enum { IDD = IDD_PROGRESS };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CString m_strPercent;
	CProgressCtrl m_Progress;
	void UpdatePercentText(void);
	afx_msg void OnClickedButtonBack();
	afx_msg void OnClickedButtonGoon();
	virtual BOOL OnInitDialog();
};

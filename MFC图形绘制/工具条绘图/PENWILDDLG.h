#pragma once
#include "afxwin.h"
#include "afxcmn.h"


// CPENWILDDLG 对话框

class CPENWILDDLG : public CDialog
{
	DECLARE_DYNAMIC(CPENWILDDLG)

public:
	CPENWILDDLG(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CPENWILDDLG();

// 对话框数据
	enum { IDD = IDD_DIALOG_WILD };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CEdit m_cpenwild;
	int m_penwild;
	CSpinButtonCtrl m_cwildspin;
};

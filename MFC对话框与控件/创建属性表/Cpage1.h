#pragma once
#include "afxcmn.h"
#include "resource.h"

// Cpage1 �Ի���

class Cpage1 : public CPropertyPage
{
	DECLARE_DYNAMIC(Cpage1)

public:
	Cpage1();
	virtual ~Cpage1();

// �Ի�������
	enum { IDD = IDD_PROGRESSDLG1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CProgressCtrl m_progress;
	virtual BOOL OnInitDialog();
	afx_msg void OnClickedStep();
};

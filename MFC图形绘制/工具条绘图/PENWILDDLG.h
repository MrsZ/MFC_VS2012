#pragma once
#include "afxwin.h"
#include "afxcmn.h"


// CPENWILDDLG �Ի���

class CPENWILDDLG : public CDialog
{
	DECLARE_DYNAMIC(CPENWILDDLG)

public:
	CPENWILDDLG(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CPENWILDDLG();

// �Ի�������
	enum { IDD = IDD_DIALOG_WILD };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CEdit m_cpenwild;
	int m_penwild;
	CSpinButtonCtrl m_cwildspin;
};

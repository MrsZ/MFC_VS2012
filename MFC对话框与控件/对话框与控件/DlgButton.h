#pragma once
#include "afxwin.h"


// CDlgButton �Ի���

class CDlgButton : public CDialogEx
{
	DECLARE_DYNAMIC(CDlgButton)

public:
	CDlgButton(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CDlgButton();

// �Ի�������
	enum { IDD = IDD_BUTTONTEST };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CStatic m_cBmp;
	CBitmap cBmp;
	afx_msg void OnRadioSport();
	afx_msg void OnRadioMusic();
	virtual BOOL OnInitDialog();
};

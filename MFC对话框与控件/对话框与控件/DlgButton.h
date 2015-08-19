#pragma once
#include "afxwin.h"


// CDlgButton 对话框

class CDlgButton : public CDialogEx
{
	DECLARE_DYNAMIC(CDlgButton)

public:
	CDlgButton(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CDlgButton();

// 对话框数据
	enum { IDD = IDD_BUTTONTEST };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CStatic m_cBmp;
	CBitmap cBmp;
	afx_msg void OnRadioSport();
	afx_msg void OnRadioMusic();
	virtual BOOL OnInitDialog();
};

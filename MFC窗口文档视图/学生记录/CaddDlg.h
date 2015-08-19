#pragma once

#include "Resource.h"
// CaddDlg 对话框

class CaddDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CaddDlg)

public:
	CaddDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CaddDlg();

// 对话框数据
	enum { IDD = IDD_DIALOG};

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CString m_strName;
	CString m_strID;
	float m_feng;
	float m_fmat;
	float m_fcom;
};

#pragma once


// CDlgIdentity 对话框

class CDlgIdentity : public CDialogEx
{
	DECLARE_DYNAMIC(CDlgIdentity)

public:
	CDlgIdentity(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CDlgIdentity();

// 对话框数据
	enum { IDD = IDD_IDENTITY };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CString m_strUser;
	CString m_strPassword;
};

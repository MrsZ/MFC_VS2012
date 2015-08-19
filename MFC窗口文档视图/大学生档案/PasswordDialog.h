#pragma once


// CPasswordDialog 对话框

class CPasswordDialog : public CDialogEx
{
	DECLARE_DYNAMIC(CPasswordDialog)

public:
	CPasswordDialog(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CPasswordDialog();

// 对话框数据
	enum { IDD = IDD_PSAAWORD_DIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CString m_password1;
	CString m_password2;
};

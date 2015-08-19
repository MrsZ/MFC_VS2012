#pragma once


// CPassWordDialog 对话框

class CPassWordDialog : public CDialogEx
{
	DECLARE_DYNAMIC(CPassWordDialog)

public:
	CPassWordDialog(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CPassWordDialog();

// 对话框数据
	enum { IDD = IDD_PASSWORD_EDIT1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CString m_password1;
	CString m_password2;
};

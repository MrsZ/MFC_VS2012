#pragma once


// CPassWordDialog �Ի���

class CPassWordDialog : public CDialogEx
{
	DECLARE_DYNAMIC(CPassWordDialog)

public:
	CPassWordDialog(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CPassWordDialog();

// �Ի�������
	enum { IDD = IDD_PASSWORD_EDIT1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CString m_password1;
	CString m_password2;
};

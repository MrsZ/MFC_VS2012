#pragma once


// CPasswordDialog �Ի���

class CPasswordDialog : public CDialogEx
{
	DECLARE_DYNAMIC(CPasswordDialog)

public:
	CPasswordDialog(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CPasswordDialog();

// �Ի�������
	enum { IDD = IDD_PSAAWORD_DIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CString m_password1;
	CString m_password2;
};

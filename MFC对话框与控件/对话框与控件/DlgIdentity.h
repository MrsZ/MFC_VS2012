#pragma once


// CDlgIdentity �Ի���

class CDlgIdentity : public CDialogEx
{
	DECLARE_DYNAMIC(CDlgIdentity)

public:
	CDlgIdentity(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CDlgIdentity();

// �Ի�������
	enum { IDD = IDD_IDENTITY };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CString m_strUser;
	CString m_strPassword;
};

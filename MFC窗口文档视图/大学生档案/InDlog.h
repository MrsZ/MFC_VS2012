#pragma once


// CInDlog �Ի���

class CInDlog : public CDialogEx
{
	DECLARE_DYNAMIC(CInDlog)

public:
	CInDlog(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CInDlog();

// �Ի�������
	enum { IDD = IDD_DIALOG1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CString m_num;
};

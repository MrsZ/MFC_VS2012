#pragma once


// CTab3Dlg �Ի���

class CTab3Dlg : public CDialogEx
{
	DECLARE_DYNAMIC(CTab3Dlg)

public:
	CTab3Dlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CTab3Dlg();

// �Ի�������
	enum { IDD = IDD_DIALOG3 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
};

#pragma once


// CTab2Dlg �Ի���

class CTab2Dlg : public CDialogEx
{
	DECLARE_DYNAMIC(CTab2Dlg)

public:
	CTab2Dlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CTab2Dlg();

// �Ի�������
	enum { IDD = IDD_DIALOG2 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
};

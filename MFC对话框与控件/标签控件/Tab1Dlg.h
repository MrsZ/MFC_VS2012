#pragma once


// CTab1Dlg �Ի���

class CTab1Dlg : public CDialogEx
{
	DECLARE_DYNAMIC(CTab1Dlg)

public:
	CTab1Dlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CTab1Dlg();

// �Ի�������
	enum { IDD = IDD_DIALOG1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
};

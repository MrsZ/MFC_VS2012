#pragma once
#include "afxwin.h"


// CDlgCombo �Ի���

class CDlgCombo : public CDialogEx
{
	DECLARE_DYNAMIC(CDlgCombo)

public:
	CDlgCombo(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CDlgCombo();

// �Ի�������
	enum { IDD = IDD_COMBOTEST };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CComboBox m_ComboBox;
	CString m_strCtrlName;
private:
	CWnd *pWndCtrl;//ָ��̬�����Ŀؼ�����
public:
	virtual BOOL OnInitDialog();
	afx_msg void OnDestroy();
	afx_msg void OnSelchangeComboControl();
};

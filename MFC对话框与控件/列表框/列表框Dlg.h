
// �б��Dlg.h : ͷ�ļ�
//

#pragma once
#include "afxwin.h"


// C�б��Dlg �Ի���
class C�б��Dlg : public CDialogEx
{
// ����
public:
	C�б��Dlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_MY_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CListBox m_NameList;
	CString m_strName;
	afx_msg void OnClickedAdd();
	afx_msg void OnClickedDelete();
	afx_msg void OnClickedExitbutton();
};


// ӳ��ؼ���ϢDlg.h : ͷ�ļ�
//

#pragma once
#include "afxwin.h"


// Cӳ��ؼ���ϢDlg �Ի���
class Cӳ��ؼ���ϢDlg : public CDialogEx
{
// ����
public:
	Cӳ��ؼ���ϢDlg(CWnd* pParent = NULL);	// ��׼���캯��

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
	afx_msg void OnClickedButton1();
	virtual BOOL OnCommand(WPARAM wParam, LPARAM lParam);
	afx_msg void OnBnClickedButton1();
	CButton m_MyBtn;
	CString m_strEdit;
};


// ����Ŀ¼Dlg.h : ͷ�ļ�
//

#pragma once
#include "afxcmn.h"


// C����Ŀ¼Dlg �Ի���
class C����Ŀ¼Dlg : public CDialogEx
{
// ����
public:
	C����Ŀ¼Dlg(CWnd* pParent = NULL);	// ��׼���캯��

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
	afx_msg void OnSelchangedTreeview(NMHDR *pNMHDR, LRESULT *pResult);
	CTreeCtrl m_TreeCtrl;
};

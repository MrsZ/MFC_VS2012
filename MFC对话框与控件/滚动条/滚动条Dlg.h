
// ������Dlg.h : ͷ�ļ�
//

#pragma once
#include "afxwin.h"


// C������Dlg �Ի���
class C������Dlg : public CDialogEx
{
// ����
public:
	C������Dlg(CWnd* pParent = NULL);	// ��׼���캯��
	BOOL m_bEditOK;

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
	int m_RValue;
	CScrollBar m_Scroll;
	afx_msg void OnChangeEdit1();
	void Draw(void);
	afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
};

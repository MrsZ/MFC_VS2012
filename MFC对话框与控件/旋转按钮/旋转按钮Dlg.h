
// ��ת��ťDlg.h : ͷ�ļ�
//

#pragma once
#include "afxcmn.h"
#include "afxwin.h"


// C��ת��ťDlg �Ի���
class C��ת��ťDlg : public CDialogEx
{
// ����
public:
	C��ת��ťDlg(CWnd* pParent = NULL);	// ��׼���캯��

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
	int m_length;
	CSpinButtonCtrl m_LengthSpin;
	int m_Width;
	CSpinButtonCtrl m_WidthSpin;
	CButton m_Room;
	afx_msg void OnClickedApply();
	afx_msg void OnClickedExitbutton();
};


// ��ѡ��ťDlg.h : ͷ�ļ�
//

#pragma once


// C��ѡ��ťDlg �Ի���
class C��ѡ��ťDlg : public CDialogEx
{
// ����
public:
	C��ѡ��ťDlg(CWnd* pParent = NULL);	// ��׼���캯��

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
	CString m_text1;
	afx_msg void OnRadio1();
	afx_msg void OnRadio2();
	afx_msg void OnRadio3();
	CString m_text2;
	afx_msg void OnClickedRadio4();
	afx_msg void OnRadio5();
	afx_msg void OnRadio6();
};

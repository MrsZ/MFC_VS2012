
// �ʻ�ѡ��Dlg.h : ͷ�ļ�
//

#pragma once


// C�ʻ�ѡ��Dlg �Ի���
class C�ʻ�ѡ��Dlg : public CDialogEx
{
// ����
public:
	C�ʻ�ѡ��Dlg(CWnd* pParent = NULL);	// ��׼���캯��

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
	bool m_check1;
	bool m_check2;
	bool m_check3;
	bool m_check4;
	CString m_text;
	afx_msg void OnRadio1();
	afx_msg void OnRadio2();
	afx_msg void OnRadio3();
	afx_msg void OnRadio4();
	afx_msg void OnClickedCheck1();
	afx_msg void OnClickedCheck2();
	afx_msg void OnClickedCheck3();
	afx_msg void OnClickedCheck4();
};

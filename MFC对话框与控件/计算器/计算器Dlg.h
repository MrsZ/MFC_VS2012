
// ������Dlg.h : ͷ�ļ�
//

#pragma once


// C������Dlg �Ի���
class C������Dlg : public CDialogEx
{
// ����
public:
	C������Dlg(CWnd* pParent = NULL);	// ��׼���캯��

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
	CString m_display;
	double m_first;//һ������ĵ�һ���������Լ�һ������Ľ��
	double m_second;//һ������ĵڶ���������
	double m_coff;//С�����ϵ��Ȩֵ
	CString m_operator;//���������
	afx_msg void OnClickedButton0();
	afx_msg void OnClickedButton1();
	afx_msg void OnClickedButton2();
	afx_msg void OnClickedButton3();
	afx_msg void OnClickedButton4();
	afx_msg void OnClickedButton5();
	afx_msg void OnClickedButton6();
	afx_msg void OnClickedButton7();
	afx_msg void OnClickedButton8();
	afx_msg void OnClickedButton9();
	afx_msg void OnClickedButtonAdd();
	afx_msg void OnClickedButtonClear();
	afx_msg void OnClickedButtonDiv();
	afx_msg void OnClickedButtonEqual();
	afx_msg void OnClickedButtonMinus();
	afx_msg void OnClickedButtonMutiply();
	afx_msg void OnClickedButtonPoint();
	afx_msg void OnClickedButtonReciprocal();
	afx_msg void OnClickedButtonSign();
	afx_msg void OnClickedButtonSqrt();
	void UpdateDisplay(double IVal);
	void Calculate(void);
};

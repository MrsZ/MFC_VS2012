
// ��ɫ����Dlg.h : ͷ�ļ�
//

#pragma once


// C��ɫ����Dlg �Ի���
class C��ɫ����Dlg : public CDialogEx
{
// ����
public:
	C��ɫ����Dlg(CWnd* pParent = NULL);	// ��׼���캯��

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
	int m_red;
	int m_green;
	int m_blue;
	int m_change;//�޸ı�־
	afx_msg void OnClickedApply();
	afx_msg void OnClickedExitbutton();
};

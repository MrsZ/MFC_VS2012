
// �ڿؼ��л�ͼDlg.h : ͷ�ļ�
//

#pragma once


// C�ڿؼ��л�ͼDlg �Ի���
class C�ڿؼ��л�ͼDlg : public CDialogEx
{
// ����
public:
	C�ڿؼ��л�ͼDlg(CWnd* pParent = NULL);	// ��׼���캯��

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
};

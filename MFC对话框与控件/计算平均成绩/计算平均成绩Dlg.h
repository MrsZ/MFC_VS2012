
// ����ƽ���ɼ�Dlg.h : ͷ�ļ�
//

#pragma once


// C����ƽ���ɼ�Dlg �Ի���
class C����ƽ���ɼ�Dlg : public CDialogEx
{
// ����
public:
	C����ƽ���ɼ�Dlg(CWnd* pParent = NULL);	// ��׼���캯��

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
	CString m_strAve;
	float m_nScore1;
	float m_nScore2;
	float m_nScore3;
	afx_msg void OnClickedButton1();
};

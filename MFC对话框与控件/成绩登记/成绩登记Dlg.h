
// �ɼ��Ǽ�Dlg.h : ͷ�ļ�
//

#pragma once
#include "afxwin.h"


// C�ɼ��Ǽ�Dlg �Ի���
class C�ɼ��Ǽ�Dlg : public CDialogEx
{
// ����
public:
	C�ɼ��Ǽ�Dlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_MY_DIALOG };

	struct SCORE
	{
		float scoreE;
		float scoreM;
		float scoreC;
	};

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
	CListBox m_List;
	CString m_strName;
	float m_nEng;
	float m_nMat;
	float m_nCom;
	afx_msg void OnClickedAdd();
	afx_msg void OnClickedDel();
	afx_msg void OnSelchangeList();
	afx_msg void OnDestroy();
};

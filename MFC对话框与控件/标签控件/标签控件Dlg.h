
// ��ǩ�ؼ�Dlg.h : ͷ�ļ�
//

#pragma once
#include "afxcmn.h"
#include "afxwin.h"
#include "tab3dlg.h"
#include "tab2dlg.h"
#include "tab1dlg.h"


// C��ǩ�ؼ�Dlg �Ի���
class C��ǩ�ؼ�Dlg : public CDialogEx
{
// ����
public:
	C��ǩ�ؼ�Dlg(CWnd* pParent = NULL);	// ��׼���캯��

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

	void SetDlgState(CWnd *pWnd,BOOL bShow);
	void DoTab(int nTab);
	CTabCtrl m_Tab;
	CImageList m_ImageList;
	CTab3Dlg *m_pTab3Dlg;
	CTab2Dlg *m_pTab2Dlg;
	CTab1Dlg *m_pTab1Dlg;
	afx_msg void OnSelchangeTab1(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnDestroy();
};


// 标签控件Dlg.h : 头文件
//

#pragma once
#include "afxcmn.h"
#include "afxwin.h"
#include "tab3dlg.h"
#include "tab2dlg.h"
#include "tab1dlg.h"


// C标签控件Dlg 对话框
class C标签控件Dlg : public CDialogEx
{
// 构造
public:
	C标签控件Dlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_MY_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
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

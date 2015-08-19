
// 滚动条Dlg.h : 头文件
//

#pragma once
#include "afxwin.h"


// C滚动条Dlg 对话框
class C滚动条Dlg : public CDialogEx
{
// 构造
public:
	C滚动条Dlg(CWnd* pParent = NULL);	// 标准构造函数
	BOOL m_bEditOK;

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
	int m_RValue;
	CScrollBar m_Scroll;
	afx_msg void OnChangeEdit1();
	void Draw(void);
	afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
};

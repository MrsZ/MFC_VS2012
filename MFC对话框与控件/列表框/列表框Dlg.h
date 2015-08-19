
// 列表框Dlg.h : 头文件
//

#pragma once
#include "afxwin.h"


// C列表框Dlg 对话框
class C列表框Dlg : public CDialogEx
{
// 构造
public:
	C列表框Dlg(CWnd* pParent = NULL);	// 标准构造函数

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
	CListBox m_NameList;
	CString m_strName;
	afx_msg void OnClickedAdd();
	afx_msg void OnClickedDelete();
	afx_msg void OnClickedExitbutton();
};

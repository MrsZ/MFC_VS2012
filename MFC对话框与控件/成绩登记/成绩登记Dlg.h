
// 成绩登记Dlg.h : 头文件
//

#pragma once
#include "afxwin.h"


// C成绩登记Dlg 对话框
class C成绩登记Dlg : public CDialogEx
{
// 构造
public:
	C成绩登记Dlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_MY_DIALOG };

	struct SCORE
	{
		float scoreE;
		float scoreM;
		float scoreC;
	};

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


// 单选按钮Dlg.h : 头文件
//

#pragma once


// C单选按钮Dlg 对话框
class C单选按钮Dlg : public CDialogEx
{
// 构造
public:
	C单选按钮Dlg(CWnd* pParent = NULL);	// 标准构造函数

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
	CString m_text1;
	afx_msg void OnRadio1();
	afx_msg void OnRadio2();
	afx_msg void OnRadio3();
	CString m_text2;
	afx_msg void OnClickedRadio4();
	afx_msg void OnRadio5();
	afx_msg void OnRadio6();
};


// 计算器Dlg.h : 头文件
//

#pragma once


// C计算器Dlg 对话框
class C计算器Dlg : public CDialogEx
{
// 构造
public:
	C计算器Dlg(CWnd* pParent = NULL);	// 标准构造函数

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
	CString m_display;
	double m_first;//一次运算的第一个操作数以及一次运算的结果
	double m_second;//一次运算的第二个操作数
	double m_coff;//小数点的系数权值
	CString m_operator;//运算操作数
	afx_msg void OnClickedButton0();
	afx_msg void OnClickedButton1();
	afx_msg void OnClickedButton2();
	afx_msg void OnClickedButton3();
	afx_msg void OnClickedButton4();
	afx_msg void OnClickedButton5();
	afx_msg void OnClickedButton6();
	afx_msg void OnClickedButton7();
	afx_msg void OnClickedButton8();
	afx_msg void OnClickedButton9();
	afx_msg void OnClickedButtonAdd();
	afx_msg void OnClickedButtonClear();
	afx_msg void OnClickedButtonDiv();
	afx_msg void OnClickedButtonEqual();
	afx_msg void OnClickedButtonMinus();
	afx_msg void OnClickedButtonMutiply();
	afx_msg void OnClickedButtonPoint();
	afx_msg void OnClickedButtonReciprocal();
	afx_msg void OnClickedButtonSign();
	afx_msg void OnClickedButtonSqrt();
	void UpdateDisplay(double IVal);
	void Calculate(void);
};

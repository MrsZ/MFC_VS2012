
// 绘制矩形Dlg.h : 头文件
//

#pragma once
#include "afxcmn.h"
#include "afxwin.h"


// C绘制矩形Dlg 对话框
class C绘制矩形Dlg : public CDialogEx
{
// 构造
public:
	C绘制矩形Dlg(CWnd* pParent = NULL);	// 标准构造函数

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
	int m_Length;
	CSpinButtonCtrl m_LengthSpin;
	int m_Width;
	CSpinButtonCtrl m_WidthSpin;
	CSliderCtrl m_LineWidthSlider;
	CButton m_Room;
	int m_LineWidth;
	afx_msg void OnClickedApply();
	afx_msg void OnClickedExitbutton();
	afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
};

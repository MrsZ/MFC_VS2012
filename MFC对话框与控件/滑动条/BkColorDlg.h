#pragma once
#include "afxcmn.h"


// CBkColorDlg 对话框

class CBkColorDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CBkColorDlg)

public:
	CBkColorDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CBkColorDlg();
	CBrush m_Brush;

// 对话框数据
	enum { IDD = IDD_COLOR };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	int q;
//	CSliderCtrl m_sliderRed;
	CSliderCtrl m_sliderBlue;
	int m_nBlue;
	CSliderCtrl m_sliderRed;
	int m_nRed;
	CSliderCtrl m_sliderGreen;
	int m_nGreen;
	virtual BOOL OnInitDialog();
	afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
};

#pragma once
#include "afxwin.h"


// CDlgCombo 对话框

class CDlgCombo : public CDialogEx
{
	DECLARE_DYNAMIC(CDlgCombo)

public:
	CDlgCombo(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CDlgCombo();

// 对话框数据
	enum { IDD = IDD_COMBOTEST };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CComboBox m_ComboBox;
	CString m_strCtrlName;
private:
	CWnd *pWndCtrl;//指向动态创建的控件对象
public:
	virtual BOOL OnInitDialog();
	afx_msg void OnDestroy();
	afx_msg void OnSelchangeComboControl();
};

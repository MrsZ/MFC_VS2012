#pragma once


// CTab2Dlg 对话框

class CTab2Dlg : public CDialogEx
{
	DECLARE_DYNAMIC(CTab2Dlg)

public:
	CTab2Dlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CTab2Dlg();

// 对话框数据
	enum { IDD = IDD_DIALOG2 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
};

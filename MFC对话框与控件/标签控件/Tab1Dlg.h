#pragma once


// CTab1Dlg 对话框

class CTab1Dlg : public CDialogEx
{
	DECLARE_DYNAMIC(CTab1Dlg)

public:
	CTab1Dlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CTab1Dlg();

// 对话框数据
	enum { IDD = IDD_DIALOG1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
};

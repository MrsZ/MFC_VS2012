#pragma once
#include "afxwin.h"

#include "resource.h"
// CFontChoose 对话框

class CFontChoose : public CPropertyPage
{
	DECLARE_DYNAMIC(CFontChoose)

public:
	CFontChoose();
	virtual ~CFontChoose();

// 对话框数据
	enum { IDD = IDD_FONT_CHOOSE };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CListBox m_lstFont;
	virtual BOOL OnInitDialog();
};

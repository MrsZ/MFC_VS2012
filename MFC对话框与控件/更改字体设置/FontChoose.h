#pragma once
#include "afxwin.h"

#include "resource.h"
// CFontChoose �Ի���

class CFontChoose : public CPropertyPage
{
	DECLARE_DYNAMIC(CFontChoose)

public:
	CFontChoose();
	virtual ~CFontChoose();

// �Ի�������
	enum { IDD = IDD_FONT_CHOOSE };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CListBox m_lstFont;
	virtual BOOL OnInitDialog();
};

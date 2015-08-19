#pragma once
#include "resource.h"

// CFontEffect 对话框

class CFontEffect : public CPropertyPage
{
	DECLARE_DYNAMIC(CFontEffect)

public:
	CFontEffect();
	virtual ~CFontEffect();

// 对话框数据
	enum { IDD = IDD_FONT_EFFECT };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	BOOL m_bBold;
	BOOL m_bItalic;
};

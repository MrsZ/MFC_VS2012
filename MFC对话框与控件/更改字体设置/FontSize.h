#pragma once

#include "resource.h"
// CFontSize 对话框

class CFontSize : public CPropertyPage
{
	DECLARE_DYNAMIC(CFontSize)

public:
	CFontSize();
	virtual ~CFontSize();

// 对话框数据
	enum { IDD = IDD_FONT_SIZE };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	UINT m_nHeight;
	UINT m_nWidth;
};

#pragma once

#include "resource.h"
// CFontSize �Ի���

class CFontSize : public CPropertyPage
{
	DECLARE_DYNAMIC(CFontSize)

public:
	CFontSize();
	virtual ~CFontSize();

// �Ի�������
	enum { IDD = IDD_FONT_SIZE };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	UINT m_nHeight;
	UINT m_nWidth;
};

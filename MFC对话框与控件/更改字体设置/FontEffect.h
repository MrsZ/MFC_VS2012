#pragma once
#include "resource.h"

// CFontEffect �Ի���

class CFontEffect : public CPropertyPage
{
	DECLARE_DYNAMIC(CFontEffect)

public:
	CFontEffect();
	virtual ~CFontEffect();

// �Ի�������
	enum { IDD = IDD_FONT_EFFECT };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	BOOL m_bBold;
	BOOL m_bItalic;
};

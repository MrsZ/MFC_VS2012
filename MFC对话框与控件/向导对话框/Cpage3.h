#pragma once
#include "resource.h"

// Cpage3 对话框

class Cpage3 : public CPropertyPage
{
	DECLARE_DYNAMIC(Cpage3)

public:
	Cpage3();
	virtual ~Cpage3();

// 对话框数据
	enum { IDD = IDD_STEP3 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnSetActive();
};

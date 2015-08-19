
// 一档多视View.h : C一档多视View 类的接口
//

#pragma once

#include "resource.h"
#include "afxcmn.h"

class C一档多视Doc;

class C一档多视View : public CFormView
{
protected: // 仅从序列化创建
	C一档多视View();
	DECLARE_DYNCREATE(C一档多视View)

public:
	enum{ IDD = IDD_MY_FORM };

// 特性
public:
	C一档多视Doc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
	virtual void OnInitialUpdate(); // 构造后第一次调用

// 实现
public:
	virtual ~C一档多视View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	int m_CoorX;
	int m_CoorY;
	CSpinButtonCtrl m_SpinX;
	CSpinButtonCtrl m_SpinY;
	bool m_bEditOK;

	afx_msg void OnChangeEdit();
	virtual void OnUpdate(CView* /*pSender*/, LPARAM /*lHint*/, CObject* /*pHint*/);
};

#ifndef _DEBUG  // 一档多视View.cpp 中的调试版本
inline C一档多视Doc* C一档多视View::GetDocument() const
   { return reinterpret_cast<C一档多视Doc*>(m_pDocument); }
#endif


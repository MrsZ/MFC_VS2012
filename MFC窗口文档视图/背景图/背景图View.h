
// 背景图View.h : C背景图View 类的接口
//

#pragma once

#include "resource.h"


class C背景图View : public CFormView
{
protected: // 仅从序列化创建
	C背景图View();
	DECLARE_DYNCREATE(C背景图View)

public:
	enum{ IDD = IDD_MY_FORM };

// 特性
public:
	C背景图Doc* GetDocument() const;

	CBitmap m_bitmap;
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
	virtual ~C背景图View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnClickedButton1();
};

#ifndef _DEBUG  // 背景图View.cpp 中的调试版本
inline C背景图Doc* C背景图View::GetDocument() const
   { return reinterpret_cast<C背景图Doc*>(m_pDocument); }
#endif


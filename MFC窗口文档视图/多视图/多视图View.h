
// 多视图View.h : C多视图View 类的接口
//

#pragma once
#include "atltypes.h"


class C多视图View : public CView
{
protected: // 仅从序列化创建
	C多视图View();
	DECLARE_DYNCREATE(C多视图View)

// 特性
public:
	C多视图Doc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// 实现
public:
	virtual ~C多视图View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	CPoint m_ptEnd;
	CPoint m_ptStart;
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // 多视图View.cpp 中的调试版本
inline C多视图Doc* C多视图View::GetDocument() const
   { return reinterpret_cast<C多视图Doc*>(m_pDocument); }
#endif


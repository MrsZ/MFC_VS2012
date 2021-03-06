
// 绘制图形View.h : C绘制图形View 类的接口
//

#pragma once
#include "绘制图形Doc.h"

class C绘制图形View : public CScrollView
{
protected: // 仅从序列化创建
	C绘制图形View();
	DECLARE_DYNCREATE(C绘制图形View)

// 特性
public:
	C绘制图形Doc* GetDocument() const;
	CPoint m_ptEnd;
	CPoint m_ptStart;
	CPoint ptOrg;
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
	virtual ~C绘制图形View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	virtual void OnInitialUpdate();
};

#ifndef _DEBUG  // 绘制图形View.cpp 中的调试版本
inline C绘制图形Doc* C绘制图形View::GetDocument() const
   { return reinterpret_cast<C绘制图形Doc*>(m_pDocument); }
#endif


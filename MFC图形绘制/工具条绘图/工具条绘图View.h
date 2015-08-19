
// 工具条绘图View.h : C工具条绘图View 类的接口
//

#pragma once
#include "PENWILDDLG.h"

class C工具条绘图View : public CView
{
protected: // 仅从序列化创建
	C工具条绘图View();
	DECLARE_DYNCREATE(C工具条绘图View)

// 特性
public:
	C工具条绘图Doc* GetDocument() const;
	CPoint StartPt,EndPt;
	CPen Pen;
	COLORREF m_colors;
	CRect Rect;
	int PenStarte;
	DWORD PenStyle;
	int MyPenWild;
	void FillMyRect();
	void MyColorsDlg();
	void WildDlg();

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
	virtual ~C工具条绘图View();
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
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnPenChioce(UINT nID);
};

#ifndef _DEBUG  // 工具条绘图View.cpp 中的调试版本
inline C工具条绘图Doc* C工具条绘图View::GetDocument() const
   { return reinterpret_cast<C工具条绘图Doc*>(m_pDocument); }
#endif


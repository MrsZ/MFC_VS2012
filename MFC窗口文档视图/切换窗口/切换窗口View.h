
// 切换窗口View.h : C切换窗口View 类的接口
//

#pragma once
#include "切换窗口Doc.h"

class C切换窗口View : public CView
{
protected: // 仅从序列化创建
	C切换窗口View();
	DECLARE_DYNCREATE(C切换窗口View)

// 特性
public:
	C切换窗口Doc* GetDocument() const;

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
	virtual ~C切换窗口View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
	virtual void OnPrint(CDC* pDC, CPrintInfo* pInfo);
};

#ifndef _DEBUG  // 切换窗口View.cpp 中的调试版本
inline C切换窗口Doc* C切换窗口View::GetDocument() const
   { return reinterpret_cast<C切换窗口Doc*>(m_pDocument); }
#endif



// 画直线View.h : C画直线View 类的接口
//

#pragma once


class C画直线View : public CView
{
protected: // 仅从序列化创建
	C画直线View();
	DECLARE_DYNCREATE(C画直线View)

// 特性
public:
	C画直线Doc* GetDocument() const;

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
	virtual ~C画直线View();
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
};

#ifndef _DEBUG  // 画直线View.cpp 中的调试版本
inline C画直线Doc* C画直线View::GetDocument() const
   { return reinterpret_cast<C画直线Doc*>(m_pDocument); }
#endif


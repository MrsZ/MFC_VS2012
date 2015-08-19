
// 设置字体View.h : C设置字体View 类的接口
//

#pragma once


class C设置字体View : public CScrollView
{
protected: // 仅从序列化创建
	C设置字体View();
	DECLARE_DYNCREATE(C设置字体View)

// 特性
public:
	C设置字体Doc* GetDocument() const;
	LOGFONT m_lfText;//用于保存当前使用的逻辑字体

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void OnInitialUpdate(); // 构造后第一次调用
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// 实现
public:
	virtual ~C设置字体View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // 设置字体View.cpp 中的调试版本
inline C设置字体Doc* C设置字体View::GetDocument() const
   { return reinterpret_cast<C设置字体Doc*>(m_pDocument); }
#endif


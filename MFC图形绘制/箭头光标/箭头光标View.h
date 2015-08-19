
// 箭头光标View.h : C箭头光标View 类的接口
//

#pragma once


class C箭头光标View : public CView
{
protected: // 仅从序列化创建
	C箭头光标View();
	DECLARE_DYNCREATE(C箭头光标View)

// 特性
public:
	C箭头光标Doc* GetDocument() const;

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
	virtual ~C箭头光标View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg BOOL OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message);
};

#ifndef _DEBUG  // 箭头光标View.cpp 中的调试版本
inline C箭头光标Doc* C箭头光标View::GetDocument() const
   { return reinterpret_cast<C箭头光标Doc*>(m_pDocument); }
#endif


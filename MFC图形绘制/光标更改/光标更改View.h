
// 光标更改View.h : C光标更改View 类的接口
//

#pragma once


class C光标更改View : public CView
{
protected: // 仅从序列化创建
	C光标更改View();
	DECLARE_DYNCREATE(C光标更改View)

// 特性
public:
	C光标更改Doc* GetDocument() const;

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
	virtual ~C光标更改View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // 光标更改View.cpp 中的调试版本
inline C光标更改Doc* C光标更改View::GetDocument() const
   { return reinterpret_cast<C光标更改Doc*>(m_pDocument); }
#endif



// 创建属性表View.h : C创建属性表View 类的接口
//

#pragma once


class C创建属性表View : public CView
{
protected: // 仅从序列化创建
	C创建属性表View();
	DECLARE_DYNCREATE(C创建属性表View)

// 特性
public:
	C创建属性表Doc* GetDocument() const;

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
	virtual ~C创建属性表View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnSheet();
};

#ifndef _DEBUG  // 创建属性表View.cpp 中的调试版本
inline C创建属性表Doc* C创建属性表View::GetDocument() const
   { return reinterpret_cast<C创建属性表Doc*>(m_pDocument); }
#endif


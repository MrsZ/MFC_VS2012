
// 显示位图View.h : C显示位图View 类的接口
//

#pragma once


class C显示位图View : public CView
{
protected: // 仅从序列化创建
	C显示位图View();
	DECLARE_DYNCREATE(C显示位图View)

// 特性
public:
	C显示位图Doc* GetDocument() const;

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
	virtual ~C显示位图View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // 显示位图View.cpp 中的调试版本
inline C显示位图Doc* C显示位图View::GetDocument() const
   { return reinterpret_cast<C显示位图Doc*>(m_pDocument); }
#endif


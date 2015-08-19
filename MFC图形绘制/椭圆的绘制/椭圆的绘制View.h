
// 椭圆的绘制View.h : C椭圆的绘制View 类的接口
//

#pragma once


class C椭圆的绘制View : public CView
{
protected: // 仅从序列化创建
	C椭圆的绘制View();
	DECLARE_DYNCREATE(C椭圆的绘制View)

// 特性
public:
	C椭圆的绘制Doc* GetDocument() const;

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
	virtual ~C椭圆的绘制View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // 椭圆的绘制View.cpp 中的调试版本
inline C椭圆的绘制Doc* C椭圆的绘制View::GetDocument() const
   { return reinterpret_cast<C椭圆的绘制Doc*>(m_pDocument); }
#endif



// 静态拆分View.h : C静态拆分View 类的接口
//

#pragma once


class C静态拆分View : public CView
{
protected: // 仅从序列化创建
	C静态拆分View();
	DECLARE_DYNCREATE(C静态拆分View)

// 特性
public:
	C静态拆分Doc* GetDocument() const;

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
	virtual ~C静态拆分View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // 静态拆分View.cpp 中的调试版本
inline C静态拆分Doc* C静态拆分View::GetDocument() const
   { return reinterpret_cast<C静态拆分Doc*>(m_pDocument); }
#endif


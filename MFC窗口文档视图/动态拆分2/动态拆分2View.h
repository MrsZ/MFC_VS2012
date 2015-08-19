
// 动态拆分2View.h : C动态拆分2View 类的接口
//

#pragma once


class C动态拆分2View : public CView
{
protected: // 仅从序列化创建
	C动态拆分2View();
	DECLARE_DYNCREATE(C动态拆分2View)

// 特性
public:
	C动态拆分2Doc* GetDocument() const;

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
	virtual ~C动态拆分2View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // 动态拆分2View.cpp 中的调试版本
inline C动态拆分2Doc* C动态拆分2View::GetDocument() const
   { return reinterpret_cast<C动态拆分2Doc*>(m_pDocument); }
#endif


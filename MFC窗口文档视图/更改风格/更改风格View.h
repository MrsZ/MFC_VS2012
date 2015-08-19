
// 更改风格View.h : C更改风格View 类的接口
//

#pragma once


class C更改风格View : public CView
{
protected: // 仅从序列化创建
	C更改风格View();
	DECLARE_DYNCREATE(C更改风格View)

// 特性
public:
	C更改风格Doc* GetDocument() const;

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
	virtual ~C更改风格View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // 更改风格View.cpp 中的调试版本
inline C更改风格Doc* C更改风格View::GetDocument() const
   { return reinterpret_cast<C更改风格Doc*>(m_pDocument); }
#endif


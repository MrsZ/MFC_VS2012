
// 更改字体设置View.h : C更改字体设置View 类的接口
//

#pragma once
#include "PropSheet.h"

class C更改字体设置View : public CEditView
{
protected: // 仅从序列化创建
	C更改字体设置View();
	DECLARE_DYNCREATE(C更改字体设置View)

// 特性
public:
	C更改字体设置Doc* GetDocument() const;

private:
	CFont *pNewFont;

// 操作
public:

// 重写
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// 实现
public:
	virtual ~C更改字体设置View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnFontSet();
	virtual BOOL DestroyWindow();
};

#ifndef _DEBUG  // 更改字体设置View.cpp 中的调试版本
inline C更改字体设置Doc* C更改字体设置View::GetDocument() const
   { return reinterpret_cast<C更改字体设置Doc*>(m_pDocument); }
#endif


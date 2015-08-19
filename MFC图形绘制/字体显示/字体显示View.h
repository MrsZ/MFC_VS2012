
// 字体显示View.h : C字体显示View 类的接口
//

#pragma once


class C字体显示View : public CView
{
protected: // 仅从序列化创建
	C字体显示View();
	DECLARE_DYNCREATE(C字体显示View)

// 特性
public:
	C字体显示Doc* GetDocument() const;

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
	virtual ~C字体显示View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	void FontOut(CDC * pDC, int & nHeight, int nPoints, int dline);
};

#ifndef _DEBUG  // 字体显示View.cpp 中的调试版本
inline C字体显示Doc* C字体显示View::GetDocument() const
   { return reinterpret_cast<C字体显示Doc*>(m_pDocument); }
#endif


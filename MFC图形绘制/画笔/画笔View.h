
// 画笔View.h : C画笔View 类的接口
//

#pragma once


class C画笔View : public CView
{
protected: // 仅从序列化创建
	C画笔View();
	DECLARE_DYNCREATE(C画笔View)

// 特性
public:
	C画笔Doc* GetDocument() const;

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
	virtual ~C画笔View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnPaint();
};

#ifndef _DEBUG  // 画笔View.cpp 中的调试版本
inline C画笔Doc* C画笔View::GetDocument() const
   { return reinterpret_cast<C画笔Doc*>(m_pDocument); }
#endif


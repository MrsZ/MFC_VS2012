
// 窗口位置View.h : C窗口位置View 类的接口
//

#pragma once


class C窗口位置View : public CView
{
protected: // 仅从序列化创建
	C窗口位置View();
	DECLARE_DYNCREATE(C窗口位置View)

// 特性
public:
	C窗口位置Doc* GetDocument() const;

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
	virtual ~C窗口位置View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // 窗口位置View.cpp 中的调试版本
inline C窗口位置Doc* C窗口位置View::GetDocument() const
   { return reinterpret_cast<C窗口位置Doc*>(m_pDocument); }
#endif


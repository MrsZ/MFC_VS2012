
// 五角星View.h : C五角星View 类的接口
//

#pragma once


class C五角星View : public CView
{
protected: // 仅从序列化创建
	C五角星View();
	DECLARE_DYNCREATE(C五角星View)

// 特性
public:
	C五角星Doc* GetDocument() const;

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
	virtual ~C五角星View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // 五角星View.cpp 中的调试版本
inline C五角星Doc* C五角星View::GetDocument() const
   { return reinterpret_cast<C五角星Doc*>(m_pDocument); }
#endif


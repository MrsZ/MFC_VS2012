
// 直方图View.h : C直方图View 类的接口
//

#pragma once


class C直方图View : public CView
{
protected: // 仅从序列化创建
	C直方图View();
	DECLARE_DYNCREATE(C直方图View)

// 特性
public:
	C直方图Doc* GetDocument() const;

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
	virtual ~C直方图View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	void DrawScore(CDC * pDC, float* fScore, int nNum);
};

#ifndef _DEBUG  // 直方图View.cpp 中的调试版本
inline C直方图Doc* C直方图View::GetDocument() const
   { return reinterpret_cast<C直方图Doc*>(m_pDocument); }
#endif



// 图像局部放大View.h : C图像局部放大View 类的接口
//

#pragma once


class C图像局部放大View : public CView
{
protected: // 仅从序列化创建
	C图像局部放大View();
	DECLARE_DYNCREATE(C图像局部放大View)

// 特性
public:
	C图像局部放大Doc* GetDocument() const;
	CSize m_sizeDest;
	CSize m_sizeSource;
	CBitmap *m_pBitmap;
	CDC *m_pdcMem;
	int oldx,oldy,s,d;
	bool recover;
	long mana;

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
	virtual ~C图像局部放大View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // 图像局部放大View.cpp 中的调试版本
inline C图像局部放大Doc* C图像局部放大View::GetDocument() const
   { return reinterpret_cast<C图像局部放大Doc*>(m_pDocument); }
#endif


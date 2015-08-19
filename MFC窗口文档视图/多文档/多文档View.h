
// 多文档View.h : C多文档View 类的接口
//

#pragma once


class C多文档View : public CView
{
protected: // 仅从序列化创建
	C多文档View();
	DECLARE_DYNCREATE(C多文档View)

// 特性
public:
	C多文档Doc* GetDocument() const;

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
	virtual ~C多文档View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // 多文档View.cpp 中的调试版本
inline C多文档Doc* C多文档View::GetDocument() const
   { return reinterpret_cast<C多文档Doc*>(m_pDocument); }
#endif


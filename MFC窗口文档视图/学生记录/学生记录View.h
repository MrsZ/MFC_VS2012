
// 学生记录View.h : C学生记录View 类的接口
//

#pragma once


class C学生记录View : public CView
{
protected: // 仅从序列化创建
	C学生记录View();
	DECLARE_DYNCREATE(C学生记录View)

// 特性
public:
	C学生记录Doc* GetDocument() const;

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
	virtual ~C学生记录View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // 学生记录View.cpp 中的调试版本
inline C学生记录Doc* C学生记录View::GetDocument() const
   { return reinterpret_cast<C学生记录Doc*>(m_pDocument); }
#endif



// 加载网页View.h : C加载网页View 类的接口
//

#pragma once


class C加载网页View : public CHtmlView
{
protected: // 仅从序列化创建
	C加载网页View();
	DECLARE_DYNCREATE(C加载网页View)

// 特性
public:
	C加载网页Doc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void OnInitialUpdate(); // 构造后第一次调用

// 实现
public:
	virtual ~C加载网页View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnFileOpen();
};

#ifndef _DEBUG  // 加载网页View.cpp 中的调试版本
inline C加载网页Doc* C加载网页View::GetDocument() const
   { return reinterpret_cast<C加载网页Doc*>(m_pDocument); }
#endif


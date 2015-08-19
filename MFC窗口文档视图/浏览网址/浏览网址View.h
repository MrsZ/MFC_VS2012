
// 浏览网址View.h : C浏览网址View 类的接口
//

#pragma once


class C浏览网址View : public CHtmlView
{
protected: // 仅从序列化创建
	C浏览网址View();
	DECLARE_DYNCREATE(C浏览网址View)

// 特性
public:
	C浏览网址Doc* GetDocument() const;
	CString MyAddressStr;

// 操作
public:

// 重写
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void OnInitialUpdate(); // 构造后第一次调用

// 实现
public:
	virtual ~C浏览网址View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
	afx_msg void OnMyAddress(UINT nID);
};

#ifndef _DEBUG  // 浏览网址View.cpp 中的调试版本
inline C浏览网址Doc* C浏览网址View::GetDocument() const
   { return reinterpret_cast<C浏览网址Doc*>(m_pDocument); }
#endif


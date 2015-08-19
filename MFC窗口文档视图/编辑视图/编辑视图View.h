
// 编辑视图View.h : C编辑视图View 类的接口
//

#pragma once


class C编辑视图View : public CEditView
{
protected: // 仅从序列化创建
	C编辑视图View();
	DECLARE_DYNCREATE(C编辑视图View)

// 特性
public:
	C编辑视图Doc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// 实现
public:
	virtual ~C编辑视图View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // 编辑视图View.cpp 中的调试版本
inline C编辑视图Doc* C编辑视图View::GetDocument() const
   { return reinterpret_cast<C编辑视图Doc*>(m_pDocument); }
#endif


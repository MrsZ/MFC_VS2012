
// 通用对话框View.h : C通用对话框View 类的接口
//

#pragma once


class C通用对话框View : public CView
{
protected: // 仅从序列化创建
	C通用对话框View();
	DECLARE_DYNCREATE(C通用对话框View)

// 特性
public:
	C通用对话框Doc* GetDocument() const;

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
	virtual ~C通用对话框View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // 通用对话框View.cpp 中的调试版本
inline C通用对话框Doc* C通用对话框View::GetDocument() const
   { return reinterpret_cast<C通用对话框Doc*>(m_pDocument); }
#endif


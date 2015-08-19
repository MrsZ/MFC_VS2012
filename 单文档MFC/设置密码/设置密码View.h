
// 设置密码View.h : C设置密码View 类的接口
//

#pragma once


class C设置密码View : public CView
{
protected: // 仅从序列化创建
	C设置密码View();
	DECLARE_DYNCREATE(C设置密码View)

// 特性
public:
	C设置密码Doc* GetDocument() const;

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
	virtual ~C设置密码View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // 设置密码View.cpp 中的调试版本
inline C设置密码Doc* C设置密码View::GetDocument() const
   { return reinterpret_cast<C设置密码Doc*>(m_pDocument); }
#endif


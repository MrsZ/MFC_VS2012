
// 图片控件View.h : C图片控件View 类的接口
//

#pragma once

#include "MyDlg.h"

class C图片控件View : public CView
{
protected: // 仅从序列化创建
	C图片控件View();
	DECLARE_DYNCREATE(C图片控件View)

// 特性
public:
	C图片控件Doc* GetDocument() const;

	CMyDlg *dlg;

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
	virtual ~C图片控件View();
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
public:
	afx_msg void OnDlg();
};

#ifndef _DEBUG  // 图片控件View.cpp 中的调试版本
inline C图片控件Doc* C图片控件View::GetDocument() const
   { return reinterpret_cast<C图片控件Doc*>(m_pDocument); }
#endif



// 列表控件View.h : C列表控件View 类的接口
//

#pragma once


class C列表控件View : public CListView
{
protected: // 仅从序列化创建
	C列表控件View();
	DECLARE_DYNCREATE(C列表控件View)

// 特性
public:
	C列表控件Doc* GetDocument() const;
	CImageList m_ImageList;
	CImageList m_ImageListSmall;
	CStringArray m_strArray;
	
// 操作
public:

// 重写
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void OnInitialUpdate(); // 构造后第一次调用

// 实现
public:
	virtual ~C列表控件View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnChance();
	afx_msg void OnNMRDblclk(NMHDR *pNMHDR, LRESULT *pResult);
	void SetCtrlStyle(HWND hWnd, DWORD dwNewStyle);
};

#ifndef _DEBUG  // 列表控件View.cpp 中的调试版本
inline C列表控件Doc* C列表控件View::GetDocument() const
   { return reinterpret_cast<C列表控件Doc*>(m_pDocument); }
#endif


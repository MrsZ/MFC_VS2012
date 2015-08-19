
// 树控件View.h : C树控件View 类的接口
//

#pragma once


class C树控件View : public CTreeView
{
protected: // 仅从序列化创建
	C树控件View();
	DECLARE_DYNCREATE(C树控件View)

// 特性
public:
	C树控件Doc* GetDocument() const;
	CString m_strPath;//文件夹路径
	CImageList m_ImageList;//图像列表对象


// 操作
public:

// 重写
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void OnInitialUpdate(); // 构造后第一次调用

// 实现
public:
	virtual ~C树控件View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	void InsertFoldItem(HTREEITEM hItem, CString strPath);
	CString GetFoldItemPath(HTREEITEM hItem);
	afx_msg void OnTvnSelchanged(NMHDR *pNMHDR, LRESULT *pResult);
};

#ifndef _DEBUG  // 树控件View.cpp 中的调试版本
inline C树控件Doc* C树控件View::GetDocument() const
   { return reinterpret_cast<C树控件Doc*>(m_pDocument); }
#endif


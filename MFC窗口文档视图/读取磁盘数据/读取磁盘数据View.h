
// 读取磁盘数据View.h : C读取磁盘数据View 类的接口
//

#pragma once


class C读取磁盘数据View : public CView
{
protected: // 仅从序列化创建
	C读取磁盘数据View();
	DECLARE_DYNCREATE(C读取磁盘数据View)

// 特性
public:
	C读取磁盘数据Doc* GetDocument() const;

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
	virtual ~C读取磁盘数据View();
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

#ifndef _DEBUG  // 读取磁盘数据View.cpp 中的调试版本
inline C读取磁盘数据Doc* C读取磁盘数据View::GetDocument() const
   { return reinterpret_cast<C读取磁盘数据Doc*>(m_pDocument); }
#endif


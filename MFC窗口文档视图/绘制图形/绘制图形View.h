
// ����ͼ��View.h : C����ͼ��View ��Ľӿ�
//

#pragma once
#include "����ͼ��Doc.h"

class C����ͼ��View : public CScrollView
{
protected: // �������л�����
	C����ͼ��View();
	DECLARE_DYNCREATE(C����ͼ��View)

// ����
public:
	C����ͼ��Doc* GetDocument() const;
	CPoint m_ptEnd;
	CPoint m_ptStart;
	CPoint ptOrg;
// ����
public:

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// ʵ��
public:
	virtual ~C����ͼ��View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	virtual void OnInitialUpdate();
};

#ifndef _DEBUG  // ����ͼ��View.cpp �еĵ��԰汾
inline C����ͼ��Doc* C����ͼ��View::GetDocument() const
   { return reinterpret_cast<C����ͼ��Doc*>(m_pDocument); }
#endif


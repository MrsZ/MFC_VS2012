
// ��������ͼView.h : C��������ͼView ��Ľӿ�
//

#pragma once
#include "PENWILDDLG.h"

class C��������ͼView : public CView
{
protected: // �������л�����
	C��������ͼView();
	DECLARE_DYNCREATE(C��������ͼView)

// ����
public:
	C��������ͼDoc* GetDocument() const;
	CPoint StartPt,EndPt;
	CPen Pen;
	COLORREF m_colors;
	CRect Rect;
	int PenStarte;
	DWORD PenStyle;
	int MyPenWild;
	void FillMyRect();
	void MyColorsDlg();
	void WildDlg();

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
	virtual ~C��������ͼView();
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
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnPenChioce(UINT nID);
};

#ifndef _DEBUG  // ��������ͼView.cpp �еĵ��԰汾
inline C��������ͼDoc* C��������ͼView::GetDocument() const
   { return reinterpret_cast<C��������ͼDoc*>(m_pDocument); }
#endif


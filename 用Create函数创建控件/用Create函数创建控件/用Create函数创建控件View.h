
// ��Create���������ؼ�View.h : C��Create���������ؼ�View ��Ľӿ�
//

#pragma once


class C��Create���������ؼ�View : public CView
{
protected: // �������л�����
	C��Create���������ؼ�View();
	DECLARE_DYNCREATE(C��Create���������ؼ�View)

// ����
public:
	C��Create���������ؼ�Doc* GetDocument() const;

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
	virtual ~C��Create���������ؼ�View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // ��Create���������ؼ�View.cpp �еĵ��԰汾
inline C��Create���������ؼ�Doc* C��Create���������ؼ�View::GetDocument() const
   { return reinterpret_cast<C��Create���������ؼ�Doc*>(m_pDocument); }
#endif


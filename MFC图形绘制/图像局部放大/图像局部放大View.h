
// ͼ��ֲ��Ŵ�View.h : Cͼ��ֲ��Ŵ�View ��Ľӿ�
//

#pragma once


class Cͼ��ֲ��Ŵ�View : public CView
{
protected: // �������л�����
	Cͼ��ֲ��Ŵ�View();
	DECLARE_DYNCREATE(Cͼ��ֲ��Ŵ�View)

// ����
public:
	Cͼ��ֲ��Ŵ�Doc* GetDocument() const;
	CSize m_sizeDest;
	CSize m_sizeSource;
	CBitmap *m_pBitmap;
	CDC *m_pdcMem;
	int oldx,oldy,s,d;
	bool recover;
	long mana;

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
	virtual ~Cͼ��ֲ��Ŵ�View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // ͼ��ֲ��Ŵ�View.cpp �еĵ��԰汾
inline Cͼ��ֲ��Ŵ�Doc* Cͼ��ֲ��Ŵ�View::GetDocument() const
   { return reinterpret_cast<Cͼ��ֲ��Ŵ�Doc*>(m_pDocument); }
#endif



// һ�㺯����ͼView.h : Cһ�㺯����ͼView ��Ľӿ�
//

#pragma once


class Cһ�㺯����ͼView : public CView
{
protected: // �������л�����
	Cһ�㺯����ͼView();
	DECLARE_DYNCREATE(Cһ�㺯����ͼView)

// ����
public:
	Cһ�㺯����ͼDoc* GetDocument() const;

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
	virtual ~Cһ�㺯����ͼView();
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
};

#ifndef _DEBUG  // һ�㺯����ͼView.cpp �еĵ��԰汾
inline Cһ�㺯����ͼDoc* Cһ�㺯����ͼView::GetDocument() const
   { return reinterpret_cast<Cһ�㺯����ͼDoc*>(m_pDocument); }
#endif



// ������ʾView.h : C������ʾView ��Ľӿ�
//

#pragma once


class C������ʾView : public CView
{
protected: // �������л�����
	C������ʾView();
	DECLARE_DYNCREATE(C������ʾView)

// ����
public:
	C������ʾDoc* GetDocument() const;

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
	virtual ~C������ʾView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
	void FontOut(CDC * pDC, int & nHeight, int nPoints, int dline);
};

#ifndef _DEBUG  // ������ʾView.cpp �еĵ��԰汾
inline C������ʾDoc* C������ʾView::GetDocument() const
   { return reinterpret_cast<C������ʾDoc*>(m_pDocument); }
#endif



// ��ʾλͼView.h : C��ʾλͼView ��Ľӿ�
//

#pragma once


class C��ʾλͼView : public CView
{
protected: // �������л�����
	C��ʾλͼView();
	DECLARE_DYNCREATE(C��ʾλͼView)

// ����
public:
	C��ʾλͼDoc* GetDocument() const;

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
	virtual ~C��ʾλͼView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // ��ʾλͼView.cpp �еĵ��԰汾
inline C��ʾλͼDoc* C��ʾλͼView::GetDocument() const
   { return reinterpret_cast<C��ʾλͼDoc*>(m_pDocument); }
#endif


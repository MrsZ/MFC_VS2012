
// ��ʾ��ͼView.h : C��ʾ��ͼView ��Ľӿ�
//

#pragma once


class C��ʾ��ͼView : public CView
{
protected: // �������л�����
	C��ʾ��ͼView();
	DECLARE_DYNCREATE(C��ʾ��ͼView)

// ����
public:
	C��ʾ��ͼDoc* GetDocument() const;

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
	virtual ~C��ʾ��ͼView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // ��ʾ��ͼView.cpp �еĵ��԰汾
inline C��ʾ��ͼDoc* C��ʾ��ͼView::GetDocument() const
   { return reinterpret_cast<C��ʾ��ͼDoc*>(m_pDocument); }
#endif


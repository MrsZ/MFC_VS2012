
// ��ʾ������ɫView.h : C��ʾ������ɫView ��Ľӿ�
//

#pragma once


class C��ʾ������ɫView : public CView
{
protected: // �������л�����
	C��ʾ������ɫView();
	DECLARE_DYNCREATE(C��ʾ������ɫView)

// ����
public:
	C��ʾ������ɫDoc* GetDocument() const;
	CRect r;
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
	virtual ~C��ʾ������ɫView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // ��ʾ������ɫView.cpp �еĵ��԰汾
inline C��ʾ������ɫDoc* C��ʾ������ɫView::GetDocument() const
   { return reinterpret_cast<C��ʾ������ɫDoc*>(m_pDocument); }
#endif



// ����λ��View.h : C����λ��View ��Ľӿ�
//

#pragma once


class C����λ��View : public CView
{
protected: // �������л�����
	C����λ��View();
	DECLARE_DYNCREATE(C����λ��View)

// ����
public:
	C����λ��Doc* GetDocument() const;

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
	virtual ~C����λ��View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // ����λ��View.cpp �еĵ��԰汾
inline C����λ��Doc* C����λ��View::GetDocument() const
   { return reinterpret_cast<C����λ��Doc*>(m_pDocument); }
#endif



// ���ĵ�View.h : C���ĵ�View ��Ľӿ�
//

#pragma once


class C���ĵ�View : public CView
{
protected: // �������л�����
	C���ĵ�View();
	DECLARE_DYNCREATE(C���ĵ�View)

// ����
public:
	C���ĵ�Doc* GetDocument() const;

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
	virtual ~C���ĵ�View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // ���ĵ�View.cpp �еĵ��԰汾
inline C���ĵ�Doc* C���ĵ�View::GetDocument() const
   { return reinterpret_cast<C���ĵ�Doc*>(m_pDocument); }
#endif



// �������Ա�View.h : C�������Ա�View ��Ľӿ�
//

#pragma once


class C�������Ա�View : public CView
{
protected: // �������л�����
	C�������Ա�View();
	DECLARE_DYNCREATE(C�������Ա�View)

// ����
public:
	C�������Ա�Doc* GetDocument() const;

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
	virtual ~C�������Ա�View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnSheet();
};

#ifndef _DEBUG  // �������Ա�View.cpp �еĵ��԰汾
inline C�������Ա�Doc* C�������Ա�View::GetDocument() const
   { return reinterpret_cast<C�������Ա�Doc*>(m_pDocument); }
#endif


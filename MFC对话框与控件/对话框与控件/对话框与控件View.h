
// �Ի�����ؼ�View.h : C�Ի�����ؼ�View ��Ľӿ�
//

#pragma once


class C�Ի�����ؼ�View : public CView
{
protected: // �������л�����
	C�Ի�����ؼ�View();
	DECLARE_DYNCREATE(C�Ի�����ؼ�View)

// ����
public:
	C�Ի�����ؼ�Doc* GetDocument() const;

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
	virtual ~C�Ի�����ؼ�View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // �Ի�����ؼ�View.cpp �еĵ��԰汾
inline C�Ի�����ؼ�Doc* C�Ի�����ؼ�View::GetDocument() const
   { return reinterpret_cast<C�Ի�����ؼ�Doc*>(m_pDocument); }
#endif


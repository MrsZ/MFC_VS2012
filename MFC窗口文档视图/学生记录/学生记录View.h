
// ѧ����¼View.h : Cѧ����¼View ��Ľӿ�
//

#pragma once


class Cѧ����¼View : public CView
{
protected: // �������л�����
	Cѧ����¼View();
	DECLARE_DYNCREATE(Cѧ����¼View)

// ����
public:
	Cѧ����¼Doc* GetDocument() const;

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
	virtual ~Cѧ����¼View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // ѧ����¼View.cpp �еĵ��԰汾
inline Cѧ����¼Doc* Cѧ����¼View::GetDocument() const
   { return reinterpret_cast<Cѧ����¼Doc*>(m_pDocument); }
#endif


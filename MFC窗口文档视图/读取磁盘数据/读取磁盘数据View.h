
// ��ȡ��������View.h : C��ȡ��������View ��Ľӿ�
//

#pragma once


class C��ȡ��������View : public CView
{
protected: // �������л�����
	C��ȡ��������View();
	DECLARE_DYNCREATE(C��ȡ��������View)

// ����
public:
	C��ȡ��������Doc* GetDocument() const;

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
	virtual ~C��ȡ��������View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnFileOpen();
};

#ifndef _DEBUG  // ��ȡ��������View.cpp �еĵ��԰汾
inline C��ȡ��������Doc* C��ȡ��������View::GetDocument() const
   { return reinterpret_cast<C��ȡ��������Doc*>(m_pDocument); }
#endif


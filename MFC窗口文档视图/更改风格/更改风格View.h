
// ���ķ��View.h : C���ķ��View ��Ľӿ�
//

#pragma once


class C���ķ��View : public CView
{
protected: // �������л�����
	C���ķ��View();
	DECLARE_DYNCREATE(C���ķ��View)

// ����
public:
	C���ķ��Doc* GetDocument() const;

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
	virtual ~C���ķ��View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // ���ķ��View.cpp �еĵ��԰汾
inline C���ķ��Doc* C���ķ��View::GetDocument() const
   { return reinterpret_cast<C���ķ��Doc*>(m_pDocument); }
#endif


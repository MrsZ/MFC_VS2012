
// ��ɫ��View.h : C��ɫ��View ��Ľӿ�
//

#pragma once


class C��ɫ��View : public CView
{
protected: // �������л�����
	C��ɫ��View();
	DECLARE_DYNCREATE(C��ɫ��View)

// ����
public:
	C��ɫ��Doc* GetDocument() const;

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
	virtual ~C��ɫ��View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // ��ɫ��View.cpp �еĵ��԰汾
inline C��ɫ��Doc* C��ɫ��View::GetDocument() const
   { return reinterpret_cast<C��ɫ��Doc*>(m_pDocument); }
#endif



// ��ͷ���View.h : C��ͷ���View ��Ľӿ�
//

#pragma once


class C��ͷ���View : public CView
{
protected: // �������л�����
	C��ͷ���View();
	DECLARE_DYNCREATE(C��ͷ���View)

// ����
public:
	C��ͷ���Doc* GetDocument() const;

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
	virtual ~C��ͷ���View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg BOOL OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message);
};

#ifndef _DEBUG  // ��ͷ���View.cpp �еĵ��԰汾
inline C��ͷ���Doc* C��ͷ���View::GetDocument() const
   { return reinterpret_cast<C��ͷ���Doc*>(m_pDocument); }
#endif


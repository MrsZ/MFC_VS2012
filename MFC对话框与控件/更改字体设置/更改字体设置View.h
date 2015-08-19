
// ������������View.h : C������������View ��Ľӿ�
//

#pragma once
#include "PropSheet.h"

class C������������View : public CEditView
{
protected: // �������л�����
	C������������View();
	DECLARE_DYNCREATE(C������������View)

// ����
public:
	C������������Doc* GetDocument() const;

private:
	CFont *pNewFont;

// ����
public:

// ��д
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// ʵ��
public:
	virtual ~C������������View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnFontSet();
	virtual BOOL DestroyWindow();
};

#ifndef _DEBUG  // ������������View.cpp �еĵ��԰汾
inline C������������Doc* C������������View::GetDocument() const
   { return reinterpret_cast<C������������Doc*>(m_pDocument); }
#endif


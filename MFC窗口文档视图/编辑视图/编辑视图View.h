
// �༭��ͼView.h : C�༭��ͼView ��Ľӿ�
//

#pragma once


class C�༭��ͼView : public CEditView
{
protected: // �������л�����
	C�༭��ͼView();
	DECLARE_DYNCREATE(C�༭��ͼView)

// ����
public:
	C�༭��ͼDoc* GetDocument() const;

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
	virtual ~C�༭��ͼView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // �༭��ͼView.cpp �еĵ��԰汾
inline C�༭��ͼDoc* C�༭��ͼView::GetDocument() const
   { return reinterpret_cast<C�༭��ͼDoc*>(m_pDocument); }
#endif


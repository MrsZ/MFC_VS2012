
// ������ҳView.h : C������ҳView ��Ľӿ�
//

#pragma once


class C������ҳView : public CHtmlView
{
protected: // �������л�����
	C������ҳView();
	DECLARE_DYNCREATE(C������ҳView)

// ����
public:
	C������ҳDoc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void OnInitialUpdate(); // ������һ�ε���

// ʵ��
public:
	virtual ~C������ҳView();
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

#ifndef _DEBUG  // ������ҳView.cpp �еĵ��԰汾
inline C������ҳDoc* C������ҳView::GetDocument() const
   { return reinterpret_cast<C������ҳDoc*>(m_pDocument); }
#endif


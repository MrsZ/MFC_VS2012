
// ����ͼView.h : C����ͼView ��Ľӿ�
//

#pragma once

#include "resource.h"


class C����ͼView : public CFormView
{
protected: // �������л�����
	C����ͼView();
	DECLARE_DYNCREATE(C����ͼView)

public:
	enum{ IDD = IDD_MY_FORM };

// ����
public:
	C����ͼDoc* GetDocument() const;

	CBitmap m_bitmap;
// ����
public:

// ��д
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	virtual void OnInitialUpdate(); // ������һ�ε���

// ʵ��
public:
	virtual ~C����ͼView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnClickedButton1();
};

#ifndef _DEBUG  // ����ͼView.cpp �еĵ��԰汾
inline C����ͼDoc* C����ͼView::GetDocument() const
   { return reinterpret_cast<C����ͼDoc*>(m_pDocument); }
#endif


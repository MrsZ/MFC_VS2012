
// һ������View.h : Cһ������View ��Ľӿ�
//

#pragma once

#include "resource.h"
#include "afxcmn.h"

class Cһ������Doc;

class Cһ������View : public CFormView
{
protected: // �������л�����
	Cһ������View();
	DECLARE_DYNCREATE(Cһ������View)

public:
	enum{ IDD = IDD_MY_FORM };

// ����
public:
	Cһ������Doc* GetDocument() const;

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
	virtual ~Cһ������View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
	int m_CoorX;
	int m_CoorY;
	CSpinButtonCtrl m_SpinX;
	CSpinButtonCtrl m_SpinY;
	bool m_bEditOK;

	afx_msg void OnChangeEdit();
	virtual void OnUpdate(CView* /*pSender*/, LPARAM /*lHint*/, CObject* /*pHint*/);
};

#ifndef _DEBUG  // һ������View.cpp �еĵ��԰汾
inline Cһ������Doc* Cһ������View::GetDocument() const
   { return reinterpret_cast<Cһ������Doc*>(m_pDocument); }
#endif



// �����ַView.h : C�����ַView ��Ľӿ�
//

#pragma once


class C�����ַView : public CHtmlView
{
protected: // �������л�����
	C�����ַView();
	DECLARE_DYNCREATE(C�����ַView)

// ����
public:
	C�����ַDoc* GetDocument() const;
	CString MyAddressStr;

// ����
public:

// ��д
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void OnInitialUpdate(); // ������һ�ε���

// ʵ��
public:
	virtual ~C�����ַView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
	afx_msg void OnMyAddress(UINT nID);
};

#ifndef _DEBUG  // �����ַView.cpp �еĵ��԰汾
inline C�����ַDoc* C�����ַView::GetDocument() const
   { return reinterpret_cast<C�����ַDoc*>(m_pDocument); }
#endif


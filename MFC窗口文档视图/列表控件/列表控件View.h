
// �б�ؼ�View.h : C�б�ؼ�View ��Ľӿ�
//

#pragma once


class C�б�ؼ�View : public CListView
{
protected: // �������л�����
	C�б�ؼ�View();
	DECLARE_DYNCREATE(C�б�ؼ�View)

// ����
public:
	C�б�ؼ�Doc* GetDocument() const;
	CImageList m_ImageList;
	CImageList m_ImageListSmall;
	CStringArray m_strArray;
	
// ����
public:

// ��д
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void OnInitialUpdate(); // ������һ�ε���

// ʵ��
public:
	virtual ~C�б�ؼ�View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnChance();
	afx_msg void OnNMRDblclk(NMHDR *pNMHDR, LRESULT *pResult);
	void SetCtrlStyle(HWND hWnd, DWORD dwNewStyle);
};

#ifndef _DEBUG  // �б�ؼ�View.cpp �еĵ��԰汾
inline C�б�ؼ�Doc* C�б�ؼ�View::GetDocument() const
   { return reinterpret_cast<C�б�ؼ�Doc*>(m_pDocument); }
#endif


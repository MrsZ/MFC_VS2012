
// ���ؼ�View.h : C���ؼ�View ��Ľӿ�
//

#pragma once


class C���ؼ�View : public CTreeView
{
protected: // �������л�����
	C���ؼ�View();
	DECLARE_DYNCREATE(C���ؼ�View)

// ����
public:
	C���ؼ�Doc* GetDocument() const;
	CString m_strPath;//�ļ���·��
	CImageList m_ImageList;//ͼ���б����


// ����
public:

// ��д
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void OnInitialUpdate(); // ������һ�ε���

// ʵ��
public:
	virtual ~C���ؼ�View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
public:
	void InsertFoldItem(HTREEITEM hItem, CString strPath);
	CString GetFoldItemPath(HTREEITEM hItem);
	afx_msg void OnTvnSelchanged(NMHDR *pNMHDR, LRESULT *pResult);
};

#ifndef _DEBUG  // ���ؼ�View.cpp �еĵ��԰汾
inline C���ؼ�Doc* C���ؼ�View::GetDocument() const
   { return reinterpret_cast<C���ؼ�Doc*>(m_pDocument); }
#endif



// ͼƬ�ؼ�View.h : CͼƬ�ؼ�View ��Ľӿ�
//

#pragma once

#include "MyDlg.h"

class CͼƬ�ؼ�View : public CView
{
protected: // �������л�����
	CͼƬ�ؼ�View();
	DECLARE_DYNCREATE(CͼƬ�ؼ�View)

// ����
public:
	CͼƬ�ؼ�Doc* GetDocument() const;

	CMyDlg *dlg;

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
	virtual ~CͼƬ�ؼ�View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnDlg();
};

#ifndef _DEBUG  // ͼƬ�ؼ�View.cpp �еĵ��԰汾
inline CͼƬ�ؼ�Doc* CͼƬ�ؼ�View::GetDocument() const
   { return reinterpret_cast<CͼƬ�ؼ�Doc*>(m_pDocument); }
#endif


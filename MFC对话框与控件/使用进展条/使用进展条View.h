
// ʹ�ý�չ��View.h : Cʹ�ý�չ��View ��Ľӿ�
//

#pragma once


class Cʹ�ý�չ��View : public CView
{
protected: // �������л�����
	Cʹ�ý�չ��View();
	DECLARE_DYNCREATE(Cʹ�ý�չ��View)

// ����
public:
	Cʹ�ý�չ��Doc* GetDocument() const;

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
	virtual ~Cʹ�ý�չ��View();
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
};

#ifndef _DEBUG  // ʹ�ý�չ��View.cpp �еĵ��԰汾
inline Cʹ�ý�չ��Doc* Cʹ�ý�չ��View::GetDocument() const
   { return reinterpret_cast<Cʹ�ý�չ��Doc*>(m_pDocument); }
#endif



// ͼ����ʾView.h : Cͼ����ʾView ��Ľӿ�
//

#pragma once


class Cͼ����ʾView : public CView
{
protected: // �������л�����
	Cͼ����ʾView();
	DECLARE_DYNCREATE(Cͼ����ʾView)

// ����
public:
	Cͼ����ʾDoc* GetDocument() const;

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
	virtual ~Cͼ����ʾView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // ͼ����ʾView.cpp �еĵ��԰汾
inline Cͼ����ʾDoc* Cͼ����ʾView::GetDocument() const
   { return reinterpret_cast<Cͼ����ʾDoc*>(m_pDocument); }
#endif


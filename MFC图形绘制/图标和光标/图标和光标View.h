
// ͼ��͹��View.h : Cͼ��͹��View ��Ľӿ�
//

#pragma once


class Cͼ��͹��View : public CView
{
protected: // �������л�����
	Cͼ��͹��View();
	DECLARE_DYNCREATE(Cͼ��͹��View)

// ����
public:
	Cͼ��͹��Doc* GetDocument() const;

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
	virtual ~Cͼ��͹��View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // ͼ��͹��View.cpp �еĵ��԰汾
inline Cͼ��͹��Doc* Cͼ��͹��View::GetDocument() const
   { return reinterpret_cast<Cͼ��͹��Doc*>(m_pDocument); }
#endif


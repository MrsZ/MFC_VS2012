
// ��Բ�Ļ���View.h : C��Բ�Ļ���View ��Ľӿ�
//

#pragma once


class C��Բ�Ļ���View : public CView
{
protected: // �������л�����
	C��Բ�Ļ���View();
	DECLARE_DYNCREATE(C��Բ�Ļ���View)

// ����
public:
	C��Բ�Ļ���Doc* GetDocument() const;

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
	virtual ~C��Բ�Ļ���View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // ��Բ�Ļ���View.cpp �еĵ��԰汾
inline C��Բ�Ļ���Doc* C��Բ�Ļ���View::GetDocument() const
   { return reinterpret_cast<C��Բ�Ļ���Doc*>(m_pDocument); }
#endif


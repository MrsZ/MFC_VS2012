
// �ı�ͼ��View.h : C�ı�ͼ��View ��Ľӿ�
//

#pragma once


class C�ı�ͼ��View : public CView
{
protected: // �������л�����
	C�ı�ͼ��View();
	DECLARE_DYNCREATE(C�ı�ͼ��View)

// ����
public:
	C�ı�ͼ��Doc* GetDocument() const;

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
	virtual ~C�ı�ͼ��View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // �ı�ͼ��View.cpp �еĵ��԰汾
inline C�ı�ͼ��Doc* C�ı�ͼ��View::GetDocument() const
   { return reinterpret_cast<C�ı�ͼ��Doc*>(m_pDocument); }
#endif



// ͨ�öԻ���View.h : Cͨ�öԻ���View ��Ľӿ�
//

#pragma once


class Cͨ�öԻ���View : public CView
{
protected: // �������л�����
	Cͨ�öԻ���View();
	DECLARE_DYNCREATE(Cͨ�öԻ���View)

// ����
public:
	Cͨ�öԻ���Doc* GetDocument() const;

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
	virtual ~Cͨ�öԻ���View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // ͨ�öԻ���View.cpp �еĵ��԰汾
inline Cͨ�öԻ���Doc* Cͨ�öԻ���View::GetDocument() const
   { return reinterpret_cast<Cͨ�öԻ���Doc*>(m_pDocument); }
#endif


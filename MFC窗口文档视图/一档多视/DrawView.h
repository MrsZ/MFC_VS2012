#pragma once


// CDrawView ��ͼ

class CDrawView : public CView
{
	DECLARE_DYNCREATE(CDrawView)

protected:
	CDrawView();           // ��̬������ʹ�õ��ܱ����Ĺ��캯��
	virtual ~CDrawView();

public:
	virtual void OnDraw(CDC* pDC);      // ��д�Ի��Ƹ���ͼ
#ifdef _DEBUG
	virtual void AssertValid() const;
#ifndef _WIN32_WCE
	virtual void Dump(CDumpContext& dc) const;
#endif
#endif

protected:
	DECLARE_MESSAGE_MAP()

public:
	CPoint m_ptDraw;
	virtual void OnInitialUpdate();
	virtual void OnUpdate(CView* /*pSender*/, LPARAM /*lHint*/, CObject* /*pHint*/);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
};



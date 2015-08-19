#pragma once


// CDrawView 视图

class CDrawView : public CView
{
	DECLARE_DYNCREATE(CDrawView)

protected:
	CDrawView();           // 动态创建所使用的受保护的构造函数
	virtual ~CDrawView();

public:
	virtual void OnDraw(CDC* pDC);      // 重写以绘制该视图
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



#pragma once


// CDemoView 视图

class CDemoView : public CView
{
	DECLARE_DYNCREATE(CDemoView)

protected:
	CDemoView();           // 动态创建所使用的受保护的构造函数
	virtual ~CDemoView();

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
};



#pragma once


// CPositionView ��ͼ

class CPositionView : public CView
{
	DECLARE_DYNCREATE(CPositionView)

protected:
	CPositionView();           // ��̬������ʹ�õ��ܱ����Ĺ��캯��
	virtual ~CPositionView();

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
};



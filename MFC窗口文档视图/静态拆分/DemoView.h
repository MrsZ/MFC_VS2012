#pragma once


// CDemoView ��ͼ

class CDemoView : public CView
{
	DECLARE_DYNCREATE(CDemoView)

protected:
	CDemoView();           // ��̬������ʹ�õ��ܱ����Ĺ��캯��
	virtual ~CDemoView();

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



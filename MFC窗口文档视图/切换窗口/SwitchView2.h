#pragma once


// CSwitchView2 ��ͼ

class CSwitchView2 : public CView
{
	DECLARE_DYNCREATE(CSwitchView2)

protected:
	CSwitchView2();           // ��̬������ʹ�õ��ܱ����Ĺ��캯��
	virtual ~CSwitchView2();

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
	virtual void OnPrint(CDC* pDC, CPrintInfo* pInfo);
};



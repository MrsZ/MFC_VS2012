#pragma once


// CSwitchView1 ��ͼ

class CSwitchView1 : public CView
{
	DECLARE_DYNCREATE(CSwitchView1)

protected:
	CSwitchView1();           // ��̬������ʹ�õ��ܱ����Ĺ��캯��
	virtual ~CSwitchView1();

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



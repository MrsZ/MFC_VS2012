#pragma once



// CPositionView ��ͼ

class CPositionView : public CScrollView
{
	DECLARE_DYNCREATE(CPositionView)

protected:
	CPositionView();           // ��̬������ʹ�õ��ܱ����Ĺ��캯��
	virtual ~CPositionView();

public:
#ifdef _DEBUG
	virtual void AssertValid() const;
#ifndef _WIN32_WCE
	virtual void Dump(CDumpContext& dc) const;
#endif
#endif

protected:
	virtual void OnDraw(CDC* pDC);      // ��д�Ի��Ƹ���ͼ
	virtual void OnInitialUpdate();     // �����ĵ�һ��

	DECLARE_MESSAGE_MAP()
};



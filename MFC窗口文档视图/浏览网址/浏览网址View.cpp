
// �����ַView.cpp : C�����ַView ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "�����ַ.h"
#endif

#include "�����ַDoc.h"
#include "�����ַView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// C�����ַView

IMPLEMENT_DYNCREATE(C�����ַView, CHtmlView)

BEGIN_MESSAGE_MAP(C�����ַView, CHtmlView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CHtmlView::OnFilePrint)
	ON_COMMAND_RANGE(IDC_BUTTON1,IDC_BUTTON6,OnMyAddress)
END_MESSAGE_MAP()

// C�����ַView ����/����

C�����ַView::C�����ַView()
{
	// TODO: �ڴ˴���ӹ������
	MyAddressStr="http://www.baidu.com";
}

C�����ַView::~C�����ַView()
{
}

BOOL C�����ַView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CHtmlView::PreCreateWindow(cs);
}

void C�����ַView::OnInitialUpdate()
{
	CHtmlView::OnInitialUpdate();

	Navigate2(_T(MyAddressStr),NULL,NULL);
}


// C�����ַView ��ӡ



// C�����ַView ���

#ifdef _DEBUG
void C�����ַView::AssertValid() const
{
	CHtmlView::AssertValid();
}

void C�����ַView::Dump(CDumpContext& dc) const
{
	CHtmlView::Dump(dc);
}

C�����ַDoc* C�����ַView::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(C�����ַDoc)));
	return (C�����ַDoc*)m_pDocument;
}
#endif //_DEBUG


// C�����ַView ��Ϣ�������
void C�����ַView::OnMyAddress(UINT nID)
{
	switch(nID)
	{
	case IDC_BUTTON1:
		MyAddressStr="http://www.baidu.com";break;
	case IDC_BUTTON2:
		MyAddressStr="http://www.sohu.com";break;
	case IDC_BUTTON3:
		MyAddressStr="http://www.taobao.com";break;
	case IDC_BUTTON4:
		MyAddressStr="http://www.sina.com";break;
	case IDC_BUTTON5:
		MyAddressStr="http://www.yahoo.com.cn";break;
	case IDC_BUTTON6:
		MyAddressStr="http://www.chinafilm.com";break;
	}
	Navigate2(_T(MyAddressStr),NULL,NULL);
	Refresh();
}
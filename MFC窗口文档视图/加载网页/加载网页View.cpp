
// ������ҳView.cpp : C������ҳView ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "������ҳ.h"
#endif

#include "������ҳDoc.h"
#include "������ҳView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// C������ҳView

IMPLEMENT_DYNCREATE(C������ҳView, CHtmlView)

BEGIN_MESSAGE_MAP(C������ҳView, CHtmlView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CHtmlView::OnFilePrint)
	ON_COMMAND(ID_FILE_OPEN, &C������ҳView::OnFileOpen)
END_MESSAGE_MAP()

// C������ҳView ����/����

C������ҳView::C������ҳView()
{
	// TODO: �ڴ˴���ӹ������

}

C������ҳView::~C������ҳView()
{
}

BOOL C������ҳView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CHtmlView::PreCreateWindow(cs);
}

void C������ҳView::OnInitialUpdate()
{
	CHtmlView::OnInitialUpdate();

	Navigate2(_T("http://www.msdn.microsoft.com/visualc/"),NULL,NULL);
}


// C������ҳView ��ӡ



// C������ҳView ���

#ifdef _DEBUG
void C������ҳView::AssertValid() const
{
	CHtmlView::AssertValid();
}

void C������ҳView::Dump(CDumpContext& dc) const
{
	CHtmlView::Dump(dc);
}

C������ҳDoc* C������ҳView::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(C������ҳDoc)));
	return (C������ҳDoc*)m_pDocument;
}
#endif //_DEBUG


// C������ҳView ��Ϣ�������


void C������ҳView::OnFileOpen()
{
	// TODO: �ڴ���������������
	CFileDialog dlg(true,_T("htm"),_T("*.htm"),OFN_HIDEREADONLY|OFN_OVERWRITEPROMPT,_T("��ҳ(*.htm)|*.htm|"));
	if(IDOK==dlg.DoModal())
	{
		Navigate2(dlg.GetPathName(),NULL,NULL);
	}
}

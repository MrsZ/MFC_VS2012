
// ����ͼView.cpp : C����ͼView ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "����ͼ.h"
#endif

#include "����ͼDoc.h"
#include "����ͼView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// C����ͼView

IMPLEMENT_DYNCREATE(C����ͼView, CFormView)

BEGIN_MESSAGE_MAP(C����ͼView, CFormView)
	ON_BN_CLICKED(IDC_BUTTON1, &C����ͼView::OnClickedButton1)
END_MESSAGE_MAP()

// C����ͼView ����/����

C����ͼView::C����ͼView()
	: CFormView(C����ͼView::IDD)
{
	// TODO: �ڴ˴���ӹ������

}

C����ͼView::~C����ͼView()
{
}

void C����ͼView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
}

BOOL C����ͼView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CFormView::PreCreateWindow(cs);
}

void C����ͼView::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

}


// C����ͼView ���

#ifdef _DEBUG
void C����ͼView::AssertValid() const
{
	CFormView::AssertValid();
}

void C����ͼView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

C����ͼDoc* C����ͼView::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(C����ͼDoc)));
	return (C����ͼDoc*)m_pDocument;
}
#endif //_DEBUG


// C����ͼView ��Ϣ�������


void C����ͼView::OnClickedButton1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CDC *pDC=GetDC();//��ʾ�豸�����ĵľ��
	//HBITMAP����λͼ��Ϣ���ڴ���ľ��
	HBITMAP hBitmap=(HBITMAP)LoadImage(NULL,_T("2.bmp"),IMAGE_BITMAP,0,0,LR_CREATEDIBSECTION|LR_DEFAULTSIZE
		|LR_LOADFROMFILE);
	m_bitmap.Attach(hBitmap);//��HBITMAPѡ������
	BITMAP bm;
	m_bitmap.GetBitmap(&bm);//���λͼ
	CDC dcImage;
	if(!dcImage.CreateCompatibleDC(pDC))
		return;
	CBitmap *pOldBitmap=dcImage.SelectObject(&m_bitmap);//ѡ��һ��GDI���ƶ�����ַ
	pDC->BitBlt(0,0,bm.bmWidth,bm.bmHeight,&dcImage,0,0,SRCCOPY);//��䴰�ڱ���
	dcImage.SelectObject(pOldBitmap);//ѡ��һ��GDI���ƶ���
	DeleteObject(m_bitmap.Detach());//�ͷ�λͼ�洢�ռ�
}

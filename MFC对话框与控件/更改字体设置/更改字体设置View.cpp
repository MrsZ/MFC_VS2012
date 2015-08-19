
// ������������View.cpp : C������������View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "������������.h"
#endif

#include "������������Doc.h"
#include "������������View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// C������������View

IMPLEMENT_DYNCREATE(C������������View, CEditView)

BEGIN_MESSAGE_MAP(C������������View, CEditView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CEditView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CEditView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CEditView::OnFilePrintPreview)
	ON_COMMAND(ID_FONT_SET, &C������������View::OnFontSet)
END_MESSAGE_MAP()

// C������������View ����/����

C������������View::C������������View()
{
	// TODO: �ڴ˴���ӹ������

}

C������������View::~C������������View()
{
}

BOOL C������������View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	BOOL bPreCreated = CEditView::PreCreateWindow(cs);
	cs.style &= ~(ES_AUTOHSCROLL|WS_HSCROLL);	// ���û���

	return bPreCreated;
}


// C������������View ��ӡ

BOOL C������������View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ�� CEditView ׼��
	return CEditView::OnPreparePrinting(pInfo);
}

void C������������View::OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo)
{
	// Ĭ�� CEditView ��ʼ��ӡ
	CEditView::OnBeginPrinting(pDC, pInfo);
}

void C������������View::OnEndPrinting(CDC* pDC, CPrintInfo* pInfo)
{
	// Ĭ�� CEditView ������ӡ
	CEditView::OnEndPrinting(pDC, pInfo);
}


// C������������View ���

#ifdef _DEBUG
void C������������View::AssertValid() const
{
	CEditView::AssertValid();
}

void C������������View::Dump(CDumpContext& dc) const
{
	CEditView::Dump(dc);
}

C������������Doc* C������������View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(C������������Doc)));
	return (C������������Doc*)m_pDocument;
}
#endif //_DEBUG


// C������������View ��Ϣ�������


void C������������View::OnFontSet()
{
	// TODO: �ڴ���������������
	CPropSheet propSheet("��������",this,0);
	if(propSheet.DoModal()==IDOK)
	{
		//���ڻ�ȡ�б���е����������ַ���
		CString str;
		//��ȡ��ͼ���ڰ����ı༭�ؼ�
		CEdit &MessageBody=GetEditCtrl();
		LOGFONT logft;
		logft.lfHeight=propSheet.m_pageSize.m_nHeight;//����߶�
		logft.lfWidth=propSheet.m_pageSize.m_nWidth;//������
		logft.lfEscapement=0;//��б��
		//�Ƿ����
		logft.lfWeight=propSheet.m_pageEffect.m_bBold?FW_BOLD:FW_NORMAL;
		logft.lfItalic=propSheet.m_pageEffect.m_bItalic;//�Ƿ�б��
		logft.lfUnderline=0;//�������»���
		logft.lfStrikeOut=false;//������ɾ����
		//��ȡ�����б����ѡ�е���������
		propSheet.m_pageFont.m_lstFont.GetText(propSheet.m_pageFont.m_lstFont.GetCurSel(),str);
		//���������Ʒ���LOGFONT�ṹ�����
		strcpy(logft.lfFaceName,str);
		//����������
		pNewFont=new CFont;
		pNewFont->CreateFontIndirect(&logft);
		MessageBody.SetFont(pNewFont);//���ñ༭�ؼ����壬ʹ����Ч
	}
}


BOOL C������������View::DestroyWindow()
{
	// TODO: �ڴ����ר�ô����/����û���
	if(pNewFont)
		delete pNewFont;
	return CEditView::DestroyWindow();
}


// ��ȡ��������View.cpp : C��ȡ��������View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "��ȡ��������.h"
#endif

#include "��ȡ��������Doc.h"
#include "��ȡ��������View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// C��ȡ��������View

IMPLEMENT_DYNCREATE(C��ȡ��������View, CView)

BEGIN_MESSAGE_MAP(C��ȡ��������View, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_COMMAND(ID_FILE_OPEN, &C��ȡ��������View::OnFileOpen)
END_MESSAGE_MAP()

// C��ȡ��������View ����/����

C��ȡ��������View::C��ȡ��������View()
{
	// TODO: �ڴ˴���ӹ������

}

C��ȡ��������View::~C��ȡ��������View()
{
}

BOOL C��ȡ��������View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// C��ȡ��������View ����

void C��ȡ��������View::OnDraw(CDC* /*pDC*/)
{
	C��ȡ��������Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// C��ȡ��������View ��ӡ

BOOL C��ȡ��������View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void C��ȡ��������View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void C��ȡ��������View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}


// C��ȡ��������View ���

#ifdef _DEBUG
void C��ȡ��������View::AssertValid() const
{
	CView::AssertValid();
}

void C��ȡ��������View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

C��ȡ��������Doc* C��ȡ��������View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(C��ȡ��������Doc)));
	return (C��ȡ��������Doc*)m_pDocument;
}
#endif //_DEBUG


// C��ȡ��������View ��Ϣ�������


void C��ȡ��������View::OnFileOpen()
{
	// TODO: �ڴ���������������
	C��ȡ��������Doc *pDoc=GetDocument();
	ASSERT_VALID(pDoc);
	CString FilePathname;
	CString FileName;
	CDC *pDC=GetDC();
	CFile MyFile;
	CFileDialog dlg(true,_T("TXT"),_T("*.TXT"),OFN_HIDEREADONLY|OFN_OVERWRITEPROMPT,_T("�ı��ļ�(*.TXT)|*.TXT|"));
	if(IDOK==dlg.DoModal())
	{
		FilePathname.Format("%s %s","filepath:",dlg.GetPathName());
		FileName.Format("%s %s","Old file name:",dlg.GetFileName());
		MyFile.Open(dlg.GetFileName(),CFile::modeRead);
	}
	pDC->TextOutA(0,0,FileName);
	pDC->TextOutA(0,20,FilePathname);
	pDC->TextOutA(0,40,"�ļ��ѱ���");
}


// ѧ����¼Doc.cpp : Cѧ����¼Doc ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "ѧ����¼.h"
#endif

#include "ѧ����¼Doc.h"
#include "CaddDlg.h"

#include <propkey.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// Cѧ����¼Doc

IMPLEMENT_DYNCREATE(Cѧ����¼Doc, CDocument)

BEGIN_MESSAGE_MAP(Cѧ����¼Doc, CDocument)
	ON_COMMAND(ID_STUREC_ADD, &Cѧ����¼Doc::OnSturecAdd)
END_MESSAGE_MAP()


// Cѧ����¼Doc ����/����

Cѧ����¼Doc::Cѧ����¼Doc()
{
	// TODO: �ڴ����һ���Թ������

}

Cѧ����¼Doc::~Cѧ����¼Doc()
{
	int nIndex=GetAllRecNum();
	while(nIndex--)
		delete m_stuObArray.GetAt(nIndex);
	m_stuObArray.RemoveAll();
}

BOOL Cѧ����¼Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: �ڴ�������³�ʼ������
	// (SDI �ĵ������ø��ĵ�)

	return TRUE;
}




// Cѧ����¼Doc ���л�

void Cѧ����¼Doc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: �ڴ���Ӵ洢����
		m_stuObArray.Serialize(ar);
	}
	else
	{
		// TODO: �ڴ���Ӽ��ش���
		m_stuObArray.Serialize(ar);
	}
}

#ifdef SHARED_HANDLERS

// ����ͼ��֧��
void Cѧ����¼Doc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
{
	// �޸Ĵ˴����Ի����ĵ�����
	dc.FillSolidRect(lprcBounds, RGB(255, 255, 255));

	CString strText = _T("TODO: implement thumbnail drawing here");
	LOGFONT lf;

	CFont* pDefaultGUIFont = CFont::FromHandle((HFONT) GetStockObject(DEFAULT_GUI_FONT));
	pDefaultGUIFont->GetLogFont(&lf);
	lf.lfHeight = 36;

	CFont fontDraw;
	fontDraw.CreateFontIndirect(&lf);

	CFont* pOldFont = dc.SelectObject(&fontDraw);
	dc.DrawText(strText, lprcBounds, DT_CENTER | DT_WORDBREAK);
	dc.SelectObject(pOldFont);
}

// ������������֧��
void Cѧ����¼Doc::InitializeSearchContent()
{
	CString strSearchContent;
	// ���ĵ����������������ݡ�
	// ���ݲ���Ӧ�ɡ�;���ָ�

	// ����:  strSearchContent = _T("point;rectangle;circle;ole object;")��
	SetSearchContent(strSearchContent);
}

void Cѧ����¼Doc::SetSearchContent(const CString& value)
{
	if (value.IsEmpty())
	{
		RemoveChunk(PKEY_Search_Contents.fmtid, PKEY_Search_Contents.pid);
	}
	else
	{
		CMFCFilterChunkValueImpl *pChunk = NULL;
		ATLTRY(pChunk = new CMFCFilterChunkValueImpl);
		if (pChunk != NULL)
		{
			pChunk->SetTextValue(PKEY_Search_Contents, value, CHUNK_TEXT);
			SetChunkValue(pChunk);
		}
	}
}

#endif // SHARED_HANDLERS

// Cѧ����¼Doc ���

#ifdef _DEBUG
void Cѧ����¼Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void Cѧ����¼Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// Cѧ����¼Doc ����



CStudent::CStudent(CString name,CString id,float f1,float f2,float f3)
{
	strName=name;
	strID=id;
	feng=f1;
	fmat=f2;
	fcom=f3;
	fAverage=(float)((f1+f2+f3)/3);
}
void CStudent::Display(int y,CDC *pDC)
{
	CString str;
	str.Format("%s %s %f %f %f %f",strName,strID,feng,fmat,fcom,fAverage);
	pDC->TextOutA(0,y,str);
}
IMPLEMENT_SERIAL(CStudent,CObject,1);
void CStudent::Serialize(CArchive &ar)
{
	if(ar.IsStoring())
		ar<<strName<<strID<<feng<<fmat<<fcom<<fAverage;//���ļ�д��
	else
		ar>>strName>>strID>>feng>>fmat>>fcom>>fAverage;//���ļ���ȡ
}

void Cѧ����¼Doc::OnSturecAdd()
{
	// TODO: �ڴ���������������
	CaddDlg dlg;
	if(IDOK==dlg.DoModal())
	{
		CStudent *pStudent=new CStudent(dlg.m_strName,dlg.m_strID,dlg.m_feng,dlg.m_fmat,dlg.m_fcom);
		m_stuObArray.Add(pStudent);//��Ӽ�¼
		SetModifiedFlag();//�����ĵ����ı�־
		UpdateAllViews(NULL);
	}
}


CStudent* Cѧ����¼Doc::GetStudentAt(int nIndex)
{
	if((nIndex<0)||nIndex>m_stuObArray.GetUpperBound())
		return 0;
	return (CStudent *)m_stuObArray.GetAt(nIndex);
}


int Cѧ����¼Doc::GetAllRecNum(void)
{
	return m_stuObArray.GetSize();
}

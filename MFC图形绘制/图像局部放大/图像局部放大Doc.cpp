
// ͼ��ֲ��Ŵ�Doc.cpp : Cͼ��ֲ��Ŵ�Doc ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "ͼ��ֲ��Ŵ�.h"
#endif

#include "ͼ��ֲ��Ŵ�Doc.h"

#include <propkey.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// Cͼ��ֲ��Ŵ�Doc

IMPLEMENT_DYNCREATE(Cͼ��ֲ��Ŵ�Doc, CDocument)

BEGIN_MESSAGE_MAP(Cͼ��ֲ��Ŵ�Doc, CDocument)
END_MESSAGE_MAP()


// Cͼ��ֲ��Ŵ�Doc ����/����

Cͼ��ֲ��Ŵ�Doc::Cͼ��ֲ��Ŵ�Doc()
{
	// TODO: �ڴ����һ���Թ������

}

Cͼ��ֲ��Ŵ�Doc::~Cͼ��ֲ��Ŵ�Doc()
{
}

BOOL Cͼ��ֲ��Ŵ�Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: �ڴ�������³�ʼ������
	// (SDI �ĵ������ø��ĵ�)

	return TRUE;
}




// Cͼ��ֲ��Ŵ�Doc ���л�

void Cͼ��ֲ��Ŵ�Doc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: �ڴ���Ӵ洢����
	}
	else
	{
		// TODO: �ڴ���Ӽ��ش���
	}
}

#ifdef SHARED_HANDLERS

// ����ͼ��֧��
void Cͼ��ֲ��Ŵ�Doc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
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
void Cͼ��ֲ��Ŵ�Doc::InitializeSearchContent()
{
	CString strSearchContent;
	// ���ĵ����������������ݡ�
	// ���ݲ���Ӧ�ɡ�;���ָ�

	// ����:  strSearchContent = _T("point;rectangle;circle;ole object;")��
	SetSearchContent(strSearchContent);
}

void Cͼ��ֲ��Ŵ�Doc::SetSearchContent(const CString& value)
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

// Cͼ��ֲ��Ŵ�Doc ���

#ifdef _DEBUG
void Cͼ��ֲ��Ŵ�Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void Cͼ��ֲ��Ŵ�Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// Cͼ��ֲ��Ŵ�Doc ����

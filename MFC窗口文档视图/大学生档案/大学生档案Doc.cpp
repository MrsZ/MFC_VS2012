
// ��ѧ������Doc.cpp : C��ѧ������Doc ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "��ѧ������.h"
#endif

#include "��ѧ������Doc.h"

#include <propkey.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// C��ѧ������Doc

IMPLEMENT_DYNCREATE(C��ѧ������Doc, CDocument)

	BEGIN_MESSAGE_MAP(C��ѧ������Doc, CDocument)
	END_MESSAGE_MAP()


	// C��ѧ������Doc ����/����

	C��ѧ������Doc::C��ѧ������Doc()
	{
		// TODO: �ڴ����һ���Թ������
		for(int i=0;i<120;i++)
		{
			m_student[i].clas[0]=NULL;
			m_student[i].pro[0]=NULL;
			m_student[i].cla[0]=NULL;
			m_student[i].name[0]=NULL;
			m_student[i].stuid[0]=NULL;
			m_student[i].sex[0]=NULL;
			m_student[i].age[0]=NULL;
			m_student[i].tel[0]=NULL;
			m_student[i].pos[0]=NULL;
			m_student[i].school[0]=NULL;
		}
	}

	C��ѧ������Doc::~C��ѧ������Doc()
	{
	}

	BOOL C��ѧ������Doc::OnNewDocument()
	{
		if (!CDocument::OnNewDocument())
			return FALSE;

		// TODO: �ڴ�������³�ʼ������
		// (SDI �ĵ������ø��ĵ�)

		return TRUE;
	}




	// C��ѧ������Doc ���л�

	void C��ѧ������Doc::Serialize(CArchive& ar)
	{
		if (ar.IsStoring())
		{
			// TODO: �ڴ���Ӵ洢����
			for(int i=0;i<120;i++)
			{
				ar.Write(m_student[i].clas,10);
				ar.Write(m_student[i].pro,10);
				ar.Write(m_student[i].cla,10);
				ar.Write(m_student[i].stuid,20);
				ar.Write(m_student[i].name,10);
				ar.Write(m_student[i].sex,10);
				ar.Write(m_student[i].age,10);
				ar.Write(m_student[i].tel,20);
				ar.Write(m_student[i].pos,20);
				ar.Write(m_student[i].school,999);
			}
		}
		else
		{
			// TODO: �ڴ���Ӽ��ش���
			for(int i=0;i<120;i++)
			{
				ar.Read(m_student[i].clas,10);
				ar.Read(m_student[i].pro,10);
				ar.Read(m_student[i].cla,10);
				ar.Read(m_student[i].stuid,20);
				ar.Read(m_student[i].name,10);
				ar.Read(m_student[i].sex,10);
				ar.Read(m_student[i].age,10);
				ar.Read(m_student[i].tel,20);
				ar.Read(m_student[i].pos,20);
				ar.Read(m_student[i].school,999);
			}
		}
	}

#ifdef SHARED_HANDLERS

	// ����ͼ��֧��
	void C��ѧ������Doc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
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
	void C��ѧ������Doc::InitializeSearchContent()
	{
		CString strSearchContent;
		// ���ĵ����������������ݡ�
		// ���ݲ���Ӧ�ɡ�;���ָ�

		// ����:  strSearchContent = _T("point;rectangle;circle;ole object;")��
		SetSearchContent(strSearchContent);
	}

	void C��ѧ������Doc::SetSearchContent(const CString& value)
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

	// C��ѧ������Doc ���

#ifdef _DEBUG
	void C��ѧ������Doc::AssertValid() const
	{
		CDocument::AssertValid();
	}

	void C��ѧ������Doc::Dump(CDumpContext& dc) const
	{
		CDocument::Dump(dc);
	}
#endif //_DEBUG


	// C��ѧ������Doc ����

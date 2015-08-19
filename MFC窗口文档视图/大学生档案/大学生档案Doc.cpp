
// 大学生档案Doc.cpp : C大学生档案Doc 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "大学生档案.h"
#endif

#include "大学生档案Doc.h"

#include <propkey.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// C大学生档案Doc

IMPLEMENT_DYNCREATE(C大学生档案Doc, CDocument)

	BEGIN_MESSAGE_MAP(C大学生档案Doc, CDocument)
	END_MESSAGE_MAP()


	// C大学生档案Doc 构造/析构

	C大学生档案Doc::C大学生档案Doc()
	{
		// TODO: 在此添加一次性构造代码
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

	C大学生档案Doc::~C大学生档案Doc()
	{
	}

	BOOL C大学生档案Doc::OnNewDocument()
	{
		if (!CDocument::OnNewDocument())
			return FALSE;

		// TODO: 在此添加重新初始化代码
		// (SDI 文档将重用该文档)

		return TRUE;
	}




	// C大学生档案Doc 序列化

	void C大学生档案Doc::Serialize(CArchive& ar)
	{
		if (ar.IsStoring())
		{
			// TODO: 在此添加存储代码
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
			// TODO: 在此添加加载代码
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

	// 缩略图的支持
	void C大学生档案Doc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
	{
		// 修改此代码以绘制文档数据
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

	// 搜索处理程序的支持
	void C大学生档案Doc::InitializeSearchContent()
	{
		CString strSearchContent;
		// 从文档数据设置搜索内容。
		// 内容部分应由“;”分隔

		// 例如:  strSearchContent = _T("point;rectangle;circle;ole object;")；
		SetSearchContent(strSearchContent);
	}

	void C大学生档案Doc::SetSearchContent(const CString& value)
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

	// C大学生档案Doc 诊断

#ifdef _DEBUG
	void C大学生档案Doc::AssertValid() const
	{
		CDocument::AssertValid();
	}

	void C大学生档案Doc::Dump(CDumpContext& dc) const
	{
		CDocument::Dump(dc);
	}
#endif //_DEBUG


	// C大学生档案Doc 命令

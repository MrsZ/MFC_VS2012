
// 学生记录Doc.cpp : C学生记录Doc 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "学生记录.h"
#endif

#include "学生记录Doc.h"
#include "CaddDlg.h"

#include <propkey.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// C学生记录Doc

IMPLEMENT_DYNCREATE(C学生记录Doc, CDocument)

BEGIN_MESSAGE_MAP(C学生记录Doc, CDocument)
	ON_COMMAND(ID_STUREC_ADD, &C学生记录Doc::OnSturecAdd)
END_MESSAGE_MAP()


// C学生记录Doc 构造/析构

C学生记录Doc::C学生记录Doc()
{
	// TODO: 在此添加一次性构造代码

}

C学生记录Doc::~C学生记录Doc()
{
	int nIndex=GetAllRecNum();
	while(nIndex--)
		delete m_stuObArray.GetAt(nIndex);
	m_stuObArray.RemoveAll();
}

BOOL C学生记录Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: 在此添加重新初始化代码
	// (SDI 文档将重用该文档)

	return TRUE;
}




// C学生记录Doc 序列化

void C学生记录Doc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: 在此添加存储代码
		m_stuObArray.Serialize(ar);
	}
	else
	{
		// TODO: 在此添加加载代码
		m_stuObArray.Serialize(ar);
	}
}

#ifdef SHARED_HANDLERS

// 缩略图的支持
void C学生记录Doc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
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
void C学生记录Doc::InitializeSearchContent()
{
	CString strSearchContent;
	// 从文档数据设置搜索内容。
	// 内容部分应由“;”分隔

	// 例如:  strSearchContent = _T("point;rectangle;circle;ole object;")；
	SetSearchContent(strSearchContent);
}

void C学生记录Doc::SetSearchContent(const CString& value)
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

// C学生记录Doc 诊断

#ifdef _DEBUG
void C学生记录Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void C学生记录Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// C学生记录Doc 命令



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
		ar<<strName<<strID<<feng<<fmat<<fcom<<fAverage;//向文件写入
	else
		ar>>strName>>strID>>feng>>fmat>>fcom>>fAverage;//从文件读取
}

void C学生记录Doc::OnSturecAdd()
{
	// TODO: 在此添加命令处理程序代码
	CaddDlg dlg;
	if(IDOK==dlg.DoModal())
	{
		CStudent *pStudent=new CStudent(dlg.m_strName,dlg.m_strID,dlg.m_feng,dlg.m_fmat,dlg.m_fcom);
		m_stuObArray.Add(pStudent);//添加记录
		SetModifiedFlag();//设置文档更改标志
		UpdateAllViews(NULL);
	}
}


CStudent* C学生记录Doc::GetStudentAt(int nIndex)
{
	if((nIndex<0)||nIndex>m_stuObArray.GetUpperBound())
		return 0;
	return (CStudent *)m_stuObArray.GetAt(nIndex);
}


int C学生记录Doc::GetAllRecNum(void)
{
	return m_stuObArray.GetSize();
}

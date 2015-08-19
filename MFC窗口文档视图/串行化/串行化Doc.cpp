
// 串行化Doc.cpp : C串行化Doc 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "串行化.h"
#endif

#include "串行化Doc.h"

#include <propkey.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// C串行化Doc

IMPLEMENT_DYNCREATE(C串行化Doc, CDocument)

BEGIN_MESSAGE_MAP(C串行化Doc, CDocument)
END_MESSAGE_MAP()


// C串行化Doc 构造/析构

C串行化Doc::C串行化Doc()
{
	// TODO: 在此添加一次性构造代码

}

C串行化Doc::~C串行化Doc()
{
}

BOOL C串行化Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: 在此添加重新初始化代码
	// (SDI 文档将重用该文档)

	return TRUE;
}




// C串行化Doc 序列化

void C串行化Doc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: 在此添加存储代码
		for(int i=0;i<sizeof(m_ch);i++)
			ar<<m_ch[i];
	}
	else
	{
		// TODO: 在此添加加载代码
		for(int i=0;i<sizeof(m_ch);i++)
		{
			//文本内容输入到数组中
			ar>>m_ch[i];
			CString str;
			//以文本字符串格式将数组内容写入
			str.Format(_T("%s"),m_ch);
			AfxMessageBox(str);
		}
	}
}

#ifdef SHARED_HANDLERS

// 缩略图的支持
void C串行化Doc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
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
void C串行化Doc::InitializeSearchContent()
{
	CString strSearchContent;
	// 从文档数据设置搜索内容。
	// 内容部分应由“;”分隔

	// 例如:  strSearchContent = _T("point;rectangle;circle;ole object;")；
	SetSearchContent(strSearchContent);
}

void C串行化Doc::SetSearchContent(const CString& value)
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

// C串行化Doc 诊断

#ifdef _DEBUG
void C串行化Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void C串行化Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// C串行化Doc 命令

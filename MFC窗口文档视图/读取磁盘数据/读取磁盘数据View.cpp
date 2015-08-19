
// 读取磁盘数据View.cpp : C读取磁盘数据View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "读取磁盘数据.h"
#endif

#include "读取磁盘数据Doc.h"
#include "读取磁盘数据View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// C读取磁盘数据View

IMPLEMENT_DYNCREATE(C读取磁盘数据View, CView)

BEGIN_MESSAGE_MAP(C读取磁盘数据View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_COMMAND(ID_FILE_OPEN, &C读取磁盘数据View::OnFileOpen)
END_MESSAGE_MAP()

// C读取磁盘数据View 构造/析构

C读取磁盘数据View::C读取磁盘数据View()
{
	// TODO: 在此处添加构造代码

}

C读取磁盘数据View::~C读取磁盘数据View()
{
}

BOOL C读取磁盘数据View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// C读取磁盘数据View 绘制

void C读取磁盘数据View::OnDraw(CDC* /*pDC*/)
{
	C读取磁盘数据Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// C读取磁盘数据View 打印

BOOL C读取磁盘数据View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void C读取磁盘数据View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void C读取磁盘数据View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// C读取磁盘数据View 诊断

#ifdef _DEBUG
void C读取磁盘数据View::AssertValid() const
{
	CView::AssertValid();
}

void C读取磁盘数据View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

C读取磁盘数据Doc* C读取磁盘数据View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(C读取磁盘数据Doc)));
	return (C读取磁盘数据Doc*)m_pDocument;
}
#endif //_DEBUG


// C读取磁盘数据View 消息处理程序


void C读取磁盘数据View::OnFileOpen()
{
	// TODO: 在此添加命令处理程序代码
	C读取磁盘数据Doc *pDoc=GetDocument();
	ASSERT_VALID(pDoc);
	CString FilePathname;
	CString FileName;
	CDC *pDC=GetDC();
	CFile MyFile;
	CFileDialog dlg(true,_T("TXT"),_T("*.TXT"),OFN_HIDEREADONLY|OFN_OVERWRITEPROMPT,_T("文本文件(*.TXT)|*.TXT|"));
	if(IDOK==dlg.DoModal())
	{
		FilePathname.Format("%s %s","filepath:",dlg.GetPathName());
		FileName.Format("%s %s","Old file name:",dlg.GetFileName());
		MyFile.Open(dlg.GetFileName(),CFile::modeRead);
	}
	pDC->TextOutA(0,0,FileName);
	pDC->TextOutA(0,20,FilePathname);
	pDC->TextOutA(0,40,"文件已被打开");
}

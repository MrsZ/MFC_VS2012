
// 字体显示View.cpp : C字体显示View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "字体显示.h"
#endif

#include "字体显示Doc.h"
#include "字体显示View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// C字体显示View

IMPLEMENT_DYNCREATE(C字体显示View, CView)

BEGIN_MESSAGE_MAP(C字体显示View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// C字体显示View 构造/析构

C字体显示View::C字体显示View()
{
	// TODO: 在此处添加构造代码

}

C字体显示View::~C字体显示View()
{
}

BOOL C字体显示View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// C字体显示View 绘制

void C字体显示View::OnDraw(CDC* pDC)
{
	C字体显示Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
	pDC->SetBkColor(RGB(240,240,250));
	pDC->SetTextColor(RGB(255,0,0));
	int ny=260;
	int ndl=40;
	for(int i=32;i>=20;i-=4)
	{
		FontOut(pDC,ny,i,ndl);
	}
}


// C字体显示View 打印

BOOL C字体显示View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void C字体显示View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void C字体显示View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// C字体显示View 诊断

#ifdef _DEBUG
void C字体显示View::AssertValid() const
{
	CView::AssertValid();
}

void C字体显示View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

C字体显示Doc* C字体显示View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(C字体显示Doc)));
	return (C字体显示Doc*)m_pDocument;
}
#endif //_DEBUG


// C字体显示View 消息处理程序


void C字体显示View::FontOut(CDC * pDC, int & nHeight, int nPoints, int dline)
{
	TEXTMETRIC textM;
	CFont font;
	CString str;
	font.CreateFontA(-nPoints,0,dline,0,400,FALSE,FALSE,0,ANSI_CHARSET,OUT_DEFAULT_PRECIS,CLIP_DEFAULT_PRECIS,
		DEFAULT_QUALITY,DEFAULT_PITCH|FF_SWISS,"宋体");
	CFont *poldfont=(CFont *)pDC->SelectObject(&font);
	pDC->GetTextMetrics(&textM);
	str.Format("这是%d点阵宋体字",nPoints);
	pDC->TextOutA(20,nHeight,str);
	nHeight-=textM.tmHeight+textM.tmExternalLeading;
	pDC->SelectObject(poldfont);
}

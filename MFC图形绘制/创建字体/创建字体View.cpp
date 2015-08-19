
// 创建字体View.cpp : C创建字体View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "创建字体.h"
#endif

#include "创建字体Doc.h"
#include "创建字体View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// C创建字体View

IMPLEMENT_DYNCREATE(C创建字体View, CView)

BEGIN_MESSAGE_MAP(C创建字体View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// C创建字体View 构造/析构

C创建字体View::C创建字体View()
{
	// TODO: 在此处添加构造代码

}

C创建字体View::~C创建字体View()
{
}

BOOL C创建字体View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// C创建字体View 绘制

void C创建字体View::OnDraw(CDC* pDC)
{
	C创建字体Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
	int cHeight;
	UINT position=0;
	for(UINT x=0;x<6;x++)
	{
		CFont font;
		cHeight=16+x*8;
		font.CreateFontA(-cHeight,0,0,0,FW_NORMAL,FALSE,FALSE,FALSE,ANSI_CHARSET,OUT_DEFAULT_PRECIS,
			CLIP_DEFAULT_PRECIS,DEFAULT_QUALITY,DEFAULT_PITCH|FF_MODERN, "Times New Roman");
		CFont *oldFont=pDC->SelectObject(&font);
		position+=cHeight;
		pDC->TextOutA(20,position,"时代先锋");
		pDC->SelectObject(oldFont);
	}
}


// C创建字体View 打印

BOOL C创建字体View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void C创建字体View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void C创建字体View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// C创建字体View 诊断

#ifdef _DEBUG
void C创建字体View::AssertValid() const
{
	CView::AssertValid();
}

void C创建字体View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

C创建字体Doc* C创建字体View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(C创建字体Doc)));
	return (C创建字体Doc*)m_pDocument;
}
#endif //_DEBUG


// C创建字体View 消息处理程序

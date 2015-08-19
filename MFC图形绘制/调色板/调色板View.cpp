
// 调色板View.cpp : C调色板View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "调色板.h"
#endif

#include "调色板Doc.h"
#include "调色板View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// C调色板View

IMPLEMENT_DYNCREATE(C调色板View, CView)

BEGIN_MESSAGE_MAP(C调色板View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// C调色板View 构造/析构

C调色板View::C调色板View()
{
	// TODO: 在此处添加构造代码

}

C调色板View::~C调色板View()
{
}

BOOL C调色板View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// C调色板View 绘制

void C调色板View::OnDraw(CDC* pDC)
{
	C调色板Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
	CPalette m_Palette;
	CBrush brush,*pOldBrush;
	int x,y;
	pDC->SelectPalette(&m_Palette,FALSE);
	pDC->RealizePalette();
	pDC->SelectStockObject(BLACK_PEN);
	for(int i=0;i<256;i++)
	{
		x=(i%16)*16;
		y=(i/16)*16;
		brush.CreateSolidBrush(PALETTEINDEX(i));
		pOldBrush =pDC->SelectObject(&brush);
		pDC->Rectangle(x,y,x+16,y+16);
		pDC->SelectObject(pOldBrush);
		brush.DeleteObject();
	}
}


// C调色板View 打印

BOOL C调色板View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void C调色板View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void C调色板View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// C调色板View 诊断

#ifdef _DEBUG
void C调色板View::AssertValid() const
{
	CView::AssertValid();
}

void C调色板View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

C调色板Doc* C调色板View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(C调色板Doc)));
	return (C调色板Doc*)m_pDocument;
}
#endif //_DEBUG


// C调色板View 消息处理程序

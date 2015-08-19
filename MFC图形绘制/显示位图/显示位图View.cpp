
// 显示位图View.cpp : C显示位图View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "显示位图.h"
#endif

#include "显示位图Doc.h"
#include "显示位图View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// C显示位图View

IMPLEMENT_DYNCREATE(C显示位图View, CView)

BEGIN_MESSAGE_MAP(C显示位图View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// C显示位图View 构造/析构

C显示位图View::C显示位图View()
{
	// TODO: 在此处添加构造代码

}

C显示位图View::~C显示位图View()
{
}

BOOL C显示位图View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// C显示位图View 绘制

void C显示位图View::OnDraw(CDC* pDC)
{
	C显示位图Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
	CBitmap m_bmp;
	m_bmp.LoadBitmapW(IDB_BITMAP1);
	BITMAP bm;
	m_bmp.GetObject(sizeof(BITMAP),&bm);
	CDC dcMem;
	dcMem.CreateCompatibleDC(pDC);
	CBitmap *pOldbmp=dcMem.SelectObject(&m_bmp);
	pDC->BitBlt(60,60,bm.bmWidth,bm.bmHeight,&dcMem,0,0,SRCCOPY);
	dcMem.SelectObject(pOldbmp);
}


// C显示位图View 打印

BOOL C显示位图View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void C显示位图View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void C显示位图View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// C显示位图View 诊断

#ifdef _DEBUG
void C显示位图View::AssertValid() const
{
	CView::AssertValid();
}

void C显示位图View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

C显示位图Doc* C显示位图View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(C显示位图Doc)));
	return (C显示位图Doc*)m_pDocument;
}
#endif //_DEBUG


// C显示位图View 消息处理程序

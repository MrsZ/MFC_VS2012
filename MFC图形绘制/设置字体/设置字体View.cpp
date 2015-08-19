
// 设置字体View.cpp : C设置字体View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "设置字体.h"
#endif

#include "设置字体Doc.h"
#include "设置字体View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// C设置字体View

IMPLEMENT_DYNCREATE(C设置字体View, CScrollView)

BEGIN_MESSAGE_MAP(C设置字体View, CScrollView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CScrollView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CScrollView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CScrollView::OnFilePrintPreview)
	ON_WM_LBUTTONDBLCLK()
END_MESSAGE_MAP()

// C设置字体View 构造/析构

C设置字体View::C设置字体View()
{
	// TODO: 在此处添加构造代码
	memset(&m_lfText,0,sizeof(LOGFONT));
	m_lfText.lfHeight=-12;
	m_lfText.lfCharSet=GB2312_CHARSET;
	strcmp(m_lfText.lfFaceName,"宋体");
}

C设置字体View::~C设置字体View()
{
}

BOOL C设置字体View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CScrollView::PreCreateWindow(cs);
}

// C设置字体View 绘制

void C设置字体View::OnDraw(CDC* pDC)
{
	C设置字体Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
	CFont cf;
	cf.CreateFontIndirectA(&m_lfText);
	CFont *oldFont=pDC->SelectObject(&cf);
	//计算每行的高度
	TEXTMETRIC tm;
	pDC->GetTextMetrics(&tm);
	int lineHeight=tm.tmHeight+tm.tmExternalLeading;
	int y=0;
	//一个tab设置为4个字符
	int tab=tm.tmAveCharWidth*4;
	int lineMaxWidth=0;
	CString str;
	CSize lineSize(0,0);
	for(int i=0;i<pDoc->m_strContents.GetSize();i++)
	{
		str=pDoc->m_strContents.GetAt(i);
		pDC->TabbedTextOutA(0,y,str,1,&tab,0);
		str=str+"A";
		lineSize=pDC->GetTabbedTextExtentA(str,1,&tab);
		if(lineMaxWidth<lineSize.cx)
			lineMaxWidth=lineSize.cx;
		y+=lineHeight;
	}
	pDC->SelectObject(oldFont);
	int nLines=pDoc->m_strContents.GetSize()+1;
	CSize sizeTotal;
	sizeTotal.cx=lineMaxWidth;
	sizeTotal.cy=lineHeight*nLines;
	SetScrollSizes(MM_TEXT,sizeTotal);
}

void C设置字体View::OnInitialUpdate()
{
	CScrollView::OnInitialUpdate();

	CSize sizeTotal;
	// TODO: 计算此视图的合计大小
	sizeTotal.cx = sizeTotal.cy = 100;
	SetScrollSizes(MM_TEXT, sizeTotal);
}


// C设置字体View 打印

BOOL C设置字体View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void C设置字体View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void C设置字体View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// C设置字体View 诊断

#ifdef _DEBUG
void C设置字体View::AssertValid() const
{
	CScrollView::AssertValid();
}

void C设置字体View::Dump(CDumpContext& dc) const
{
	CScrollView::Dump(dc);
}

C设置字体Doc* C设置字体View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(C设置字体Doc)));
	return (C设置字体Doc*)m_pDocument;
}
#endif //_DEBUG


// C设置字体View 消息处理程序


void C设置字体View::OnLButtonDblClk(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CFontDialog dlg(&m_lfText);
	if(dlg.DoModal()==IDOK)
	{
		dlg.GetCurrentFont(&m_lfText);
		Invalidate();
	}
	CScrollView::OnLButtonDblClk(nFlags, point);
}

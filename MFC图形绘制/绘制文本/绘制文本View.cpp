
// 绘制文本View.cpp : C绘制文本View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "绘制文本.h"
#endif

#include "绘制文本Doc.h"
#include "绘制文本View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// C绘制文本View

IMPLEMENT_DYNCREATE(C绘制文本View, CView)

BEGIN_MESSAGE_MAP(C绘制文本View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// C绘制文本View 构造/析构

C绘制文本View::C绘制文本View()
{
	// TODO: 在此处添加构造代码

}

C绘制文本View::~C绘制文本View()
{
}

BOOL C绘制文本View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// C绘制文本View 绘制

void C绘制文本View::OnDraw(CDC* pDC)
{
	C绘制文本Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
	CRect rc(10,10,200,140);
	pDC->Rectangle(rc);
	pDC->DrawText("单行文本居中",rc,DT_CENTER|DT_VCENTER|DT_SINGLELINE);
	rc.OffsetRect(200,0);
	pDC->Rectangle(rc);
	int nTab=40;
	pDC->TabbedTextOutA(rc.left,rc.top,"绘制\tTab\t文本\t示例",1,&nTab,rc.left);
	nTab=80;
	pDC->TabbedTextOutA(rc.left,rc.top+20,"绘制\tTab\t文本\t示例",1,&nTab,rc.left);
	pDC->TabbedTextOutA(rc.left,rc.top+40,"绘制\tTab\t文本\t示例",0,NULL,0);
}


// C绘制文本View 打印

BOOL C绘制文本View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void C绘制文本View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void C绘制文本View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// C绘制文本View 诊断

#ifdef _DEBUG
void C绘制文本View::AssertValid() const
{
	CView::AssertValid();
}

void C绘制文本View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

C绘制文本Doc* C绘制文本View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(C绘制文本Doc)));
	return (C绘制文本Doc*)m_pDocument;
}
#endif //_DEBUG


// C绘制文本View 消息处理程序

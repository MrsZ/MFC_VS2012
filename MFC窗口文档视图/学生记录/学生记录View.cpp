
// 学生记录View.cpp : C学生记录View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "学生记录.h"
#endif

#include "学生记录Doc.h"
#include "学生记录View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// C学生记录View

IMPLEMENT_DYNCREATE(C学生记录View, CView)

BEGIN_MESSAGE_MAP(C学生记录View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// C学生记录View 构造/析构

C学生记录View::C学生记录View()
{
	// TODO: 在此处添加构造代码

}

C学生记录View::~C学生记录View()
{
}

BOOL C学生记录View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// C学生记录View 绘制

void C学生记录View::OnDraw(CDC* pDC)
{
	C学生记录Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	/*if (!pDoc)
		return;*/

	// TODO: 在此处为本机数据添加绘制代码
	int y=0;
	for(int nIndex=0;nIndex<pDoc->GetAllRecNum();nIndex++)
	{
		pDoc->GetStudentAt(nIndex)->Display(y,pDC);
		y+=16;
	}
}


// C学生记录View 打印

BOOL C学生记录View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void C学生记录View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void C学生记录View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// C学生记录View 诊断

#ifdef _DEBUG
void C学生记录View::AssertValid() const
{
	CView::AssertValid();
}

void C学生记录View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

C学生记录Doc* C学生记录View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(C学生记录Doc)));
	return (C学生记录Doc*)m_pDocument;
}
#endif //_DEBUG


// C学生记录View 消息处理程序


// 图片控件View.cpp : C图片控件View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "图片控件.h"
#endif

#include "图片控件Doc.h"
#include "图片控件View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// C图片控件View

IMPLEMENT_DYNCREATE(C图片控件View, CView)

BEGIN_MESSAGE_MAP(C图片控件View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &C图片控件View::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_COMMAND(ID_DLG, &C图片控件View::OnDlg)
END_MESSAGE_MAP()

// C图片控件View 构造/析构

C图片控件View::C图片控件View()
{
	// TODO: 在此处添加构造代码

}

C图片控件View::~C图片控件View()
{
}

BOOL C图片控件View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// C图片控件View 绘制

void C图片控件View::OnDraw(CDC* /*pDC*/)
{
	C图片控件Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// C图片控件View 打印


void C图片控件View::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL C图片控件View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void C图片控件View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void C图片控件View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}

void C图片控件View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void C图片控件View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// C图片控件View 诊断

#ifdef _DEBUG
void C图片控件View::AssertValid() const
{
	CView::AssertValid();
}

void C图片控件View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

C图片控件Doc* C图片控件View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(C图片控件Doc)));
	return (C图片控件Doc*)m_pDocument;
}
#endif //_DEBUG


// C图片控件View 消息处理程序


void C图片控件View::OnDlg()
{
	// TODO: 在此添加命令处理程序代码
	dlg=new CMyDlg(this);
	dlg->Create(IDD_DIALOG1);
	dlg->ShowWindow(SW_RESTORE);
}


// 加载网页View.cpp : C加载网页View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "加载网页.h"
#endif

#include "加载网页Doc.h"
#include "加载网页View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// C加载网页View

IMPLEMENT_DYNCREATE(C加载网页View, CHtmlView)

BEGIN_MESSAGE_MAP(C加载网页View, CHtmlView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CHtmlView::OnFilePrint)
	ON_COMMAND(ID_FILE_OPEN, &C加载网页View::OnFileOpen)
END_MESSAGE_MAP()

// C加载网页View 构造/析构

C加载网页View::C加载网页View()
{
	// TODO: 在此处添加构造代码

}

C加载网页View::~C加载网页View()
{
}

BOOL C加载网页View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CHtmlView::PreCreateWindow(cs);
}

void C加载网页View::OnInitialUpdate()
{
	CHtmlView::OnInitialUpdate();

	Navigate2(_T("http://www.msdn.microsoft.com/visualc/"),NULL,NULL);
}


// C加载网页View 打印



// C加载网页View 诊断

#ifdef _DEBUG
void C加载网页View::AssertValid() const
{
	CHtmlView::AssertValid();
}

void C加载网页View::Dump(CDumpContext& dc) const
{
	CHtmlView::Dump(dc);
}

C加载网页Doc* C加载网页View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(C加载网页Doc)));
	return (C加载网页Doc*)m_pDocument;
}
#endif //_DEBUG


// C加载网页View 消息处理程序


void C加载网页View::OnFileOpen()
{
	// TODO: 在此添加命令处理程序代码
	CFileDialog dlg(true,_T("htm"),_T("*.htm"),OFN_HIDEREADONLY|OFN_OVERWRITEPROMPT,_T("网页(*.htm)|*.htm|"));
	if(IDOK==dlg.DoModal())
	{
		Navigate2(dlg.GetPathName(),NULL,NULL);
	}
}

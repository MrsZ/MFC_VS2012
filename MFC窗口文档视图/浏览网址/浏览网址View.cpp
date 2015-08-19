
// 浏览网址View.cpp : C浏览网址View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "浏览网址.h"
#endif

#include "浏览网址Doc.h"
#include "浏览网址View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// C浏览网址View

IMPLEMENT_DYNCREATE(C浏览网址View, CHtmlView)

BEGIN_MESSAGE_MAP(C浏览网址View, CHtmlView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CHtmlView::OnFilePrint)
	ON_COMMAND_RANGE(IDC_BUTTON1,IDC_BUTTON6,OnMyAddress)
END_MESSAGE_MAP()

// C浏览网址View 构造/析构

C浏览网址View::C浏览网址View()
{
	// TODO: 在此处添加构造代码
	MyAddressStr="http://www.baidu.com";
}

C浏览网址View::~C浏览网址View()
{
}

BOOL C浏览网址View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CHtmlView::PreCreateWindow(cs);
}

void C浏览网址View::OnInitialUpdate()
{
	CHtmlView::OnInitialUpdate();

	Navigate2(_T(MyAddressStr),NULL,NULL);
}


// C浏览网址View 打印



// C浏览网址View 诊断

#ifdef _DEBUG
void C浏览网址View::AssertValid() const
{
	CHtmlView::AssertValid();
}

void C浏览网址View::Dump(CDumpContext& dc) const
{
	CHtmlView::Dump(dc);
}

C浏览网址Doc* C浏览网址View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(C浏览网址Doc)));
	return (C浏览网址Doc*)m_pDocument;
}
#endif //_DEBUG


// C浏览网址View 消息处理程序
void C浏览网址View::OnMyAddress(UINT nID)
{
	switch(nID)
	{
	case IDC_BUTTON1:
		MyAddressStr="http://www.baidu.com";break;
	case IDC_BUTTON2:
		MyAddressStr="http://www.sohu.com";break;
	case IDC_BUTTON3:
		MyAddressStr="http://www.taobao.com";break;
	case IDC_BUTTON4:
		MyAddressStr="http://www.sina.com";break;
	case IDC_BUTTON5:
		MyAddressStr="http://www.yahoo.com.cn";break;
	case IDC_BUTTON6:
		MyAddressStr="http://www.chinafilm.com";break;
	}
	Navigate2(_T(MyAddressStr),NULL,NULL);
	Refresh();
}
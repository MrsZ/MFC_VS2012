
// 背景图View.cpp : C背景图View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "背景图.h"
#endif

#include "背景图Doc.h"
#include "背景图View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// C背景图View

IMPLEMENT_DYNCREATE(C背景图View, CFormView)

BEGIN_MESSAGE_MAP(C背景图View, CFormView)
	ON_BN_CLICKED(IDC_BUTTON1, &C背景图View::OnClickedButton1)
END_MESSAGE_MAP()

// C背景图View 构造/析构

C背景图View::C背景图View()
	: CFormView(C背景图View::IDD)
{
	// TODO: 在此处添加构造代码

}

C背景图View::~C背景图View()
{
}

void C背景图View::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
}

BOOL C背景图View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CFormView::PreCreateWindow(cs);
}

void C背景图View::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

}


// C背景图View 诊断

#ifdef _DEBUG
void C背景图View::AssertValid() const
{
	CFormView::AssertValid();
}

void C背景图View::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

C背景图Doc* C背景图View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(C背景图Doc)));
	return (C背景图Doc*)m_pDocument;
}
#endif //_DEBUG


// C背景图View 消息处理程序


void C背景图View::OnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	CDC *pDC=GetDC();//显示设备上下文的句柄
	//HBITMAP保存位图信息的内存域的句柄
	HBITMAP hBitmap=(HBITMAP)LoadImage(NULL,_T("2.bmp"),IMAGE_BITMAP,0,0,LR_CREATEDIBSECTION|LR_DEFAULTSIZE
		|LR_LOADFROMFILE);
	m_bitmap.Attach(hBitmap);//将HBITMAP选入类中
	BITMAP bm;
	m_bitmap.GetBitmap(&bm);//获得位图
	CDC dcImage;
	if(!dcImage.CreateCompatibleDC(pDC))
		return;
	CBitmap *pOldBitmap=dcImage.SelectObject(&m_bitmap);//选择一个GDI绘制对象首址
	pDC->BitBlt(0,0,bm.bmWidth,bm.bmHeight,&dcImage,0,0,SRCCOPY);//填充窗口背景
	dcImage.SelectObject(pOldBitmap);//选择一个GDI绘制对象
	DeleteObject(m_bitmap.Detach());//释放位图存储空间
}

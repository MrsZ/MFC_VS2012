
// 更改字体设置View.cpp : C更改字体设置View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "更改字体设置.h"
#endif

#include "更改字体设置Doc.h"
#include "更改字体设置View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// C更改字体设置View

IMPLEMENT_DYNCREATE(C更改字体设置View, CEditView)

BEGIN_MESSAGE_MAP(C更改字体设置View, CEditView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CEditView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CEditView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CEditView::OnFilePrintPreview)
	ON_COMMAND(ID_FONT_SET, &C更改字体设置View::OnFontSet)
END_MESSAGE_MAP()

// C更改字体设置View 构造/析构

C更改字体设置View::C更改字体设置View()
{
	// TODO: 在此处添加构造代码

}

C更改字体设置View::~C更改字体设置View()
{
}

BOOL C更改字体设置View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	BOOL bPreCreated = CEditView::PreCreateWindow(cs);
	cs.style &= ~(ES_AUTOHSCROLL|WS_HSCROLL);	// 启用换行

	return bPreCreated;
}


// C更改字体设置View 打印

BOOL C更改字体设置View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认 CEditView 准备
	return CEditView::OnPreparePrinting(pInfo);
}

void C更改字体设置View::OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo)
{
	// 默认 CEditView 开始打印
	CEditView::OnBeginPrinting(pDC, pInfo);
}

void C更改字体设置View::OnEndPrinting(CDC* pDC, CPrintInfo* pInfo)
{
	// 默认 CEditView 结束打印
	CEditView::OnEndPrinting(pDC, pInfo);
}


// C更改字体设置View 诊断

#ifdef _DEBUG
void C更改字体设置View::AssertValid() const
{
	CEditView::AssertValid();
}

void C更改字体设置View::Dump(CDumpContext& dc) const
{
	CEditView::Dump(dc);
}

C更改字体设置Doc* C更改字体设置View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(C更改字体设置Doc)));
	return (C更改字体设置Doc*)m_pDocument;
}
#endif //_DEBUG


// C更改字体设置View 消息处理程序


void C更改字体设置View::OnFontSet()
{
	// TODO: 在此添加命令处理程序代码
	CPropSheet propSheet("字体设置",this,0);
	if(propSheet.DoModal()==IDOK)
	{
		//用于获取列表框中的字体名称字符串
		CString str;
		//获取视图窗口包含的编辑控件
		CEdit &MessageBody=GetEditCtrl();
		LOGFONT logft;
		logft.lfHeight=propSheet.m_pageSize.m_nHeight;//字体高度
		logft.lfWidth=propSheet.m_pageSize.m_nWidth;//字体宽度
		logft.lfEscapement=0;//倾斜度
		//是否粗体
		logft.lfWeight=propSheet.m_pageEffect.m_bBold?FW_BOLD:FW_NORMAL;
		logft.lfItalic=propSheet.m_pageEffect.m_bItalic;//是否斜体
		logft.lfUnderline=0;//不创建下划线
		logft.lfStrikeOut=false;//不创建删除线
		//获取字体列表框中选中的字体名称
		propSheet.m_pageFont.m_lstFont.GetText(propSheet.m_pageFont.m_lstFont.GetCurSel(),str);
		//将字体名称放入LOGFONT结构体变量
		strcpy(logft.lfFaceName,str);
		//创建新字体
		pNewFont=new CFont;
		pNewFont->CreateFontIndirect(&logft);
		MessageBody.SetFont(pNewFont);//设置编辑控件字体，使其有效
	}
}


BOOL C更改字体设置View::DestroyWindow()
{
	// TODO: 在此添加专用代码和/或调用基类
	if(pNewFont)
		delete pNewFont;
	return CEditView::DestroyWindow();
}

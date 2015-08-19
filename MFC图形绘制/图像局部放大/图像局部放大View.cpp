
// 图像局部放大View.cpp : C图像局部放大View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "图像局部放大.h"
#endif

#include "图像局部放大Doc.h"
#include "图像局部放大View.h"
#include "MainFrm.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// C图像局部放大View

IMPLEMENT_DYNCREATE(C图像局部放大View, CView)

	BEGIN_MESSAGE_MAP(C图像局部放大View, CView)
		// 标准打印命令
		ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
		ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
		ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
		ON_WM_MOUSEMOVE()
		ON_WM_RBUTTONDOWN()
		ON_WM_LBUTTONDOWN()
	END_MESSAGE_MAP()

	// C图像局部放大View 构造/析构

	C图像局部放大View::C图像局部放大View()
	{
		// TODO: 在此处添加构造代码
		m_pdcMem=new CDC;
		m_pBitmap=new CBitmap;
		recover=true;
		s=30;
		d=45;
		mana=SRCCOPY;
	}

	C图像局部放大View::~C图像局部放大View()
	{
		delete m_pdcMem;
		delete m_pBitmap;
	}

	BOOL C图像局部放大View::PreCreateWindow(CREATESTRUCT& cs)
	{
		// TODO: 在此处通过修改
		//  CREATESTRUCT cs 来修改窗口类或样式

		return CView::PreCreateWindow(cs);
	}

	// C图像局部放大View 绘制

	void C图像局部放大View::OnDraw(CDC* pDC)
	{
		C图像局部放大Doc* pDoc = GetDocument();
		ASSERT_VALID(pDoc);
		if (!pDoc)
			return;

		// TODO: 在此处为本机数据添加绘制代码
		static bool load;
		if(!load)
		{
			BITMAP bm;
			load=!load;
			m_pBitmap->LoadBitmap(IDB_BITMAP1);
			m_pdcMem->CreateCompatibleDC(pDC);
			m_pdcMem->SelectObject(m_pBitmap);
			m_pBitmap->GetObject(sizeof(bm),&bm);
			m_sizeSource.cx=bm.bmWidth;
			m_sizeSource.cy=bm.bmHeight;
			m_sizeDest=m_sizeSource;
			pDC->StretchBlt(0,0,m_sizeSource.cx,m_sizeSource.cy,m_pdcMem,0,0,m_sizeSource.cx,
				m_sizeSource.cy,mana);
		}
		else
		{
			pDC->StretchBlt(0,0,m_sizeSource.cx,m_sizeSource.cy,m_pdcMem,0,0,m_sizeSource.cx,
				m_sizeSource.cy,mana);
		}
	}


	// C图像局部放大View 打印

	BOOL C图像局部放大View::OnPreparePrinting(CPrintInfo* pInfo)
	{
		// 默认准备
		return DoPreparePrinting(pInfo);
	}

	void C图像局部放大View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
	{
		// TODO: 添加额外的打印前进行的初始化过程
	}

	void C图像局部放大View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
	{
		// TODO: 添加打印后进行的清理过程
	}


	// C图像局部放大View 诊断

#ifdef _DEBUG
	void C图像局部放大View::AssertValid() const
	{
		CView::AssertValid();
	}

	void C图像局部放大View::Dump(CDumpContext& dc) const
	{
		CView::Dump(dc);
	}

	C图像局部放大Doc* C图像局部放大View::GetDocument() const // 非调试版本是内联的
	{
		ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(C图像局部放大Doc)));
		return (C图像局部放大Doc*)m_pDocument;
	}
#endif //_DEBUG


	// C图像局部放大View 消息处理程序


	void C图像局部放大View::OnMouseMove(UINT nFlags, CPoint point)
	{
		// TODO: 在此添加消息处理程序代码和/或调用默认值
		CString cord;
		int dd;
		CRect srect,drect,mrect;
		CMainFrame *pFrame=(CMainFrame*)AfxGetApp()->m_pMainWnd;
		CStatusBar *pStatus=&pFrame->m_wndStatusBar;
		if(pStatus)
		{
			cord.Format("X=%d,Y=%d",point.x,point.y);
			pStatus->SetPaneText(1,cord);
			srect.left=point.x-s;
			srect.top=point.y-s;
			srect.right=point.x+s;
			srect.bottom=point.y+s;
			drect.left=point.x-d;
			drect.top=point.y-d;
			drect.top=point.y-d;
			drect.right=point.x+d;
			drect.bottom=point.y+d;
			mrect.left=oldx-d;
			mrect.top=oldy-d;
			mrect.right=oldx+d;
			mrect.bottom=oldy+d;
			dd=2*d;
			CDC *pDC=GetDC();
			OnPrepareDC(pDC);
			if(recover)
			{
				pDC->BitBlt(mrect.left,mrect.top,dd,dd,m_pdcMem,mrect.left,mrect.top,mana);
			}
			pDC->StretchBlt(drect.left,drect.top,drect.Width(),drect.Height(),m_pdcMem,srect.left,
			 srect.top,srect.Width(),srect.Height(),SRCCOPY);
			oldx=point.x;
			oldy=point.y;
			ReleaseDC(pDC);
		}
		recover=true;
		CView::OnMouseMove(nFlags, point);
	}


	void C图像局部放大View::OnRButtonDown(UINT nFlags, CPoint point)
	{
		// TODO: 在此添加消息处理程序代码和/或调用默认值
		if(d>5)
		{
			CDC *pDC=GetDC();
			pDC->StretchBlt(oldx-d,oldy-d,2*d,2*d,m_pdcMem,oldx-d,oldy-d,2*d,2*d,mana);
			d-=10;
			ReleaseDC(pDC);
			C图像局部放大View::OnMouseMove(nFlags,point);
		}
		CView::OnRButtonDown(nFlags, point);
	}


	void C图像局部放大View::OnLButtonDown(UINT nFlags, CPoint point)
	{
		// TODO: 在此添加消息处理程序代码和/或调用默认值
		if(d<150)
		{
			d+=10;
			C图像局部放大View::OnMouseMove(nFlags,point);
		}
		CView::OnLButtonDown(nFlags, point);
	}

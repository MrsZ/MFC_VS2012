
// ͼ��ֲ��Ŵ�View.cpp : Cͼ��ֲ��Ŵ�View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "ͼ��ֲ��Ŵ�.h"
#endif

#include "ͼ��ֲ��Ŵ�Doc.h"
#include "ͼ��ֲ��Ŵ�View.h"
#include "MainFrm.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Cͼ��ֲ��Ŵ�View

IMPLEMENT_DYNCREATE(Cͼ��ֲ��Ŵ�View, CView)

	BEGIN_MESSAGE_MAP(Cͼ��ֲ��Ŵ�View, CView)
		// ��׼��ӡ����
		ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
		ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
		ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
		ON_WM_MOUSEMOVE()
		ON_WM_RBUTTONDOWN()
		ON_WM_LBUTTONDOWN()
	END_MESSAGE_MAP()

	// Cͼ��ֲ��Ŵ�View ����/����

	Cͼ��ֲ��Ŵ�View::Cͼ��ֲ��Ŵ�View()
	{
		// TODO: �ڴ˴���ӹ������
		m_pdcMem=new CDC;
		m_pBitmap=new CBitmap;
		recover=true;
		s=30;
		d=45;
		mana=SRCCOPY;
	}

	Cͼ��ֲ��Ŵ�View::~Cͼ��ֲ��Ŵ�View()
	{
		delete m_pdcMem;
		delete m_pBitmap;
	}

	BOOL Cͼ��ֲ��Ŵ�View::PreCreateWindow(CREATESTRUCT& cs)
	{
		// TODO: �ڴ˴�ͨ���޸�
		//  CREATESTRUCT cs ���޸Ĵ��������ʽ

		return CView::PreCreateWindow(cs);
	}

	// Cͼ��ֲ��Ŵ�View ����

	void Cͼ��ֲ��Ŵ�View::OnDraw(CDC* pDC)
	{
		Cͼ��ֲ��Ŵ�Doc* pDoc = GetDocument();
		ASSERT_VALID(pDoc);
		if (!pDoc)
			return;

		// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
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


	// Cͼ��ֲ��Ŵ�View ��ӡ

	BOOL Cͼ��ֲ��Ŵ�View::OnPreparePrinting(CPrintInfo* pInfo)
	{
		// Ĭ��׼��
		return DoPreparePrinting(pInfo);
	}

	void Cͼ��ֲ��Ŵ�View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
	{
		// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
	}

	void Cͼ��ֲ��Ŵ�View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
	{
		// TODO: ��Ӵ�ӡ����е��������
	}


	// Cͼ��ֲ��Ŵ�View ���

#ifdef _DEBUG
	void Cͼ��ֲ��Ŵ�View::AssertValid() const
	{
		CView::AssertValid();
	}

	void Cͼ��ֲ��Ŵ�View::Dump(CDumpContext& dc) const
	{
		CView::Dump(dc);
	}

	Cͼ��ֲ��Ŵ�Doc* Cͼ��ֲ��Ŵ�View::GetDocument() const // �ǵ��԰汾��������
	{
		ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Cͼ��ֲ��Ŵ�Doc)));
		return (Cͼ��ֲ��Ŵ�Doc*)m_pDocument;
	}
#endif //_DEBUG


	// Cͼ��ֲ��Ŵ�View ��Ϣ�������


	void Cͼ��ֲ��Ŵ�View::OnMouseMove(UINT nFlags, CPoint point)
	{
		// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
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


	void Cͼ��ֲ��Ŵ�View::OnRButtonDown(UINT nFlags, CPoint point)
	{
		// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
		if(d>5)
		{
			CDC *pDC=GetDC();
			pDC->StretchBlt(oldx-d,oldy-d,2*d,2*d,m_pdcMem,oldx-d,oldy-d,2*d,2*d,mana);
			d-=10;
			ReleaseDC(pDC);
			Cͼ��ֲ��Ŵ�View::OnMouseMove(nFlags,point);
		}
		CView::OnRButtonDown(nFlags, point);
	}


	void Cͼ��ֲ��Ŵ�View::OnLButtonDown(UINT nFlags, CPoint point)
	{
		// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
		if(d<150)
		{
			d+=10;
			Cͼ��ֲ��Ŵ�View::OnMouseMove(nFlags,point);
		}
		CView::OnLButtonDown(nFlags, point);
	}

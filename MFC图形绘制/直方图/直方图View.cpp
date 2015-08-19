
// 直方图View.cpp : C直方图View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "直方图.h"
#endif

#include "直方图Doc.h"
#include "直方图View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// C直方图View

IMPLEMENT_DYNCREATE(C直方图View, CView)

BEGIN_MESSAGE_MAP(C直方图View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// C直方图View 构造/析构

C直方图View::C直方图View()
{
	// TODO: 在此处添加构造代码

}

C直方图View::~C直方图View()
{
}

BOOL C直方图View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// C直方图View 绘制

void C直方图View::OnDraw(CDC* pDC)
{
	C直方图Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
	float fScore[]={66,82,79,74,86,82,67,60,45,44,77,98,65,90,66,76,66,62,83};
	DrawScore(pDC,fScore,sizeof(fScore)/sizeof(float));
}


// C直方图View 打印

BOOL C直方图View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void C直方图View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void C直方图View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// C直方图View 诊断

#ifdef _DEBUG
void C直方图View::AssertValid() const
{
	CView::AssertValid();
}

void C直方图View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

C直方图Doc* C直方图View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(C直方图Doc)));
	return (C直方图Doc*)m_pDocument;
}
#endif //_DEBUG


// C直方图View 消息处理程序


void C直方图View::DrawScore(CDC * pDC, float* fScore, int nNum)
{
	//各成绩段人数初始值
	int nScoreNum[]={0,0,0,0,0};
	//统计各分数段人数
	for(int i=0;i<nNum;i++)
	{
		int nSeg=(int)(fScore[i]/10);
		if(nSeg<6)nSeg=5;
		if(nSeg==10)nSeg=9;
		nScoreNum[nSeg-5]++;
	}
	//计算多少个分数段
	int nSegNum=sizeof(nScoreNum)/sizeof(int);
	int nNumMax=nScoreNum[0];
	//求各个分数段最大人数
	for(int i=1;i<nSegNum;i++)
	{
		if(nNumMax<nScoreNum[i])
			nNumMax=nScoreNum[i];
	}
	CRect rc;
	//客户区大小
	GetClientRect(rc);
	rc.DeflateRect(40,40);
	int nSegWidth=rc.Width()/nSegNum;
	int nSegHeight=rc.Height()/nNumMax;
	COLORREF crSeg=RGB(0,0,192);
	CBrush brush1(HS_FDIAGONAL,crSeg);
	CBrush brush2(HS_BDIAGONAL,crSeg);
	CPen pen(PS_INSIDEFRAME,2,crSeg);
	CBrush *oldBrush=pDC->SelectObject(&brush1);
	CPen *oldPen=pDC->SelectObject(&pen);
	CRect rcSeg(rc);
	rcSeg.right=rcSeg.left+nSegWidth;
	CString strSeg[]={"<60","60-70","70-80","80-90",">=90"};
	CRect rcStr;
	for(int i=0;i < nSegNum;i++)
	{
		//保证相邻的矩形填充样式不相同
		if(i%2)
			pDC->SelectObject(&brush2);
		else
			pDC->SelectObject(&brush1);
		//计算各段矩形的宽度
		rcSeg.top=rcSeg.bottom-nScoreNum[i]*nSegHeight-2;
		pDC->Rectangle(rcSeg);
		if(nScoreNum[i]>0)
		{
			CString str;
			str.Format("%d人",nScoreNum[i]);
			pDC->DrawText(str,rcSeg,DT_CENTER|DT_VCENTER|DT_SINGLELINE);
		}
		rcStr=rcSeg;
		rcStr.top=rcStr.bottom+2;
		rcStr.bottom+=20;
		pDC->DrawText(strSeg[i],rcStr,DT_CENTER|DT_VCENTER|DT_SINGLELINE);
		rcSeg.OffsetRect(nSegWidth,0);
	}
	pDC->SelectObject(oldBrush);
	pDC->SelectObject(oldPen);
}


// ֱ��ͼView.cpp : Cֱ��ͼView ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "ֱ��ͼ.h"
#endif

#include "ֱ��ͼDoc.h"
#include "ֱ��ͼView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Cֱ��ͼView

IMPLEMENT_DYNCREATE(Cֱ��ͼView, CView)

BEGIN_MESSAGE_MAP(Cֱ��ͼView, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// Cֱ��ͼView ����/����

Cֱ��ͼView::Cֱ��ͼView()
{
	// TODO: �ڴ˴���ӹ������

}

Cֱ��ͼView::~Cֱ��ͼView()
{
}

BOOL Cֱ��ͼView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// Cֱ��ͼView ����

void Cֱ��ͼView::OnDraw(CDC* pDC)
{
	Cֱ��ͼDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
	float fScore[]={66,82,79,74,86,82,67,60,45,44,77,98,65,90,66,76,66,62,83};
	DrawScore(pDC,fScore,sizeof(fScore)/sizeof(float));
}


// Cֱ��ͼView ��ӡ

BOOL Cֱ��ͼView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void Cֱ��ͼView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void Cֱ��ͼView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}


// Cֱ��ͼView ���

#ifdef _DEBUG
void Cֱ��ͼView::AssertValid() const
{
	CView::AssertValid();
}

void Cֱ��ͼView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

Cֱ��ͼDoc* Cֱ��ͼView::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Cֱ��ͼDoc)));
	return (Cֱ��ͼDoc*)m_pDocument;
}
#endif //_DEBUG


// Cֱ��ͼView ��Ϣ�������


void Cֱ��ͼView::DrawScore(CDC * pDC, float* fScore, int nNum)
{
	//���ɼ���������ʼֵ
	int nScoreNum[]={0,0,0,0,0};
	//ͳ�Ƹ�����������
	for(int i=0;i<nNum;i++)
	{
		int nSeg=(int)(fScore[i]/10);
		if(nSeg<6)nSeg=5;
		if(nSeg==10)nSeg=9;
		nScoreNum[nSeg-5]++;
	}
	//������ٸ�������
	int nSegNum=sizeof(nScoreNum)/sizeof(int);
	int nNumMax=nScoreNum[0];
	//������������������
	for(int i=1;i<nSegNum;i++)
	{
		if(nNumMax<nScoreNum[i])
			nNumMax=nScoreNum[i];
	}
	CRect rc;
	//�ͻ�����С
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
		//��֤���ڵľ��������ʽ����ͬ
		if(i%2)
			pDC->SelectObject(&brush2);
		else
			pDC->SelectObject(&brush1);
		//������ξ��εĿ��
		rcSeg.top=rcSeg.bottom-nScoreNum[i]*nSegHeight-2;
		pDC->Rectangle(rcSeg);
		if(nScoreNum[i]>0)
		{
			CString str;
			str.Format("%d��",nScoreNum[i]);
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

// BkColorDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "������.h"
#include "BkColorDlg.h"
#include "afxdialogex.h"


// CBkColorDlg �Ի���

IMPLEMENT_DYNAMIC(CBkColorDlg, CDialogEx)

CBkColorDlg::CBkColorDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CBkColorDlg::IDD, pParent)
	, q(0)
	, m_nBlue(0)
	, m_nRed(0)
	, m_nGreen(0)
{

}

CBkColorDlg::~CBkColorDlg()
{
}

void CBkColorDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	//  DDX_Control(pDX, IDC_SLIDER_BLUE, m_sliderRed);
	DDX_Control(pDX, IDC_SLIDER_BLUE, m_sliderBlue);
	DDX_Slider(pDX, IDC_SLIDER_BLUE, m_nBlue);
	DDX_Control(pDX, IDC_SLIDER_RED, m_sliderRed);
	DDX_Slider(pDX, IDC_SLIDER_RED, m_nRed);
	DDX_Control(pDX, IDC_SLIDER_GREEN, m_sliderGreen);
	DDX_Slider(pDX, IDC_SLIDER_GREEN, m_nGreen);
}


BEGIN_MESSAGE_MAP(CBkColorDlg, CDialogEx)
	ON_WM_HSCROLL()
	ON_WM_CTLCOLOR()
END_MESSAGE_MAP()


// CBkColorDlg ��Ϣ�������


BOOL CBkColorDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	m_sliderRed.SetRange(0,255);
	m_sliderGreen.SetRange(0,255);
	m_sliderBlue.SetRange(0,255);
	m_nRed=200;
	UpdateData(false);
	return true;
}


void CBkColorDlg::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	///*int nID=pScrollBar->GetDlgCtrlID();
	//if(nID==IDC_SLIDER_RED)
	//{
	//	switch(nSBCode)
	//	{
	//	case SB_LINELEFT:m_nRed--;break;
	//	case SB_LINERIGHT:m_nRed++;break;
	//	case SB_PAGELEFT:m_nRed-=10;break;
	//	case SB_PAGEDOWN:m_nRed+=10;break;
	//	case SB_THUMBTRACK:m_nRed=nPos;break;
	//	}
	//	if(m_nRed<0) m_nRed=0;
	//	if(m_nRed>255)m_nRed=255;
	//	m_sliderRed.SetScrollPos(0,m_nRed);
	//}
	Invalidate();
	CDialogEx::OnHScroll(nSBCode, nPos, pScrollBar);
}


HBRUSH CBkColorDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	//HBRUSH hbr = CDialogEx::OnCtlColor(pDC, pWnd, nCtlColor);
	UpdateData(true);
	COLORREF color=RGB(m_nRed,m_nGreen,m_nBlue);
	m_Brush.Detach();//ʹ��ˢ�Ͷ������
	m_Brush.CreateSolidBrush(color);//����color��ɫ��ˢ
	pDC->SetBkColor(color);//����color������ɫ
	return (HBRUSH)m_Brush;//���ػ�ˢ������Ա�ϵͳʹ�˻�ˢ���ƶԻ���
}

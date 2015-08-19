// DlgButton.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "�Ի�����ؼ�.h"
#include "DlgButton.h"
#include "afxdialogex.h"


// CDlgButton �Ի���

IMPLEMENT_DYNAMIC(CDlgButton, CDialogEx)

CDlgButton::CDlgButton(CWnd* pParent /*=NULL*/)
	: CDialogEx(CDlgButton::IDD, pParent)
{

}

CDlgButton::~CDlgButton()
{
}

void CDlgButton::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_BITMAP, m_cBmp);
}


BEGIN_MESSAGE_MAP(CDlgButton, CDialogEx)
	ON_COMMAND(IDC_RADIO_SPORT, &CDlgButton::OnRadioSport)
	ON_COMMAND(IDC_RADIO_MUSIC, &CDlgButton::OnRadioMusic)
END_MESSAGE_MAP()


// CDlgButton ��Ϣ�������


void CDlgButton::OnRadioSport()
{
	// TODO: �ڴ���������������
	cBmp.DeleteObject();//ɾ���ײ����
	cBmp.LoadBitmapA(IDB_BITMAP1);//װ��λͼ
	m_cBmp.SetBitmap(HBITMAP(cBmp));//����̬�ؼ�����λͼ
}


void CDlgButton::OnRadioMusic()
{
	// TODO: �ڴ���������������
	cBmp.DeleteObject();//ɾ���ײ����
	cBmp.LoadBitmapA(IDB_BITMAP2);//װ��λͼ
	m_cBmp.SetBitmap(HBITMAP(cBmp));//����̬�ؼ�����λͼ
}


BOOL CDlgButton::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	cBmp.LoadBitmapA(IDB_BITMAP1);
	m_cBmp.SetBitmap(HBITMAP(cBmp));
	return true;
}

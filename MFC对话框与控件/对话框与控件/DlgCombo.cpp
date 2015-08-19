// DlgCombo.cpp : 实现文件
//

#include "stdafx.h"
#include "对话框与控件.h"
#include "DlgCombo.h"
#include "afxdialogex.h"


// CDlgCombo 对话框

IMPLEMENT_DYNAMIC(CDlgCombo, CDialogEx)

CDlgCombo::CDlgCombo(CWnd* pParent /*=NULL*/)
	: CDialogEx(CDlgCombo::IDD, pParent)
{

	
}

CDlgCombo::~CDlgCombo()
{
}

void CDlgCombo::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBO_CONTROL, m_ComboBox);
}


BEGIN_MESSAGE_MAP(CDlgCombo, CDialogEx)
	ON_WM_DESTROY()
	ON_CBN_SELCHANGE(IDC_COMBO_CONTROL, &CDlgCombo::OnSelchangeComboControl)
END_MESSAGE_MAP()


// CDlgCombo 消息处理程序


BOOL CDlgCombo::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	pWndCtrl=NULL;
	return true;
}


void CDlgCombo::OnDestroy()
{
	CDialogEx::OnDestroy();
	if(pWndCtrl!=NULL)
		delete pWndCtrl;
	// TODO: 在此处添加消息处理程序代码
}


void CDlgCombo::OnSelchangeComboControl()
{
	// TODO: 在此添加控件通知处理程序代码
	if(pWndCtrl!=NULL)
	{
		delete pWndCtrl;
		pWndCtrl=NULL;
	}
	int nChoice=m_ComboBox.GetCurSel();
	switch(nChoice)
	{
	case 0:
		pWndCtrl=new CStatic;
		((CStatic *)pWndCtrl)->Create(_T("静态文本"),WS_VISIBLE,CRect(180,40,300,70),this,1);break;
	case 1:
		pWndCtrl=new CEdit;
		((CEdit *)pWndCtrl)->Create(WS_VISIBLE|WS_BORDER,CRect(180,40,300,70),this,2);break;
	case 2:
		pWndCtrl =new CButton;
		((CButton *)pWndCtrl)->Create(_T("组框"),WS_VISIBLE|BS_GROUPBOX,CRect(180,40,300,100),this,3);break;
	case 3:
		pWndCtrl=new CButton;
		((CButton *)pWndCtrl)->Create(_T("单选按钮"),WS_VISIBLE|BS_RADIOBUTTON,CRect(180,40,300,70),this,4);
		break;
	case 4:
		pWndCtrl=new CButton;
		((CButton*)pWndCtrl)->Create(_T("复选框"),WS_VISIBLE|BS_CHECKBOX,CRect(180,40,300,70),this,5);
		break;
	default:
		pWndCtrl=new CStatic;
		((CStatic*)pWndCtrl)->Create(_T("没有选择"),WS_VISIBLE,CRect(180,40,300,70),this,1);
		break;
	}
}

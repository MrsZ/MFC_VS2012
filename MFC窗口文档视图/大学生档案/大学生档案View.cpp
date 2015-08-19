
// 大学生档案View.cpp : C大学生档案View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "大学生档案.h"
#endif

#include "大学生档案Doc.h"
#include "大学生档案View.h"
#include "InDlog.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// C大学生档案View

IMPLEMENT_DYNCREATE(C大学生档案View, CFormView)

BEGIN_MESSAGE_MAP(C大学生档案View, CFormView)
	ON_BN_CLICKED(IDC_BUTTON1, &C大学生档案View::OnClickedButton1)
	ON_EN_CHANGE(IDC_EDIT_AGE, &C大学生档案View::OnChangeEditAge)
	ON_EN_CHANGE(IDC_EDIT_CLA, &C大学生档案View::OnChangeEditCla)
	ON_EN_CHANGE(IDC_EDIT_CLAS, &C大学生档案View::OnChangeEditClas)
	ON_EN_CHANGE(IDC_EDIT_NAME, &C大学生档案View::OnChangeEditName)
	ON_COMMAND(IDC_EDIT_NUM, &C大学生档案View::OnEditNum)
	ON_EN_CHANGE(IDC_EDIT_POS, &C大学生档案View::OnChangeEditPos)
	ON_EN_CHANGE(IDC_EDIT_PRO, &C大学生档案View::OnChangeEditPro)
	ON_EN_CHANGE(IDC_EDIT_SCHOOL, &C大学生档案View::OnChangeEditSchool)
	ON_EN_CHANGE(IDC_EDIT_SEX, &C大学生档案View::OnChangeEditSex)
	ON_EN_CHANGE(IDC_EDIT_STUID, &C大学生档案View::OnChangeEditStuid)
	ON_EN_CHANGE(IDC_EDIT_TEL, &C大学生档案View::OnChangeEditTel)
	ON_CBN_SELCHANGE(IDC_COMBO1, &C大学生档案View::OnSelchangeCombo1)
	ON_COMMAND(ID_FILE_MYOPEN, &C大学生档案View::OnFileMyopen)
	ON_COMMAND(ID_FILE_MYSAVE, &C大学生档案View::OnFileMysave)
END_MESSAGE_MAP()

// C大学生档案View 构造/析构

C大学生档案View::C大学生档案View()
	: CFormView(C大学生档案View::IDD)
	, m_clas(_T(""))
	, m_pro(_T(""))
	, m_cla(_T(""))
	, m_name(_T(""))
	, m_stuid(_T(""))
	, m_sex(_T(""))
	, m_age(_T(""))
	, m_tel(_T(""))
	, m_pos(_T(""))
	, m_school(_T(""))
{
	// TODO: 在此处添加构造代码
	m_nCurrentNo=0;
}

C大学生档案View::~C大学生档案View()
{
}

void C大学生档案View::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_CLAS, m_clas);
	DDX_Text(pDX, IDC_EDIT_PRO, m_pro);
	DDX_Text(pDX, IDC_EDIT_CLA, m_cla);
	DDX_Text(pDX, IDC_EDIT_NAME, m_name);
	DDX_Text(pDX, IDC_EDIT_STUID, m_stuid);
	DDX_Text(pDX, IDC_EDIT_SEX, m_sex);
	DDX_Text(pDX, IDC_EDIT_AGE, m_age);
	DDX_Text(pDX, IDC_EDIT_TEL, m_tel);
	DDX_Text(pDX, IDC_EDIT_POS, m_pos);
	DDX_Control(pDX, IDC_COMBO1, m_noList);
	DDX_Text(pDX, IDC_EDIT_SCHOOL, m_school);
}

BOOL C大学生档案View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CFormView::PreCreateWindow(cs);
}

void C大学生档案View::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

	C大学生档案Doc *pDoc=GetDocument();
	m_noList.ResetContent();
	for(int i=0;i<120;i++)
	{
		if(strcmp(pDoc->m_student[i].name,""))
			m_noList.InsertString(-1,pDoc->m_student[i].name);
	}
	m_noList.SetCurSel(0);
	m_clas=pDoc->m_student[0].clas;
	m_pro=pDoc->m_student[0].pro;
	m_cla=pDoc->m_student[0].cla;
	m_name=pDoc->m_student[0].name;
	m_stuid=pDoc->m_student[0].stuid;
	m_sex=pDoc->m_student[0].sex;
	m_age=pDoc->m_student[0].age;
	m_tel=pDoc->m_student[0].tel;
	m_pos=pDoc->m_student[0].pos;
	m_school=pDoc->m_student[0].school;
	UpdateData(false);
}


// C大学生档案View 诊断

#ifdef _DEBUG
void C大学生档案View::AssertValid() const
{
	CFormView::AssertValid();
}

void C大学生档案View::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

C大学生档案Doc* C大学生档案View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(C大学生档案Doc)));
	return (C大学生档案Doc*)m_pDocument;
}
#endif //_DEBUG


// C大学生档案View 消息处理程序


void C大学生档案View::OnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(true);
	CInDlog dlg;
	dlg.m_num.TrimLeft();
	dlg.m_num.TrimRight();
	if(IDOK==dlg.DoModal())
	{
		if(dlg.m_num.IsEmpty())
		{
			MessageBox("姓名不能为空");
			return;
		}
		if((m_noList.FindStringExact(-1,dlg.m_num))!=LB_ERR)
		{
			MessageBox("列表中已有相同的姓名，不能添加");
			return;
		}
	}
	m_noList.InsertString(-1,dlg.m_num);
	m_noList.SetCurSel(m_noList.GetCount()-1);
	m_nCurrentNo=m_noList.GetCurSel();
	m_name="";
	m_stuid="";
	m_sex="";
	m_age="";
	m_tel="";
	m_pos="";
	m_school="";
	UpdateData(false);
}


void C大学生档案View::OnChangeEditAge()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CFormView::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

//#1015
	// TODO:  在此添加控件通知处理程序代码
	C大学生档案Doc *pDoc=GetDocument();
	UpdateData(true);
	if(strcmp(pDoc->m_student[m_nCurrentNo].age,m_age))
	{
		strcpy_s(pDoc->m_student[m_nCurrentNo].age,m_age);
		pDoc->SetModifiedFlag();
	}
}


void C大学生档案View::OnChangeEditCla()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CFormView::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

//#1015

	// TODO:  在此添加控件通知处理程序代码
	C大学生档案Doc *pDoc=GetDocument();
	UpdateData(true);
	if(strcmp(pDoc->m_student[m_nCurrentNo].cla,m_cla))
	{
		strcpy_s(pDoc->m_student[m_nCurrentNo].cla,m_cla);
		pDoc->SetModifiedFlag();
	}
}


void C大学生档案View::OnChangeEditClas()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CFormView::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

//#1015

	// TODO:  在此添加控件通知处理程序代码
	C大学生档案Doc *pDoc=GetDocument();
	UpdateData(true);
	if(strcmp(pDoc->m_student[m_nCurrentNo].clas,m_clas))
	{
		strcpy_s(pDoc->m_student[m_nCurrentNo].clas,m_clas);
		pDoc->SetModifiedFlag();
	}
}


void C大学生档案View::OnChangeEditName()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CFormView::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。



	// TODO:  在此添加控件通知处理程序代码
	C大学生档案Doc *pDoc=GetDocument();
	UpdateData(true);
	if(strcmp(pDoc->m_student[m_nCurrentNo].name,m_name))
	{
		strcpy_s(pDoc->m_student[m_nCurrentNo].name,m_name);
		pDoc->SetModifiedFlag();
	}
}


void C大学生档案View::OnEditNum()
{
	// TODO: 在此添加命令处理程序代码
}


void C大学生档案View::OnChangeEditPos()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CFormView::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

//#1015

	// TODO:  在此添加控件通知处理程序代码
	C大学生档案Doc *pDoc=GetDocument();
	UpdateData(true);
	if(strcmp(pDoc->m_student[m_nCurrentNo].pos,m_pos))
	{
		strcpy_s(pDoc->m_student[m_nCurrentNo].pos,m_pos);
		pDoc->SetModifiedFlag();
	}
}


void C大学生档案View::OnChangeEditPro()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CFormView::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

//#1015

	// TODO:  在此添加控件通知处理程序代码
	C大学生档案Doc *pDoc=GetDocument();
	UpdateData(true);
	if(strcmp(pDoc->m_student[m_nCurrentNo].pro,m_pro))
	{
		strcpy_s(pDoc->m_student[m_nCurrentNo].pro,m_pro);
		pDoc->SetModifiedFlag();
	}
}


void C大学生档案View::OnChangeEditSchool()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CFormView::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

//#1015

	// TODO:  在此添加控件通知处理程序代码
	C大学生档案Doc *pDoc=GetDocument();
	UpdateData(true);
	if(strcmp(pDoc->m_student[m_nCurrentNo].school,m_school))
	{
		strcpy_s(pDoc->m_student[m_nCurrentNo].school,m_school);
		pDoc->SetModifiedFlag();
	}
}


void C大学生档案View::OnChangeEditSex()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CFormView::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

//#1015

	// TODO:  在此添加控件通知处理程序代码
	C大学生档案Doc *pDoc=GetDocument();
	UpdateData(true);
	if(strcmp(pDoc->m_student[m_nCurrentNo].sex,m_sex))
	{
		strcpy_s(pDoc->m_student[m_nCurrentNo].sex,m_sex);
		pDoc->SetModifiedFlag();
	}
}


void C大学生档案View::OnChangeEditStuid()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CFormView::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

//#1015

	// TODO:  在此添加控件通知处理程序代码
	C大学生档案Doc *pDoc=GetDocument();
	UpdateData(true);
	if(strcmp(pDoc->m_student[m_nCurrentNo].stuid,m_stuid))
	{
		strcpy_s(pDoc->m_student[m_nCurrentNo].stuid,m_stuid);
		pDoc->SetModifiedFlag();
	}
}


void C大学生档案View::OnChangeEditTel()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CFormView::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

//#1015

	// TODO:  在此添加控件通知处理程序代码
	C大学生档案Doc *pDoc=GetDocument();
	UpdateData(true);
	if(strcmp(pDoc->m_student[m_nCurrentNo].tel,m_tel))
	{
		strcpy_s(pDoc->m_student[m_nCurrentNo].tel,m_tel);
		pDoc->SetModifiedFlag();
	}
}


void C大学生档案View::OnSelchangeCombo1()
{
	// TODO: 在此添加控件通知处理程序代码
	C大学生档案Doc *pDoc=GetDocument();
	UpdateData(true);
	CInDlog dlg;
	m_nCurrentNo=m_noList.GetCurSel();
	int i=m_noList.GetCurSel();
	m_clas=pDoc->m_student[m_nCurrentNo].clas;
	m_pro=pDoc->m_student[m_nCurrentNo].pro;
	m_cla=pDoc->m_student[m_nCurrentNo].cla;
	dlg.m_num=pDoc->m_student[m_nCurrentNo].name;
	m_name=pDoc->m_student[m_nCurrentNo].name;
	m_stuid=pDoc->m_student[m_nCurrentNo].stuid;
	m_sex=pDoc->m_student[m_nCurrentNo].sex;
	m_age=pDoc->m_student[m_nCurrentNo].age;
	m_tel=pDoc->m_student[m_nCurrentNo].tel;
	m_pos=pDoc->m_student[m_nCurrentNo].pos;
	m_school=pDoc->m_student[m_nCurrentNo].school;

	if(i==0)
	{
		CDC *pDC=GetDC();
		HBITMAP hBitmap=(HBITMAP)LoadImage(NULL,_T("x0.bmp"),IMAGE_BITMAP,0,0,LR_CREATEDIBSECTION|LR_DEFAULTSIZE
			|LR_LOADFROMFILE);
		m_bitmap.Attach(hBitmap);
		BITMAP bm;
		m_bitmap.GetBitmap(&bm);
		CDC dcImage;
		if(!dcImage.CreateCompatibleDC(pDC))
			return;
		CBitmap *pOldBitmap=dcImage.SelectObject(&m_bitmap);
		pDC->BitBlt(0,0,bm.bmWidth,bm.bmHeight,&dcImage,0,0,SRCCOPY);
		dcImage.SelectObject(pOldBitmap);
		DeleteObject(m_bitmap.Detach());
	}

	UpdateData(false);
}


void C大学生档案View::OnFileMyopen()
{
	// TODO: 在此添加命令处理程序代码
	CString strFilter="All Files(*.*)|*.*|Dat File(*.dat)|*.dat||";
	CFileDialog fileDlg(true,NULL,NULL,OFN_HIDEREADONLY|OFN_OVERWRITEPROMPT,(LPCSTR)strFilter,this);
	if(fileDlg.DoModal()!=IDOK)
		return;
	CString strFileName=fileDlg.GetPathName();
	CFile f;
	if(!f.Open(strFileName,CFile::modeRead))
	{
		AfxMessageBox("打开文件失败");
		return;
	}
	C大学生档案Doc *pDoc=GetDocument();
	f.Read(&m_nCurrentNo,sizeof(int));
	for(int i=0;i<120;i++)
	{
		f.Read(pDoc->m_student[i].clas,10);
		f.Read(pDoc->m_student[i].pro,10);
		f.Read(pDoc->m_student[i].cla,10);
		f.Read(pDoc->m_student[i].stuid,20);
		f.Read(pDoc->m_student[i].name,10);
		f.Read(pDoc->m_student[i].sex,10);
		f.Read(pDoc->m_student[i].age,10);
		f.Read(pDoc->m_student[i].tel,20);
		f.Read(pDoc->m_student[i].pos,20);
		f.Read(pDoc->m_student[i].school,999);
	}
	f.Close();
	
	m_noList.SetCurSel(m_nCurrentNo);
	m_clas=pDoc->m_student[m_nCurrentNo].clas;
	m_pro=pDoc->m_student[m_nCurrentNo].pro;
	m_cla=pDoc->m_student[m_nCurrentNo].cla;
	m_stuid=pDoc->m_student[m_nCurrentNo].stuid;
	m_name=pDoc->m_student[m_nCurrentNo].name;
	m_tel=pDoc->m_student[m_nCurrentNo].tel;
	m_pos=pDoc->m_student[m_nCurrentNo].pos;
	m_school=pDoc->m_student[m_nCurrentNo].school;
	UpdateData(false);
}


void C大学生档案View::OnFileMysave()
{
	// TODO: 在此添加命令处理程序代码
	CString strFilter="All Files(*.*)|*.*|Dat File(*.dat)|*.dat||";
	CFileDialog fileDlg(false,NULL,NULL,OFN_HIDEREADONLY|OFN_OVERWRITEPROMPT,(LPCSTR)strFilter,this);
	if(fileDlg.DoModal()!=IDOK)
		return;
	CString strFileName=fileDlg.GetPathName();
	CFile f;
	if(!f.Open(strFileName,CFile::modeCreate|CFile::modeWrite))
	{
		AfxMessageBox("创建文件失败");
		return;
	}
	C大学生档案Doc *pDoc=GetDocument();
	f.Write(&m_nCurrentNo,sizeof(int));
	for(int i=0;i<120;i++)
	{
		f.Write(pDoc->m_student[i].clas,10);
		f.Write(pDoc->m_student[i].pro,10);
		f.Write(pDoc->m_student[i].cla,10);
		f.Write(pDoc->m_student[i].stuid,20);
		f.Write(pDoc->m_student[i].name,10);
		f.Write(pDoc->m_student[i].sex,10);
		f.Write(pDoc->m_student[i].age,10);
		f.Write(pDoc->m_student[i].tel,20);
		f.Write(pDoc->m_student[i].pos,20);
		f.Write(pDoc->m_student[i].school,999);
	}
	f.Close();
}

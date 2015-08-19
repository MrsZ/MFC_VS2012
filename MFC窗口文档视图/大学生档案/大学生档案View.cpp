
// ��ѧ������View.cpp : C��ѧ������View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "��ѧ������.h"
#endif

#include "��ѧ������Doc.h"
#include "��ѧ������View.h"
#include "InDlog.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// C��ѧ������View

IMPLEMENT_DYNCREATE(C��ѧ������View, CFormView)

BEGIN_MESSAGE_MAP(C��ѧ������View, CFormView)
	ON_BN_CLICKED(IDC_BUTTON1, &C��ѧ������View::OnClickedButton1)
	ON_EN_CHANGE(IDC_EDIT_AGE, &C��ѧ������View::OnChangeEditAge)
	ON_EN_CHANGE(IDC_EDIT_CLA, &C��ѧ������View::OnChangeEditCla)
	ON_EN_CHANGE(IDC_EDIT_CLAS, &C��ѧ������View::OnChangeEditClas)
	ON_EN_CHANGE(IDC_EDIT_NAME, &C��ѧ������View::OnChangeEditName)
	ON_COMMAND(IDC_EDIT_NUM, &C��ѧ������View::OnEditNum)
	ON_EN_CHANGE(IDC_EDIT_POS, &C��ѧ������View::OnChangeEditPos)
	ON_EN_CHANGE(IDC_EDIT_PRO, &C��ѧ������View::OnChangeEditPro)
	ON_EN_CHANGE(IDC_EDIT_SCHOOL, &C��ѧ������View::OnChangeEditSchool)
	ON_EN_CHANGE(IDC_EDIT_SEX, &C��ѧ������View::OnChangeEditSex)
	ON_EN_CHANGE(IDC_EDIT_STUID, &C��ѧ������View::OnChangeEditStuid)
	ON_EN_CHANGE(IDC_EDIT_TEL, &C��ѧ������View::OnChangeEditTel)
	ON_CBN_SELCHANGE(IDC_COMBO1, &C��ѧ������View::OnSelchangeCombo1)
	ON_COMMAND(ID_FILE_MYOPEN, &C��ѧ������View::OnFileMyopen)
	ON_COMMAND(ID_FILE_MYSAVE, &C��ѧ������View::OnFileMysave)
END_MESSAGE_MAP()

// C��ѧ������View ����/����

C��ѧ������View::C��ѧ������View()
	: CFormView(C��ѧ������View::IDD)
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
	// TODO: �ڴ˴���ӹ������
	m_nCurrentNo=0;
}

C��ѧ������View::~C��ѧ������View()
{
}

void C��ѧ������View::DoDataExchange(CDataExchange* pDX)
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

BOOL C��ѧ������View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CFormView::PreCreateWindow(cs);
}

void C��ѧ������View::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

	C��ѧ������Doc *pDoc=GetDocument();
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


// C��ѧ������View ���

#ifdef _DEBUG
void C��ѧ������View::AssertValid() const
{
	CFormView::AssertValid();
}

void C��ѧ������View::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

C��ѧ������Doc* C��ѧ������View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(C��ѧ������Doc)));
	return (C��ѧ������Doc*)m_pDocument;
}
#endif //_DEBUG


// C��ѧ������View ��Ϣ�������


void C��ѧ������View::OnClickedButton1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(true);
	CInDlog dlg;
	dlg.m_num.TrimLeft();
	dlg.m_num.TrimRight();
	if(IDOK==dlg.DoModal())
	{
		if(dlg.m_num.IsEmpty())
		{
			MessageBox("��������Ϊ��");
			return;
		}
		if((m_noList.FindStringExact(-1,dlg.m_num))!=LB_ERR)
		{
			MessageBox("�б���������ͬ���������������");
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


void C��ѧ������View::OnChangeEditAge()
{
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
	// ���ʹ�֪ͨ��������д CFormView::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

//#1015
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	C��ѧ������Doc *pDoc=GetDocument();
	UpdateData(true);
	if(strcmp(pDoc->m_student[m_nCurrentNo].age,m_age))
	{
		strcpy_s(pDoc->m_student[m_nCurrentNo].age,m_age);
		pDoc->SetModifiedFlag();
	}
}


void C��ѧ������View::OnChangeEditCla()
{
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
	// ���ʹ�֪ͨ��������д CFormView::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

//#1015

	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	C��ѧ������Doc *pDoc=GetDocument();
	UpdateData(true);
	if(strcmp(pDoc->m_student[m_nCurrentNo].cla,m_cla))
	{
		strcpy_s(pDoc->m_student[m_nCurrentNo].cla,m_cla);
		pDoc->SetModifiedFlag();
	}
}


void C��ѧ������View::OnChangeEditClas()
{
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
	// ���ʹ�֪ͨ��������д CFormView::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

//#1015

	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	C��ѧ������Doc *pDoc=GetDocument();
	UpdateData(true);
	if(strcmp(pDoc->m_student[m_nCurrentNo].clas,m_clas))
	{
		strcpy_s(pDoc->m_student[m_nCurrentNo].clas,m_clas);
		pDoc->SetModifiedFlag();
	}
}


void C��ѧ������View::OnChangeEditName()
{
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
	// ���ʹ�֪ͨ��������д CFormView::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�



	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	C��ѧ������Doc *pDoc=GetDocument();
	UpdateData(true);
	if(strcmp(pDoc->m_student[m_nCurrentNo].name,m_name))
	{
		strcpy_s(pDoc->m_student[m_nCurrentNo].name,m_name);
		pDoc->SetModifiedFlag();
	}
}


void C��ѧ������View::OnEditNum()
{
	// TODO: �ڴ���������������
}


void C��ѧ������View::OnChangeEditPos()
{
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
	// ���ʹ�֪ͨ��������д CFormView::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

//#1015

	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	C��ѧ������Doc *pDoc=GetDocument();
	UpdateData(true);
	if(strcmp(pDoc->m_student[m_nCurrentNo].pos,m_pos))
	{
		strcpy_s(pDoc->m_student[m_nCurrentNo].pos,m_pos);
		pDoc->SetModifiedFlag();
	}
}


void C��ѧ������View::OnChangeEditPro()
{
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
	// ���ʹ�֪ͨ��������д CFormView::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

//#1015

	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	C��ѧ������Doc *pDoc=GetDocument();
	UpdateData(true);
	if(strcmp(pDoc->m_student[m_nCurrentNo].pro,m_pro))
	{
		strcpy_s(pDoc->m_student[m_nCurrentNo].pro,m_pro);
		pDoc->SetModifiedFlag();
	}
}


void C��ѧ������View::OnChangeEditSchool()
{
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
	// ���ʹ�֪ͨ��������д CFormView::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

//#1015

	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	C��ѧ������Doc *pDoc=GetDocument();
	UpdateData(true);
	if(strcmp(pDoc->m_student[m_nCurrentNo].school,m_school))
	{
		strcpy_s(pDoc->m_student[m_nCurrentNo].school,m_school);
		pDoc->SetModifiedFlag();
	}
}


void C��ѧ������View::OnChangeEditSex()
{
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
	// ���ʹ�֪ͨ��������д CFormView::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

//#1015

	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	C��ѧ������Doc *pDoc=GetDocument();
	UpdateData(true);
	if(strcmp(pDoc->m_student[m_nCurrentNo].sex,m_sex))
	{
		strcpy_s(pDoc->m_student[m_nCurrentNo].sex,m_sex);
		pDoc->SetModifiedFlag();
	}
}


void C��ѧ������View::OnChangeEditStuid()
{
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
	// ���ʹ�֪ͨ��������д CFormView::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

//#1015

	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	C��ѧ������Doc *pDoc=GetDocument();
	UpdateData(true);
	if(strcmp(pDoc->m_student[m_nCurrentNo].stuid,m_stuid))
	{
		strcpy_s(pDoc->m_student[m_nCurrentNo].stuid,m_stuid);
		pDoc->SetModifiedFlag();
	}
}


void C��ѧ������View::OnChangeEditTel()
{
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
	// ���ʹ�֪ͨ��������д CFormView::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

//#1015

	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	C��ѧ������Doc *pDoc=GetDocument();
	UpdateData(true);
	if(strcmp(pDoc->m_student[m_nCurrentNo].tel,m_tel))
	{
		strcpy_s(pDoc->m_student[m_nCurrentNo].tel,m_tel);
		pDoc->SetModifiedFlag();
	}
}


void C��ѧ������View::OnSelchangeCombo1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	C��ѧ������Doc *pDoc=GetDocument();
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


void C��ѧ������View::OnFileMyopen()
{
	// TODO: �ڴ���������������
	CString strFilter="All Files(*.*)|*.*|Dat File(*.dat)|*.dat||";
	CFileDialog fileDlg(true,NULL,NULL,OFN_HIDEREADONLY|OFN_OVERWRITEPROMPT,(LPCSTR)strFilter,this);
	if(fileDlg.DoModal()!=IDOK)
		return;
	CString strFileName=fileDlg.GetPathName();
	CFile f;
	if(!f.Open(strFileName,CFile::modeRead))
	{
		AfxMessageBox("���ļ�ʧ��");
		return;
	}
	C��ѧ������Doc *pDoc=GetDocument();
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


void C��ѧ������View::OnFileMysave()
{
	// TODO: �ڴ���������������
	CString strFilter="All Files(*.*)|*.*|Dat File(*.dat)|*.dat||";
	CFileDialog fileDlg(false,NULL,NULL,OFN_HIDEREADONLY|OFN_OVERWRITEPROMPT,(LPCSTR)strFilter,this);
	if(fileDlg.DoModal()!=IDOK)
		return;
	CString strFileName=fileDlg.GetPathName();
	CFile f;
	if(!f.Open(strFileName,CFile::modeCreate|CFile::modeWrite))
	{
		AfxMessageBox("�����ļ�ʧ��");
		return;
	}
	C��ѧ������Doc *pDoc=GetDocument();
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

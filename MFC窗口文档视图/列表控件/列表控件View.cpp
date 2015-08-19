
// �б�ؼ�View.cpp : C�б�ؼ�View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "�б�ؼ�.h"
#endif

#include "�б�ؼ�Doc.h"
#include "�б�ؼ�View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// C�б�ؼ�View

IMPLEMENT_DYNCREATE(C�б�ؼ�View, CListView)

BEGIN_MESSAGE_MAP(C�б�ؼ�View, CListView)
	ON_COMMAND(ID_CHANCE, &C�б�ؼ�View::OnChance)
	ON_NOTIFY_REFLECT(NM_RDBLCLK, &C�б�ؼ�View::OnNMRDblclk)
END_MESSAGE_MAP()

// C�б�ؼ�View ����/����

C�б�ؼ�View::C�б�ؼ�View()
{
	// TODO: �ڴ˴���ӹ������

}

C�б�ؼ�View::~C�б�ؼ�View()
{
}

BOOL C�б�ؼ�View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CListView::PreCreateWindow(cs);
}

void C�б�ؼ�View::OnInitialUpdate()
{
	CListView::OnInitialUpdate();
	//����ͼ���б�
	m_ImageList.Create(32,32,ILC_COLOR8|ILC_MASK,1,1);
	m_ImageListSmall.Create(16,16,ILC_COLOR8|ILC_MASK,1,1);
	CListCtrl &m_ListCtrl=GetListCtrl();
	m_ListCtrl.SetImageList(&m_ImageList,LVSIL_NORMAL);
	m_ListCtrl.SetImageList(&m_ImageListSmall,LVSIL_SMALL);
	LV_COLUMN listCol;
	char *arCols[4]={"�ļ���","��С","����","�޸�����"};
	listCol.mask=LVCF_FMT|LVCF_WIDTH|LVCF_TEXT|LVCF_SUBITEM;
	for(int nCol=0;nCol<4;nCol++)
	{
		listCol.iSubItem=nCol;
		listCol.pszText=arCols[nCol];
		if(nCol==1)
			listCol.fmt=LVCFMT_RIGHT;
		else
			listCol.fmt=LVCFMT_LEFT;
		m_ListCtrl.InsertColumn(nCol,&listCol);
	}
	//���ҵ�ǰĿ¼
	CFileFind finder;
	bool bWorking=finder.FindFile("*.*");
	int nItem=0,nIndex,nImage;
	CTime m_time;
	CString  str,strTypeName;
	while(bWorking)
	{
		bWorking=finder.FindNextFileA();
		if(finder.IsArchived())
		{
			str=finder.GetFilePath();
			SHFILEINFO fi;
			//��ȡ�ļ�������ͼ����ļ�������
			SHGetFileInfo(str,0,&fi,sizeof(SHFILEINFO),SHGFI_ICON|SHGFI_LARGEICON|SHGFI_TYPENAME);
			strTypeName=fi.szTypeName;
			nImage=-1;
			for(int i=0;i<m_strArray.GetSize();i++)
			{
				if(m_strArray[i]==strTypeName)
				{
					nImage=i;
					break;
				}
			}
			//���ͼ��
			if(nImage<0)
			{
				nImage=m_ImageList.Add(fi.hIcon);
				SHGetFileInfo(str,0,&fi,sizeof(SHFILEINFO),SHGFI_ICON|SHGFI_SMALLICON);
				m_ImageListSmall.Add(fi.hIcon);
				m_strArray.Add(strTypeName);
			}
			//����б���
			nIndex=m_ListCtrl.InsertItem(nItem,finder.GetFileName(),nImage);
			DWORD dwSize=finder.GetLength();
			if(dwSize>1024)
				str.Format("%dK",dwSize/1024);
			else
				str.Format("%d",dwSize);
			m_ListCtrl.SetItemText(nIndex,1,str);
			m_ListCtrl.SetItemText(nIndex,2,strTypeName);
			finder.GetLastWriteTime(m_time);
			m_ListCtrl.SetItemText(nIndex,3,m_time.Format("%Y-%m-%d"));
			nItem++;
		}
	}
	//����Ϊ����ʽ
	SetCtrlStyle(m_ListCtrl.GetSafeHwnd(),LVS_REPORT);
	//������չ���ʹ���б���һ�У�ȫ��ѡ������ʾ������
	m_ListCtrl.SetExtendedStyle(LVS_EX_FULLROWSELECT|LVS_EX_GRIDLINES);
	//���ÿ��
	m_ListCtrl.SetColumnWidth(0,LVSCW_AUTOSIZE);
	m_ListCtrl.SetColumnWidth(1,100);
	m_ListCtrl.SetColumnWidth(2,LVSCW_AUTOSIZE);
	m_ListCtrl.SetColumnWidth(3,200);
	// TODO: ���� GetListCtrl() ֱ�ӷ��� ListView ���б�ؼ���
	//  �Ӷ������������ ListView��
}

// C�б�ؼ�View ���

#ifdef _DEBUG
void C�б�ؼ�View::AssertValid() const
{
	CListView::AssertValid();
}

void C�б�ؼ�View::Dump(CDumpContext& dc) const
{
	CListView::Dump(dc);
}

C�б�ؼ�Doc* C�б�ؼ�View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(C�б�ؼ�Doc)));
	return (C�б�ؼ�Doc*)m_pDocument;
}
#endif //_DEBUG


// C�б�ؼ�View ��Ϣ�������


void C�б�ؼ�View::OnChance()
{
	// TODO: �ڴ���������������
	static int nStyleIndex=1;
	DWORD style[4]={LVS_REPORT,LVS_ICON,LVS_SMALLICON,LVS_LIST};
	CListCtrl &m_ListCtrl=GetListCtrl();
	SetCtrlStyle(m_ListCtrl.GetSafeHwnd(),style[nStyleIndex]);
	nStyleIndex++;
	if(nStyleIndex>3)
		nStyleIndex=0;
}


void C�б�ؼ�View::OnNMRDblclk(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMITEMACTIVATE lpItem = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
	//@TN
	//	*pResult = 0;
	//// TODO: �ڴ���ӿؼ�֪ͨ����������
	//*pResult = 0;
	int nIndex=lpItem->iItem;
	if(nIndex>=0)
	{
		CListCtrl &m_ListCtrl=GetListCtrl();
		CString str=m_ListCtrl.GetItemText(nIndex,0);
		MessageBox(str);
	}
	*pResult=0;
}


void C�б�ؼ�View::SetCtrlStyle(HWND hWnd, DWORD dwNewStyle)
{
	DWORD dwOldStyle;
		dwOldStyle=GetWindowLong(hWnd,GWL_STYLE);
		if((dwOldStyle & LVS_TYPEMASK)!=dwNewStyle)
		{
			dwOldStyle&=~LVS_TYPEMASK;
			dwNewStyle|=dwOldStyle;
			SetWindowLong(hWnd,GWL_STYLE,dwNewStyle);
		}
}

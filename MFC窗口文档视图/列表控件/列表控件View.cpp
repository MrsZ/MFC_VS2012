
// 列表控件View.cpp : C列表控件View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "列表控件.h"
#endif

#include "列表控件Doc.h"
#include "列表控件View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// C列表控件View

IMPLEMENT_DYNCREATE(C列表控件View, CListView)

BEGIN_MESSAGE_MAP(C列表控件View, CListView)
	ON_COMMAND(ID_CHANCE, &C列表控件View::OnChance)
	ON_NOTIFY_REFLECT(NM_RDBLCLK, &C列表控件View::OnNMRDblclk)
END_MESSAGE_MAP()

// C列表控件View 构造/析构

C列表控件View::C列表控件View()
{
	// TODO: 在此处添加构造代码

}

C列表控件View::~C列表控件View()
{
}

BOOL C列表控件View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CListView::PreCreateWindow(cs);
}

void C列表控件View::OnInitialUpdate()
{
	CListView::OnInitialUpdate();
	//创建图像列表
	m_ImageList.Create(32,32,ILC_COLOR8|ILC_MASK,1,1);
	m_ImageListSmall.Create(16,16,ILC_COLOR8|ILC_MASK,1,1);
	CListCtrl &m_ListCtrl=GetListCtrl();
	m_ListCtrl.SetImageList(&m_ImageList,LVSIL_NORMAL);
	m_ListCtrl.SetImageList(&m_ImageListSmall,LVSIL_SMALL);
	LV_COLUMN listCol;
	char *arCols[4]={"文件名","大小","类型","修改日期"};
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
	//查找当前目录
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
			//获取文件关联的图标和文件类型名
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
			//添加图标
			if(nImage<0)
			{
				nImage=m_ImageList.Add(fi.hIcon);
				SHGetFileInfo(str,0,&fi,sizeof(SHFILEINFO),SHGFI_ICON|SHGFI_SMALLICON);
				m_ImageListSmall.Add(fi.hIcon);
				m_strArray.Add(strTypeName);
			}
			//添加列表项
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
	//设置为报表方式
	SetCtrlStyle(m_ListCtrl.GetSafeHwnd(),LVS_REPORT);
	//设置扩展风格，使得列表项一行，全项选择且显示出网格
	m_ListCtrl.SetExtendedStyle(LVS_EX_FULLROWSELECT|LVS_EX_GRIDLINES);
	//设置宽度
	m_ListCtrl.SetColumnWidth(0,LVSCW_AUTOSIZE);
	m_ListCtrl.SetColumnWidth(1,100);
	m_ListCtrl.SetColumnWidth(2,LVSCW_AUTOSIZE);
	m_ListCtrl.SetColumnWidth(3,200);
	// TODO: 调用 GetListCtrl() 直接访问 ListView 的列表控件，
	//  从而可以用项填充 ListView。
}

// C列表控件View 诊断

#ifdef _DEBUG
void C列表控件View::AssertValid() const
{
	CListView::AssertValid();
}

void C列表控件View::Dump(CDumpContext& dc) const
{
	CListView::Dump(dc);
}

C列表控件Doc* C列表控件View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(C列表控件Doc)));
	return (C列表控件Doc*)m_pDocument;
}
#endif //_DEBUG


// C列表控件View 消息处理程序


void C列表控件View::OnChance()
{
	// TODO: 在此添加命令处理程序代码
	static int nStyleIndex=1;
	DWORD style[4]={LVS_REPORT,LVS_ICON,LVS_SMALLICON,LVS_LIST};
	CListCtrl &m_ListCtrl=GetListCtrl();
	SetCtrlStyle(m_ListCtrl.GetSafeHwnd(),style[nStyleIndex]);
	nStyleIndex++;
	if(nStyleIndex>3)
		nStyleIndex=0;
}


void C列表控件View::OnNMRDblclk(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMITEMACTIVATE lpItem = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
	//@TN
	//	*pResult = 0;
	//// TODO: 在此添加控件通知处理程序代码
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


void C列表控件View::SetCtrlStyle(HWND hWnd, DWORD dwNewStyle)
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

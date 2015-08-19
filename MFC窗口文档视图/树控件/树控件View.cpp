
// 树控件View.cpp : C树控件View 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "树控件.h"
#endif

#include "树控件Doc.h"
#include "树控件View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// C树控件View

IMPLEMENT_DYNCREATE(C树控件View, CTreeView)

BEGIN_MESSAGE_MAP(C树控件View, CTreeView)
	ON_NOTIFY_REFLECT(TVN_SELCHANGED, &C树控件View::OnTvnSelchanged)
END_MESSAGE_MAP()

// C树控件View 构造/析构

C树控件View::C树控件View()
{
	// TODO: 在此处添加构造代码

}

C树控件View::~C树控件View()
{
}

BOOL C树控件View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式
	cs.style|=TVS_HASLINES|TVS_LINESATROOT|TVS_HASBUTTONS;
	return CTreeView::PreCreateWindow(cs);
}

void C树控件View::OnInitialUpdate()
{
	CTreeView::OnInitialUpdate();
	CTreeCtrl &treeCtrl=GetTreeCtrl();
	m_ImageList.Create(16,16,ILC_COLOR8|ILC_MASK,2,1);
	treeCtrl.SetImageList(&m_ImageList,TVSIL_NORMAL);
	CString strPath;
	GetWindowsDirectory((LPTSTR)(LPCTSTR)strPath,MAX_PATH+1);
	SHFILEINFO fi;
	SHGetFileInfo(strPath,0,&fi,sizeof(SHFILEINFO),SHGFI_ICON|SHGFI_SMALLICON);
	m_ImageList.Add(fi.hIcon);
	SHGetFileInfo(strPath,0,&fi,sizeof(SHFILEINFO),SHGFI_ICON|SHGFI_SMALLICON|SHGFI_OPENICON);
	m_ImageList.Add(fi.hIcon);
	CString str;
	for(int i=0;i<32;i++)
	{
		str.Format("%c:\\",'A'+i);
		SHGetFileInfo(str,0,&fi,sizeof(SHFILEINFO),SHGFI_ICON|SHGFI_SMALLICON|SHGFI_DISPLAYNAME);
		if(fi.hIcon)
		{
			int nImage=m_ImageList.Add(fi.hIcon);
			HTREEITEM hItem=treeCtrl.InsertItem(fi.szDisplayName,nImage,nImage);
			treeCtrl.SetItemData(hItem,(DWORD)('A'+i));
		}
	}

}


// C树控件View 诊断

#ifdef _DEBUG
void C树控件View::AssertValid() const
{
	CTreeView::AssertValid();
}

void C树控件View::Dump(CDumpContext& dc) const
{
	CTreeView::Dump(dc);
}

C树控件Doc* C树控件View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(C树控件Doc)));
	return (C树控件Doc*)m_pDocument;
}
#endif //_DEBUG


// C树控件View 消息处理程序


void C树控件View::InsertFoldItem(HTREEITEM hItem, CString strPath)
{
	CTreeCtrl &treeCtrl=GetTreeCtrl();
	if(treeCtrl.ItemHasChildren(hItem))
	{
		return;
	}
	CFileFind finder;
	BOOL bWorking =finder.FindFile(strPath);
	while(bWorking)
	{
		bWorking=finder.FindNextFileA();
		if(finder.IsDirectory()&&!finder.IsHidden()&&!finder.IsDots())
			treeCtrl.InsertItem(finder.GetFileTitle(),0,1,hItem,TVI_SORT);
	}
}


CString C树控件View::GetFoldItemPath(HTREEITEM hItem)
{
	CString strPath,str;
	strPath.Empty();
	CTreeCtrl&treeCtrl=GetTreeCtrl();
	HTREEITEM folderItem=hItem;
	while(folderItem)
	{
		int data=(int)treeCtrl.GetItemData(folderItem);
		if(data==0)
			str=treeCtrl.GetItemText(folderItem);
		else
			str.Format("%c:\\",data);
		strPath=str+"\\"+strPath;
		folderItem=treeCtrl.GetParentItem(folderItem);
	}
	strPath=strPath+"*.*";
	return strPath;
}


void C树控件View::OnTvnSelchanged(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMTREEVIEW pNMTreeView = reinterpret_cast<LPNMTREEVIEW>(pNMHDR);
	
	// TODO: 在此添加控件通知处理程序代码
	HTREEITEM hSelItem=pNMTreeView->itemNew.hItem;
	CTreeCtrl &treeCtrl=GetTreeCtrl();
	CString strPath=GetFoldItemPath(hSelItem);
	if(!strPath.IsEmpty())
	{
		InsertFoldItem(hSelItem,strPath);
		treeCtrl.Expand(hSelItem,TVE_EXPAND);
	}
	*pResult = 0;
}

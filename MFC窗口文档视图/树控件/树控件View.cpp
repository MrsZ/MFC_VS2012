
// ���ؼ�View.cpp : C���ؼ�View ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "���ؼ�.h"
#endif

#include "���ؼ�Doc.h"
#include "���ؼ�View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// C���ؼ�View

IMPLEMENT_DYNCREATE(C���ؼ�View, CTreeView)

BEGIN_MESSAGE_MAP(C���ؼ�View, CTreeView)
	ON_NOTIFY_REFLECT(TVN_SELCHANGED, &C���ؼ�View::OnTvnSelchanged)
END_MESSAGE_MAP()

// C���ؼ�View ����/����

C���ؼ�View::C���ؼ�View()
{
	// TODO: �ڴ˴���ӹ������

}

C���ؼ�View::~C���ؼ�View()
{
}

BOOL C���ؼ�View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ
	cs.style|=TVS_HASLINES|TVS_LINESATROOT|TVS_HASBUTTONS;
	return CTreeView::PreCreateWindow(cs);
}

void C���ؼ�View::OnInitialUpdate()
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


// C���ؼ�View ���

#ifdef _DEBUG
void C���ؼ�View::AssertValid() const
{
	CTreeView::AssertValid();
}

void C���ؼ�View::Dump(CDumpContext& dc) const
{
	CTreeView::Dump(dc);
}

C���ؼ�Doc* C���ؼ�View::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(C���ؼ�Doc)));
	return (C���ؼ�Doc*)m_pDocument;
}
#endif //_DEBUG


// C���ؼ�View ��Ϣ�������


void C���ؼ�View::InsertFoldItem(HTREEITEM hItem, CString strPath)
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


CString C���ؼ�View::GetFoldItemPath(HTREEITEM hItem)
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


void C���ؼ�View::OnTvnSelchanged(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMTREEVIEW pNMTreeView = reinterpret_cast<LPNMTREEVIEW>(pNMHDR);
	
	// TODO: �ڴ���ӿؼ�֪ͨ����������
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

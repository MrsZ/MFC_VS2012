
// 大学生档案View.h : C大学生档案View 类的接口
//

#pragma once

#include "resource.h"
#include "afxwin.h"


class C大学生档案View : public CFormView
{
protected: // 仅从序列化创建
	C大学生档案View();
	DECLARE_DYNCREATE(C大学生档案View)

public:
	enum{ IDD = IDD_MY_FORM };

// 特性
public:
	C大学生档案Doc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
	virtual void OnInitialUpdate(); // 构造后第一次调用

// 实现
public:
	virtual ~C大学生档案View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	CString m_clas;
	CString m_pro;
	CString m_cla;
	CString m_name;
	CString m_stuid;
	CString m_sex;
	CString m_age;
	CString m_tel;
	CString m_pos;
	CComboBox m_noList;
	CString m_school;
	CBitmap m_bitmap;

private:
	int m_nCurrentNo;
public:
	afx_msg void OnClickedButton1();
	afx_msg void OnChangeEditAge();
	afx_msg void OnChangeEditCla();
	afx_msg void OnChangeEditClas();
	afx_msg void OnChangeEditName();
	afx_msg void OnEditNum();
	afx_msg void OnChangeEditPos();
	afx_msg void OnChangeEditPro();
	afx_msg void OnChangeEditSchool();
	afx_msg void OnChangeEditSex();
	afx_msg void OnChangeEditStuid();
	afx_msg void OnChangeEditTel();
	afx_msg void OnSelchangeCombo1();
	afx_msg void OnFileMyopen();
	afx_msg void OnFileMysave();
};

#ifndef _DEBUG  // 大学生档案View.cpp 中的调试版本
inline C大学生档案Doc* C大学生档案View::GetDocument() const
   { return reinterpret_cast<C大学生档案Doc*>(m_pDocument); }
#endif


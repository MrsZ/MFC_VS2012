
// ��ѧ������View.h : C��ѧ������View ��Ľӿ�
//

#pragma once

#include "resource.h"
#include "afxwin.h"


class C��ѧ������View : public CFormView
{
protected: // �������л�����
	C��ѧ������View();
	DECLARE_DYNCREATE(C��ѧ������View)

public:
	enum{ IDD = IDD_MY_FORM };

// ����
public:
	C��ѧ������Doc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	virtual void OnInitialUpdate(); // ������һ�ε���

// ʵ��
public:
	virtual ~C��ѧ������View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
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

#ifndef _DEBUG  // ��ѧ������View.cpp �еĵ��԰汾
inline C��ѧ������Doc* C��ѧ������View::GetDocument() const
   { return reinterpret_cast<C��ѧ������Doc*>(m_pDocument); }
#endif


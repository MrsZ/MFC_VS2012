#pragma once

#include "Resource.h"
// CaddDlg �Ի���

class CaddDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CaddDlg)

public:
	CaddDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CaddDlg();

// �Ի�������
	enum { IDD = IDD_DIALOG};

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CString m_strName;
	CString m_strID;
	float m_feng;
	float m_fmat;
	float m_fcom;
};

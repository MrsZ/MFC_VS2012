
// ���ƾ���Dlg.h : ͷ�ļ�
//

#pragma once
#include "afxcmn.h"
#include "afxwin.h"


// C���ƾ���Dlg �Ի���
class C���ƾ���Dlg : public CDialogEx
{
// ����
public:
	C���ƾ���Dlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_MY_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	int m_Length;
	CSpinButtonCtrl m_LengthSpin;
	int m_Width;
	CSpinButtonCtrl m_WidthSpin;
	CSliderCtrl m_LineWidthSlider;
	CButton m_Room;
	int m_LineWidth;
	afx_msg void OnClickedApply();
	afx_msg void OnClickedExitbutton();
	afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
};

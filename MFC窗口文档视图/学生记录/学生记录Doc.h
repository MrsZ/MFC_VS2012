
// ѧ����¼Doc.h : Cѧ����¼Doc ��Ľӿ�
//


#pragma once

class CStudent:public CObject
{
	CString strName;
	CString strID;
	float feng,fmat,fcom;
	float fAverage;
	DECLARE_SERIAL(CStudent)
public:
	CStudent(){};
	CStudent(CString name,CString id,float f1,float f2,float f3);
	void Serialize(CArchive &ar);
	void Display(int y,CDC* pDC);
};

class Cѧ����¼Doc : public CDocument
{
protected: // �������л�����
	Cѧ����¼Doc();
	DECLARE_DYNCREATE(Cѧ����¼Doc)

// ����
public:
	CObArray m_stuObArray;
// ����
public:

// ��д
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// ʵ��
public:
	virtual ~Cѧ����¼Doc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// ����Ϊ����������������������ݵ� Helper ����
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
public:
	afx_msg void OnSturecAdd();
	CStudent* GetStudentAt(int nIndex);
	int GetAllRecNum(void);
};

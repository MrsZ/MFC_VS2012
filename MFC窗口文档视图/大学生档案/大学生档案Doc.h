
// ��ѧ������Doc.h : C��ѧ������Doc ��Ľӿ�
//


#pragma once


class C��ѧ������Doc : public CDocument
{
protected: // �������л�����
	C��ѧ������Doc();
	DECLARE_DYNCREATE(C��ѧ������Doc)

// ����
public:
	struct
	{
		char clas[10];
		char pro[20];
		char cla[20];
		char name[20];
		char stuid[20];
		char sex[10];
		char age[20];
		char tel[20];
		char pos[20];
		char school[9999];
	}m_student[120];
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
	virtual ~C��ѧ������Doc();
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
};

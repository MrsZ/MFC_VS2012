
// 学生记录Doc.h : C学生记录Doc 类的接口
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

class C学生记录Doc : public CDocument
{
protected: // 仅从序列化创建
	C学生记录Doc();
	DECLARE_DYNCREATE(C学生记录Doc)

// 特性
public:
	CObArray m_stuObArray;
// 操作
public:

// 重写
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// 实现
public:
	virtual ~C学生记录Doc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// 用于为搜索处理程序设置搜索内容的 Helper 函数
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
public:
	afx_msg void OnSturecAdd();
	CStudent* GetStudentAt(int nIndex);
	int GetAllRecNum(void);
};

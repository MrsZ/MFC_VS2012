
// 大学生档案Doc.h : C大学生档案Doc 类的接口
//


#pragma once


class C大学生档案Doc : public CDocument
{
protected: // 仅从序列化创建
	C大学生档案Doc();
	DECLARE_DYNCREATE(C大学生档案Doc)

// 特性
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
	virtual ~C大学生档案Doc();
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
};

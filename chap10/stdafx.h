#pragma once
#include<Windows.h>

#define DECLARE_MESSAGE_MAP() static MessageMap messageMap[];
#define BEGIN_MESSAGE_MAP(class_name) MessageMap class_name::messageMap[] =
#define END_MESSAGE_MAP()	{0,NULL}};

#define RUNTIME_CLASS(class_name) (&class_name::class##class_name)
#define DECLARE_DYNAMIC(class_name)	static CRuntimeClass class##class_name;

#define IMPLEMENT_DYNAMIC(class_name) CRuntimeClass\
		class_name::class##classs_name={\
		(#class_name),\
		sizeof(class_name),\
		class_name::CreateObject;

#define DECLARE_DYNCREATE(class_name)\
		DECLARE_DYNAMIC(class_name)\
		CObject* class_name::CreateObject(){return new class_name;}

LRESULT CALLBACK WndProc(HWND hend, UINT iMsg, WPARAM wParam, LPARAM lParam);

class CObject;

struct CRuntimeClass
{
	char m_lpzClassName[21];
	int m_ObjectSize;
	CObject* (*pfnCreateObject)();
	CObject* CreateObject();
};

class CView;

typedef void(CView::*CViewFunPointer)();
typedef struct tagMessageMap
{
	UINT iMsg;
	CViewFunPointer fp;
}MessafeMap;


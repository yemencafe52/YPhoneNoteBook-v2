#ifndef _ACCESSDB_H
#define _ACCESSDB_H

#include <afxwin.h>
#include <afxdb.h>

static CDatabase* db = nullptr;
class __declspec(dllexport) CAccessDB
{
public:
	CAccessDB(const CString& connectionString);
	bool ExceuteNoneQuery(const CString& sql);
	bool ExceuteQuery(const CString& sql);
	void CloseConnection();
	CRecordset* GetRS();

private:
	CString connectionString;
	CRecordset* rs = nullptr;
};

#endif _ACCESSDB_H// !_ACCESSDB_H

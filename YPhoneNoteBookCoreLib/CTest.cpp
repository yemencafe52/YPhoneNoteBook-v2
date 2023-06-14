#include "CTest.h"
//#include "../DSLib/CAccessDB.h"
#include "CPersonController.h"

CString CurrentDirectory()
{
	CString res = "";
	WCHAR temp[256];
	WCHAR temp2[256];

	memset(temp, 0, 256 * 2);
	memset(temp2, 0, 256 * 2);

	int len = GetCurrentDirectoryW(256, temp);

	if (len > 0)
	{
		memcpy(temp2, temp, len*2);
	}

	res = CString(temp2);
	return res;
}

int main()
{
	CString dbPath = "C:\\DataBase\\db.accdb";
	CString connectionString = "DRIVER={Microsoft Access Driver (*.mdb, *.accdb)};pwd=123;User ID=admin;DBQ=" + dbPath;
	
	CPerson p(3, "per3", "123");
	CAccessDB db0(connectionString);

	CPersonController pc(db0);
	pc.Add(p);
	
	return 0;
}
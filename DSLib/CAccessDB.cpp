#include "CAccessDB.h"

CAccessDB::CAccessDB(const CString& connectionString)
:connectionString(connectionString)
{}

bool CAccessDB::ExceuteNoneQuery(const CString& sql) {
	bool res = false;

	try
	{
		if (db == nullptr)
		{
			db = new CDatabase();
			db->OpenEx(this->connectionString, CDatabase::noOdbcDialog);
		}

		if (!(db->IsOpen()))
		{
			db->Close();
			db->OpenEx(this->connectionString, CDatabase::noOdbcDialog);
		}

		db->ExecuteSQL(sql);
		res = true;
	}
	catch(int){}
	return res;
}

bool CAccessDB::ExceuteQuery(const CString& sql) {
	bool res = false;

	try
	{
		if (db == nullptr)
		{
			db = new CDatabase();
			db->OpenEx(this->connectionString, CDatabase::noOdbcDialog);
		}

		if (!(db->IsOpen()))
		{
			db->Close();
			db->OpenEx(this->connectionString, CDatabase::noOdbcDialog);
		}

		//if (this->rs == nullptr) {
			this->rs = new CRecordset();
			this->rs->m_pDatabase = db;
		//}

		/*if ((this->rs->IsOpen()))
		{
			this->rs->Close();
		}*/

		this->rs->Open(CRecordset::snapshot, sql, CRecordset::readOnly);

		if (!(this->rs->IsEOF()))
		{
			res = true;
		}
	}
	catch (int) {}
	return res;
}

void CAccessDB::CloseConnection() {

	if (this->rs != nullptr)
	{
		if (this->rs->IsOpen())
		{
			void* p = this->rs;
			this->rs->Close();
			this->rs = nullptr;
			delete p;
		}
	}

	if (db != nullptr) {
		if (db->IsOpen()) {
			db->Close();
		}
	}
}

CRecordset* CAccessDB::GetRS() {
	return this->rs;
}

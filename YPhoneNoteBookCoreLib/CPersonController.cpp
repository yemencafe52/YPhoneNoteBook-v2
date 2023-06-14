#include "CPersonController.h"

extern CString IntToStr(int number);

CString GetFieldValueByName(CRecordset* rs, const CString& fieldName)
{
	CString res = "";
	rs->GetFieldValue(fieldName, res);
	return res;
}

CPersonController::CPersonController(CAccessDB& db) :db(db) {}

bool CPersonController::Add(const CPerson& person) {
	bool res = false;

	try {
		CString sql = "insert into tblPeople (pName,pPhone) values('" + person.Name() + "','" + person.Phone() + "')";

		res = db.ExceuteNoneQuery(sql);
	}
	catch (int) {

	}
	return res;
}

bool CPersonController::Update(int number, const CPerson& person) {
	bool res = false;

	CString sql = "update tblPeople set pName='"+person.Name()+"',pPhone='"+person.Phone()+"' where pNumber=" + IntToStr(number);
	res = db.ExceuteNoneQuery(sql);

	return res;
}

bool CPersonController::Delete(int number) {
	bool res = false;

	CString sql = "delete from tblPeople where pNumber=" + IntToStr(number);
	res = db.ExceuteNoneQuery(sql);

	return res;
}

bool CPersonController::Read(int number, CPerson** person) {
	bool res = false;

	try {
		CString sql = "select pNumber,pName,pPhone from tblPeople where pNumber=" + IntToStr(number);

		if (db.ExceuteQuery(sql))
		{
			CRecordset* rs = db.GetRS();
			*person = new CPerson(_wtoi(GetFieldValueByName(rs, "pNumber")), GetFieldValueByName(rs, "pName"), GetFieldValueByName(rs, "pPhone"));
			rs->Close();
			delete rs;
			res = true;
		}
	}catch(int){}

	return res;
}

bool CPersonController::Search(const CString& txt, std::vector<CPerson*>& people) {

	bool res = false;


	try {
		CString sql = "select pNumber,pName,pPhone from tblPeople where pName like('%" + txt + "%')";

		if (db.ExceuteQuery(sql))
		{
			CRecordset* rs = db.GetRS();

			while (!(rs->IsEOF()))
			{
				people.push_back(new CPerson(_wtoi(GetFieldValueByName(rs, "pNumber")), GetFieldValueByName(rs, "pName"), GetFieldValueByName(rs, "pPhone")));
				rs->MoveNext();
			}

			rs->Close();
			delete rs;
			res = true;
		}
	}catch(int){}

	return res;
}

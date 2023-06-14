#ifndef _PERSONCONTROLLER_H
#define _PERSONCONTROLLER_H

#include  "../DSLib/CAccessDB.h"
#include "CPerson.h"
#include <vector>

class  __declspec(dllexport) CPersonController
{
public:
	CPersonController(CAccessDB& db);
	bool Add(const CPerson& person);
	bool Update(int number,const CPerson& person);
	bool Delete(int number);
	bool Read(int number,CPerson** person);
	bool Search(const CString&txt,std::vector<CPerson*>& people);
		
private:
	CAccessDB db;
};

#endif _PERSONCONTROLLER_H// !_PERSONCONTROLLER_H

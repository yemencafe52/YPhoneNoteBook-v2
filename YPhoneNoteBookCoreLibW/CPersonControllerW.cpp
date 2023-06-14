#include "CPersonControllerW.h"
#include "../YPhoneNoteBookCoreLib//CPersonController.h"

namespace YPhoneNoteBookCoreLibW
{
	using namespace System;
	using namespace System::Runtime::InteropServices;
	using namespace System::Collections::Generic;

	extern CString StrToCStr(String^ str);
	extern String^ CStrToStr(const CString& str);

	CPersonControllerW::CPersonControllerW(String^ connectionString) {
		this->connectionString = connectionString;
	}

	bool CPersonControllerW::Add(PersonW^ person) {
		bool res = false;

		try {
			CAccessDB db(StrToCStr(this->connectionString));
			CPersonController pc(db);
			res = pc.Add(CPerson(person->Number, StrToCStr(person->Name), StrToCStr(person->Phone)));
		}
		catch (Exception^ e) {

		}

		return res;
	}

	bool CPersonControllerW::Update(int number, PersonW^ person) {
		bool res = false;

		CAccessDB db(StrToCStr(this->connectionString));
		CPersonController pc(db);
		res = pc.Update(number,CPerson(person->Number, StrToCStr(person->Name), StrToCStr(person->Phone)));

		return res;
	}

	bool CPersonControllerW::Delete(int number) {
		bool res = false;

		CAccessDB db(StrToCStr(this->connectionString));
		CPersonController pc(db);
		res = pc.Delete(number);

		return res;
	}

	bool CPersonControllerW::Read(int number,[Out] PersonW^% person) {
		bool res = false;

		try {
			CAccessDB db(StrToCStr(this->connectionString));
			CPersonController pc(db);

			CPerson* p = nullptr;
			if (pc.Read(number, &p))
			{
				person = gcnew PersonW(p->Number(), CStrToStr(p->Name()), CStrToStr(p->Phone()));
				delete p;
				res = true;
			}

		}
		catch (Exception ^ e) {

		}
		return res;
	}

	bool CPersonControllerW::Search(String^ txt, [Out] List<PersonW^>^% peopleResults) {
		bool res = false;

		try {
			peopleResults = gcnew List<PersonW^>();

			CAccessDB db(StrToCStr(this->connectionString));
			CPersonController pc(db);

			std::vector<CPerson*> people;

			if (pc.Search(txt, people))
			{
				int len = people.size();
				for (int i = 0; i < len; i++)
				{
					peopleResults->Add(gcnew PersonW(people[i]->Number(), CStrToStr(people[i]->Name()), CStrToStr(people[i]->Phone())));
					delete people[i];
				}

				res = true;
			}
		}
		catch (Exception ^ e) {

		}

		return res;
	}
}
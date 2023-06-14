#include "CPersonW.h"

namespace YPhoneNoteBookCoreLibW
{
	using namespace System;

	extern CString StrToCStr(String^ str);
	extern String^ CStrToStr(const CString& str);

	PersonW::PersonW(int pNumber, String^ pName, String^ pPhone) {
		this->person = new CPerson(pNumber, StrToCStr(pName), StrToCStr(pPhone));
	}

	int PersonW::Number::get(){ 
		return this->person->Number();
	}

	String^ PersonW::Name::get()
	{
		String^ res = CStrToStr(this->person->Name());
		return res;
	}

	String^ PersonW::Phone::get() {
		String^ res = CStrToStr(this->person->Phone());
		return res;
	}
}
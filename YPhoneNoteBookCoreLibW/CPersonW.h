#ifndef _PERSONW_H
#define _PERSONW_H

#include "../YPhoneNoteBookCoreLib/CPerson.h"

namespace YPhoneNoteBookCoreLibW
{
	using namespace System;
	public ref class PersonW
	{
	public:
		PersonW(int pNumber, String^ pName, String^ pPhone);

		property int Number {int get(); }
		property String^ Name {String^ get(); };
		property String^ Phone {String^ get(); };

	private:
		CPerson* person;
	};
}

#endif _PERSONW_H// !_PERSONW_H


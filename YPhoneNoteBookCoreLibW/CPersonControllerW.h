#ifndef _PERSONCONTROLLERW_H
#define _PERSONCONTROLLERW_H

#include "CPersonW.h"

namespace YPhoneNoteBookCoreLibW
{
	using namespace System;
	using namespace System::Runtime::InteropServices;
	using namespace System::Collections::Generic;

	public ref class CPersonControllerW
	{
	public:
		CPersonControllerW(String^ connectionString);
		bool Add(PersonW^ person);
		bool Update(int number,PersonW^ person);
		bool Delete(int number);
		bool Read(int number,[Out] PersonW^%);
		bool Search(String^txt,[Out] List<PersonW^>^%PersonW);

	private:
		String^ connectionString;
	};
}
#endif _PERSONCONTROLLERW_H// !_PERSONCONTROLLERW_H

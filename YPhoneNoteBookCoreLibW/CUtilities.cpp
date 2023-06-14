#include "CUtilities.h"


namespace YPhoneNoteBookCoreLibW
{
	using namespace System;
	using namespace System::Runtime::InteropServices;

	CString StrToCStr(String^ str)
	{
		IntPtr ptr =  Marshal::StringToHGlobalUni(str);
		CString res((wchar_t*)ptr.ToPointer());
		Marshal::FreeHGlobal(ptr);

		return res;
	}

	String^ CStrToStr(const CString& str)
	{
		IntPtr r = (IntPtr)((wchar_t*)str.GetString());
		String^ res = Marshal::PtrToStringUni(r);
		return res;
	}
}

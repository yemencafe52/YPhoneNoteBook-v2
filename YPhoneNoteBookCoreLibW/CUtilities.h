#ifndef _YPNBCLW_UTILITIES_H
#define _YPNBCLW_UTILITIES_H

#include <afxwin.h>

namespace YPhoneNoteBookCoreLibW
{
	using namespace System;

	CString StrToCStr(String^ str);
	String^ CStrToStr(const CString& str);
}

#endif _YPNBCLW_UTILITIES_H// !_YPNBCLW_UTILITIES_H

#include "CUtilities.h"

CString IntToStr(int number) {
	CString res = "";
	res.Format(L"%d", number);
	return res;
}

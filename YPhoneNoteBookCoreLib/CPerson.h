#ifndef _PERSON_H
#define _PERSON_H

#include <afxwin.h>

class __declspec(dllexport) CPerson
{
public:
	CPerson(
		int pNumber,
		const CString& pName,
		const CString& pPhone
	);

	int Number() const;
	const CString& Name() const;
	const CString& Phone() const;

private:
	int pNumber;
	CString pName;
	CString pPhone;
};

#endif _PERSON_H// !_PERSON_H

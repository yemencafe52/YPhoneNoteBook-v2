#include "CPerson.h"

CPerson::CPerson(
	int pNumber,
	const CString& pName,
	const CString& pPhone
)
:pNumber(pNumber),pName(pName),pPhone(pPhone){}

int CPerson::Number() const {
	return this->pNumber;
}
const CString& CPerson::Name() const {
	return this->pName;
}
const CString& CPerson::Phone() const {
	return this->pPhone;
}

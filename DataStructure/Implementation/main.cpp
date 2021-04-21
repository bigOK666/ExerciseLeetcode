#include "myString.h"

int main()
{
	myString str1;
	char* t= "test";
	myString str2(t);
	myString str3(str2);
}
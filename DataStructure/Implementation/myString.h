#ifndef _MYSTRING_H
#define _MYSTRING_H
#include<cstring>

class myString
{
public:
	myString() :m_data(new char[1]) { *m_data = '\0'; }
	myString(const char* str) :m_data(new char[strlen(str) + 1]) { strcpy(m_data, str); }
	//¿½±´¹¹Ôìº¯Êý
	myString(const myString& rhs) :m_data(new char[rhs.size() + 1]) { strcpy(m_data, rhs.m_data); }
	~myString() { delete[]m_data; }

	unsigned size() const { return strlen(m_data); }
private:
	char* m_data;
};

#endif
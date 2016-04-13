#ifndef _MYSTRING
#define __MYSTRING
#include <string.h>
#include <stdio.h>

#include "Vector.h"

class MyString{
public: 
	char* first = nullptr;
	char* second = nullptr;
private:
	char* buffer = nullptr;
	
	unsigned int MaxSize;
public:
	MyString(){}

	MyString(const char* str)
	{
		int len = (strlen(str));
		buffer = new char[len + 1];
		MaxSize = len + 1;
		strcpy_s(buffer, len + 1, str);
		

	}
	MyString(const MyString& str)
	{
		int len = (strlen(str.buffer));
		buffer = new char[len + 1];
		MaxSize = len + 1;
		strcpy_s(this->buffer, len + 1, str.buffer);
		
	}
	~MyString()
	{
		delete[] buffer;
		
	}
	unsigned int MyLength() const
	{
		int length = (strlen(buffer));
		return length;
	}
	const char* c_str()const //function to print 
	{
		return buffer;
	}

	bool empty()const//checks if buffer is null
	{
		return strlen(buffer) == 0;
	}
	bool operator == (const MyString& another)const
	{
		return strcmp(buffer, another.buffer) == 0;

	}
	bool operator == (const char* another)const
	{
		
		return strcmp(buffer, another) == 0;

	}
	/*
	void operator += (const MyString& one)
	{
	char *temp = nullptr;
	temp = new char[strlen(buffer) + 1];
	strcpy_s(temp, strlen(buffer) + 1, buffer);
	delete[]buffer;
	int lenght = strlen(temp) + strlen(one.buffer) + 1;
	buffer = new char[lenght];
	strcpy_s(buffer, lenght, temp);


	}*/
	void operator = (const MyString& one)
	{

		//int lenght = strlen(one.buffer)+1;

		if ((strlen(one.buffer) + 1 > MaxSize)) //Revise
		{

			delete[]buffer;
			MaxSize = (strlen(one.buffer) + 1);
			buffer = new char[MaxSize];
		}

		strcpy_s(buffer, MaxSize, one.buffer);
	}
	MyString operator + (const MyString& one)
	{
		MyString third;
		int lenght = strlen(buffer) + strlen(one.buffer) + 1;
		third.buffer = new char[lenght];
		strcpy_s(third.buffer, lenght, buffer);
		strcat_s(third.buffer, lenght, one.buffer);
		return third;
	}
	//EXTRA OPERATIONS FOR ZORK
	MyString operator = (const char* word)
	{
		int len = strlen(word) + 1;
		buffer = new char[len];
		strcpy_s(buffer, len, word);
		return buffer;
	}
	void tokenize(const char* symbol,  Vector <MyString> tokens)
	{
		
		char *Counter;
		char *word;
		word = strtok_s(buffer, symbol, &Counter);
		//strtok_s(NULL, symbol, &Counter);
		while (buffer != NULL)
		{
			tokens.Push_back(buffer);
			//strtok_s(NULL, symbol, &Counter);
		}
		//first->buffer= strtok_s(buffer, symbol, &Counter);
		//tokens.Push_back(first->buffer);
		//two.buffer = strtok_s(NULL, " ", &Counter);
		printf("%s", buffer);
	}

	void Get(const char* string)
	{
		int len = strlen(string);
		delete[]buffer;
		buffer = new char[len + 1];
		strcpy_s(buffer, len + 1, string);
	}

};
#endif
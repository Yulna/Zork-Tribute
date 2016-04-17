#include "My_String.h"
#include <string.h>
#include <stdio.h>

String::String(){
	the_string = new char[5];
	max_size = 5;
};
String::String(const char* str){
	int len = strlen(str);
	the_string = new char[len+1];
	strcpy_s(the_string, len + 1, str);
	max_size = len + 1;
};
String::String(const String& str){
	int len = strlen(str.the_string);
	the_string = new char[len + 1];
	strcpy_s(the_string, len + 1, str.the_string);
	max_size = len + 1;
};

String::~String(){
	delete[] the_string;
};


unsigned int String::lenght() const{
	return strlen(the_string);
};
unsigned int String::capacity() const{
	return max_size;
};

const char* String::get_str() const{
	return the_string;
};
void String::write_str(){
	char input_string[20];
	gets_s(input_string);
	unsigned int cap = strlen(input_string)+1;
	if (cap > max_size){
		delete[] the_string;
		max_size = cap;
		the_string = new char[max_size];
	}
	strcpy_s(the_string, max_size, input_string);
}

void String::print_str() const {
	printf("%s\n", the_string);
};

bool String::empty() const{
	return the_string[0] == '\0';
};

bool String::operator==(const String& str) const{
	if (_stricmp(the_string, str.the_string) == 0)
		return true;
	else
		return false;
};


void String::operator=(const String &other_str){
	int len = other_str.lenght()+1;
	if (max_size < len) {
		max_size = len;
		delete[] the_string;
		the_string = new char[max_size];
	}
	strcpy_s(the_string, len, other_str.the_string);
};

void String::operator+=(const String &other_str){
	int total_len = lenght() + other_str.lenght();
	unsigned int string_end = lenght() + 1;

	if (max_size < total_len + 1)	{
		max_size = total_len + 1;
		delete[] the_string;
		the_string = new char[max_size];
	}
}

//Tokonize
//Size depending in how many  words
Vector<String*> String::tokenize(){
	Vector<String*> ret;
	char* context = nullptr;

	ret.pushback(new String (strtok_s(the_string, " ", &context)));

	while (*context != '\0'){
		ret.pushback(new String(strtok_s(NULL, " ", &context)));
	}
	return ret;
};

#ifndef __STRING_H__
#define __STRING_H__

#include <string.h>
#include "Vector.h"

class String{
private:
	char* the_string = nullptr;
	unsigned int max_size;

public:
	String();
	String(const char* str);
	String(const String& str);
	~String();

	unsigned int lenght() const;
	unsigned int capacity() const;
	const char* get_str() const;
	void write_str();
	void print_str() const;

	bool empty() const;
	bool operator == (const String& str) const;
	void operator=(const String &other_str);
	void operator+=(const String &other_str);

	void tokenize(Vector<String*> &tokens);
	
};
#endif // !__STRING_H__
#pragma once
#include <iostream>
#include <fstream>
#pragma warning (disable : 4996)

class MyString
{
private:
	char* data = nullptr;
	size_t size = 0;
	size_t capacity = 16;

	MyString(size_t size);
	void copyFrom(const MyString& other);
	void moveFrom(MyString&& other);
	void free();
public:
	MyString() = default;
	MyString(const char* str);
	MyString(const MyString& other);
	MyString(MyString&& other) noexcept;

	MyString& operator=(const MyString& other);
	MyString& operator=(MyString&& other) noexcept;
	MyString& operator+=(const MyString& other);

	const char& operator[](size_t index)const;
	char& operator[](size_t index);
	friend std::istream& operator>>(std::istream& is, MyString& str);
	friend std::ostream& operator<<(std::ostream& os, const MyString& str);
	friend MyString operator+(const MyString& lhs, const MyString& rhs);
	operator bool()const;

	void resize(size_t newAllocatadDataSize);
	const char* getData()const;
	size_t getSize()const;
	size_t getCapacity()const;

	MyString subStr(size_t begin, size_t howMany);

	~MyString();
};

bool operator==(const MyString& lhs, const MyString& rhs);
bool operator<=(const MyString& lhs, const MyString& rhs);
bool operator>=(const MyString& lhs, const MyString& rhs);
bool operator<(const MyString& lhs, const MyString& rhs);
bool operator>(const MyString& lhs, const MyString& rhs);
bool operator!=(const MyString& lhs, const MyString& rhs);


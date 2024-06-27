#include <iostream>
#include "MyString.h"

static unsigned findClosestPowerOfTwo(size_t v) {
	v--;
	v |= v >> 1;
	v |= v >> 2;
	v |= v >> 4;
	v |= v >> 8;
	v |= v >> 16;
	v++;
	return v;
}
static unsigned dataToAllocataForString(size_t size) {
	return std::max(findClosestPowerOfTwo(size + 1), 16u);
}

void MyString::copyFrom(const MyString& other)
{
	size = other.size;
	capacity = other.capacity;
	data = new char[capacity];
	strcpy(data, other.data);
}
void MyString::moveFrom(MyString&& other)
{
	size = other.size;
	capacity = other.capacity;
	data = other.data;
	other.data = nullptr;
	other.size = 0;
	other.capacity = 0;
}
void MyString::free()
{
	delete[] data;
	size = 0;
	capacity = 0;
}
MyString::MyString(size_t size) {
	this->size = size;
	capacity = dataToAllocataForString(size);
	data = new char[capacity];
}


MyString::MyString(const char* str)
{
	size = strlen(str);
	capacity = dataToAllocataForString(size);
	data = new char[capacity];
	strcpy(data, str);
}
MyString::MyString(const MyString& other)
{
	copyFrom(other);
}
MyString::MyString(MyString&& other) noexcept
{
	moveFrom(std::move(other));
}

MyString& MyString::operator=(const MyString& other)
{
	if (this != &other) {
		free();
		copyFrom(other);
	}
	return *this;
}
MyString& MyString::operator=(MyString&& other) noexcept
{
	if (this != &other) {
		free();
		moveFrom(std::move(other));
	}
	return *this;
}

MyString& MyString::operator+=(const MyString& other)
{
	if (size + other.size + 1 > capacity) {
		resize(dataToAllocataForString(size + other.size));
	}
	strncat(data, other.data, other.size);
	size += other.size;
	return *this;
}

const char& MyString::operator[](size_t index) const
{
	if (index >= size) {
		throw std::exception();
	}
	return data[index];
}
char& MyString::operator[](size_t index)
{
	if (index >= size) {
		throw std::exception();
	}
	return data[index];
}

MyString::operator bool() const
{
	if (data) {
		return true;
	}
	return false;
}

void MyString::resize(size_t newAllocatadDataSize)
{
	char* newData = new char[newAllocatadDataSize];
	strcpy(newData, data);
	delete[]data;
	data = newData;
	capacity = newAllocatadDataSize;
}
const char* MyString::getData() const
{
	return data;
}

size_t MyString::getSize() const
{
	return size;
}

size_t MyString::getCapacity() const
{
	return capacity;
}

MyString MyString::subStr(size_t begin, size_t howMany)
{
	if (begin + howMany > size) {
		throw std::exception();
	}
	MyString result(howMany + 1);
	strncat(result.data, data + begin, howMany);
	return result;
}

MyString::~MyString()
{
	free();
}

std::istream& operator>>(std::istream& is, MyString& str)
{
	char buff[1024];
	is >> buff;
	str.size = strlen(buff);
	if (str.capacity < str.size) {
		str.resize(dataToAllocataForString(str.size));
	}
	str.data = new char[str.size + 1];
	strcpy(str.data, buff);
	return is;
}
std::ostream& operator<<(std::ostream& os, const MyString& str)
{
	return os << str.data;
}

MyString operator+(const MyString& lhs, const MyString& rhs)
{
	MyString result(lhs);
	result += rhs;
	return result;
}

bool operator==(const MyString& lhs, const MyString& rhs)
{
	return strcmp(lhs.getData(), rhs.getData()) == 0;
}

bool operator<=(const MyString& lhs, const MyString& rhs)
{
	return strcmp(lhs.getData(), rhs.getData()) <= 0;
}

bool operator>=(const MyString& lhs, const MyString& rhs)
{
	return strcmp(lhs.getData(), rhs.getData()) >= 0;
}

bool operator<(const MyString& lhs, const MyString& rhs)
{
	return strcmp(lhs.getData(), rhs.getData()) < 0;
}

bool operator>(const MyString& lhs, const MyString& rhs)
{
	return strcmp(lhs.getData(), rhs.getData()) > 0;
}

bool operator!=(const MyString& lhs, const MyString& rhs)
{
	return !(lhs == rhs);
}
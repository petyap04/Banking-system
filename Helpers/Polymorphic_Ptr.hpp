#pragma once 
#include <utility>
#include <stdexcept>
#include <fstream>
//#include "../Users/h/UsersFactory.h"
//#include "../Users/Tasks/h/TaskFactory.h"

template <class T>
class Polymorphic_Ptr {
	T* data = nullptr;

	void copyFrom(const Polymorphic_Ptr<T>& other);
	void moveFrom(Polymorphic_Ptr<T>&& other);
	void free();

public:
	Polymorphic_Ptr() = default;
	Polymorphic_Ptr(T* data);
	Polymorphic_Ptr(const Polymorphic_Ptr<T>& other);
	Polymorphic_Ptr(Polymorphic_Ptr<T>&& other) noexcept;

	Polymorphic_Ptr<T>& operator=(const Polymorphic_Ptr<T>& other);
	Polymorphic_Ptr<T>& operator=(Polymorphic_Ptr<T>&& other) noexcept;

	~Polymorphic_Ptr();

	T* operator->();
	const T* operator->() const;

	T& operator*();
	const T& operator*() const;

	operator bool() const;
	void reset(T* data);

	T* get();
	const T* get() const;
	
};


template<class T>
void Polymorphic_Ptr<T>::copyFrom(const Polymorphic_Ptr<T>& other)
{
	data = other.data->clone();
}

template<class T>
void Polymorphic_Ptr<T>::moveFrom(Polymorphic_Ptr<T>&& other)
{
	data = other.data;
	other.data = nullptr;
}

template<class T>
void Polymorphic_Ptr<T>::free()
{
	delete data;
}

template<class T>
Polymorphic_Ptr<T>::Polymorphic_Ptr(T* data) : data(data)
{
}

template<class T>
inline Polymorphic_Ptr<T>::Polymorphic_Ptr(const Polymorphic_Ptr<T>& other)
{
	copyFrom(other);
}

template<class T>
Polymorphic_Ptr<T>::Polymorphic_Ptr(Polymorphic_Ptr<T>&& other) noexcept
{
	moveFrom(std::move(other));
}

template<class T>
Polymorphic_Ptr<T>& Polymorphic_Ptr<T>::operator=(const Polymorphic_Ptr<T>& other)
{
	if (this != &other) {
		free();
		copyFrom(other);
	}
	return *this;
}

template<class T>
Polymorphic_Ptr<T>& Polymorphic_Ptr<T>::operator=(Polymorphic_Ptr<T>&& other) noexcept
{
	if (this != &other) {
		free();
		moveFrom(std::move(other));
	}
	return *this;
}

template<class T>
Polymorphic_Ptr<T>::~Polymorphic_Ptr()
{
	free();
}

template<class T>
T* Polymorphic_Ptr<T>::operator->()
{
	return data;
}

template<class T>
const T* Polymorphic_Ptr<T>::operator->() const
{
	return data;
}

template<class T>
T& Polymorphic_Ptr<T>::operator*()
{
	if (data == nullptr) {
		throw std::runtime_error("ptr is nullptr");
	}
	return *data;
}

template<class T>
const T& Polymorphic_Ptr<T>::operator*() const
{
	if (data == nullptr) {
		throw std::runtime_error("ptr is nullptr");
	}
	return *data;
}

template<class T>
Polymorphic_Ptr<T>::operator bool() const
{
	return data != nullptr;
}

template<class T>
void Polymorphic_Ptr<T>::reset(T* data)
{
	if (this->data != data) {
		free();
		this->data = data;
	}
}

template<class T>
T* Polymorphic_Ptr<T>::get()
{
	return data;
}

template<class T>
const T* Polymorphic_Ptr<T>::get() const
{
	return data;
}

//template<typename T>
//std::ostream& operator<<(std::ostream& ofs, const Polymorphic_Ptr<T> ptr)
//{
//	return ofs;
//}

//template<>
//std::ostream& operator<<<User>(std::ostream& ofs, const Polymorphic_Ptr<User> ptr)
//{
//	serialise(ofs, ptr.get());
//	return ofs;
//}
//
//template<>
//std::ostream& operator<<<Task>(std::ostream& ofs, const Polymorphic_Ptr<Task> ptr)
//{
//	serialise(ofs, ptr.get());
//	return ofs;
//}

//template<typename T>
//std::istream& operator>>(std::istream& ifs, Polymorphic_Ptr<T> ptr)
//{
//	return ifs;
//}

//template<>
//std::istream& operator>><User>(std::istream& ifs, Polymorphic_Ptr<User> ptr)
//{
//	deserialization(ifs, ptr.get());
//	return ifs;
//}
//
//template<>
//std::istream& operator>><Task>(std::istream& ifs, Polymorphic_Ptr<Task> ptr)
//{
//	deserialization(ifs, ptr.get());
//	return ifs;
//}
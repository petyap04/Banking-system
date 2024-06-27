#pragma once
#include <iostream>

template<class T>
struct Queue {
private:
    T* data = nullptr;
    size_t size = 0;
    size_t capacity = 0;
    size_t get = 0;
    size_t put = 0;

    void copyFrom(const Queue<T>& other);
    void moveFrom(Queue<T>&& other);
    void free();
    void resize(size_t newCap);
    Queue(size_t capacity);
public:
    Queue() = default;
    Queue(const Queue<T>& other);
    Queue(Queue<T>&& other);

    Queue& operator=(const Queue<T>& other);
    Queue& operator=(Queue<T>&& other);

    void push(const T& elem);
    T& peek()const;
    void pop();
    bool isEmpty()const;

    ~Queue();
};

template<class T>
void Queue<T>::copyFrom(const Queue<T>& other)
{
    size = other.size;
    capacity = other.capacity;
    get = other.get;
    put = other.put;

    data = new T[capacity];
    for (int i = 0; i < size; i++) {
        data[i] = other.data[i];
    }
}

template<class T>
void Queue<T>::moveFrom(Queue<T>&& other)
{
    size = other.size;
    capacity = other.capacity;
    data = other.data;
    other.data = nullptr;
    get = other.get;
    put = other.put;

    other.size = other.capacity = other.get = other.put = 0;

}

template<class T>
void Queue<T>::free()
{
    delete[]data;
    size = capacity = get = put = 0;
}

template<class T>
void Queue<T>::resize(size_t newCap)
{
    T* newData = new T[newCap];

    for (int i = 0; i < size; i++) {
        get %= capacity;
        newData[i] = data[get];
        get++;
    }
    delete[]data;
    data = newData;
    capacity = newCap;
    get = 0;
    put = size;
}

template<class T>
Queue<T>::Queue(const Queue<T>& other)
{
    copyFrom(other);
}

template<class T>
Queue<T>::Queue(Queue<T>&& other)
{
    moveFrom(std::move(other));
}

template<class T>
Queue<T>& Queue<T>::operator=(const Queue<T>& other)
{
    if (this != &other) {
        free();
        copyFrom(other);
    }
    return *this;
}

template<class T>
Queue<T>& Queue<T>::operator=(Queue<T>&& other)
{
    if (this != &other) {
        free();
        moveFrom(std::move(other));
    }
    return *this;
}

template<class T>
void Queue<T>::push(const T& elem)
{
    if (capacity == 0) {
        resize(1);
    }
    else if (size == capacity) {
        resize(2 * capacity);
    }
    data[put++] = elem;
    size++;
}

template<class T>
T& Queue<T>::peek() const
{
    return data[get];
}

template<class T>
void Queue<T>::pop()
{
    get++;
    size--;
}

template<class T>
bool Queue<T>::isEmpty() const
{
    return size == 0;
}

template<class T>
Queue<T>::~Queue()
{
    free();
}
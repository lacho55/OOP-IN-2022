#include<iostream>
#include<fstream>
#include<cassert>

template<typename T>
class Vector
{
private:
	T* arr;
	size_t capacity;
	size_t size;
	
	void copy(const Vector<T>& other);
	void erase();
	void resize();
public:
	Vector();
	Vector(size_t capacity);
	Vector(const T* arr, int size, int capacity);
	Vector(const Vector& other);
	Vector& operator=(const Vector& other);
	void addElem(const T element);
	void remove();
	T& getAt(const int index)const;
	void setAt(const int index, const T element);
	T& operator[](const int index)const;
	void print()const;
	std::ofstream& write(const char* fileName);
	~Vector();

};

//friendly func
//template<typename T>

template<typename T>
std::ofstream& Vector<T>::write(const char* fileName)
{
	std::ofstream stream(fileName);
	for (size_t i = 0; i < this->size; i++)
	{
		stream << this->arr[i] << " ";
	}
	return stream;
}

//private methods

template<typename T>
void Vector<T>::copy(const Vector<T>& other)
{
	this->arr = new T[other.capacity];
	for (size_t i = 0; i < other.size; i++)
	{
		this->arr[i] = other.arr[i];
	}
	this->capacity = other.capacity;
	this->size = other.size;
}

template<typename T>
void Vector<T>::erase()
{
	delete[] this->arr;
}

template<typename T>
void Vector<T>::resize()
{
	T* temp = new T[this->capacity * 2 + 1];
	for (size_t i = 0; i < this->size; i++)
	{
		temp[i] = this->arr[i];
	}
	this->erase();
	this->capacity = this->capacity * 2 + 1;
	this->arr = temp;
}

//public methods

template<typename T>
Vector<T>::Vector()
{	
	this->capacity = 4;
	this->arr = new T[this->capacity];
	this->size = 0;
}
template<typename T>
Vector<T>::Vector(size_t capacity)
{
	this->capacity = capacity;
	this->arr = new T[this->capacity];
	this->size = this->capacity;
}

template<typename T>
Vector<T>::Vector(const Vector& other)
{
	this->copy(other);
}
template<typename T>
Vector<T>::Vector(const T* arr,  int size,  int capacity)
{
	this->size = size;
	this->capacity = capacity;
	this->arr = new T[capacity];
	for (size_t i = 0; i < this->size; i++)
	{
		this->arr[i] = arr[i];
	}
}

template<typename T>
Vector<T>& Vector<T>::operator=(const Vector<T>& other)
{
	if (this != &other)
	{
		this->erase();
		this->copy(other);
	}
	return *this;
}

template<typename T>
void Vector<T>::addElem(const T element)
{
	if (this->size >= this->capacity)resize();
	this->arr[size++] = element;;
}

template<typename T>
void Vector<T> :: remove()
{
	this->size--;
}

template<typename T>
T& Vector<T>:: getAt(const int index)const
{
	assert(index >= 0 && index < size);
	return this->arr[index];
}

template<typename T>
void Vector<T>::setAt(const int index, const T element)
{
	assert(index >= 0 && index < size);
		this->arr[index] = element;
	//return this->arr[index];
}

template<typename T>
T& Vector<T>:: operator[](const int index)const
{
	assert(index >= 0 && index < size);
	return this->getAt(index);
}

template<typename T> 
void Vector<T>::print()const
{
	std::cout << "[";
	for (int i = 0; i < this->size; i++)
	{
		std::cout << this->arr[i] << " ";
	}
	std::cout << "]" << std::endl;
}

template<typename T>
Vector<T>::~Vector()
{
	this->erase();
}
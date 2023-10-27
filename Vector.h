#pragma once
#include <iostream>

template<class T>
class Vector
{
	template<class T> friend std::istream& operator>>(std::istream& in, Vector<T>& V);
	template<class T> friend std::ostream& operator<<(std::ostream& out, const Vector<T>& V);
private:
	T* arr;
	int length;
public:
	Vector() : arr(nullptr), length(0) {};
	~Vector();
	Vector(int n);
	Vector(T* ptr, int n);
	Vector(const Vector<T>& other);
	
	Vector<T>& operator=(const Vector<T>& other);
	T& operator[](int n) const;
	Vector<T> operator+(const Vector<T>& other) const;
	Vector<T> operator*(const Vector<T>& other) const;
};

template<class T>
inline Vector<T>::~Vector()
{
	delete[] arr;
}

template<class T>
inline Vector<T>::Vector(int n)
{
	arr = new T[n];
	length = n;
}

template<class T>
inline Vector<T>::Vector(T* ptr, int n) : length(n), arr(new T[length])
{
	for (int i = 0; i < n; i++) arr[i] = ptr[i];
}

template<class T>
inline Vector<T>::Vector(const Vector<T>& other) : length(other.length), arr(new T[other.length])
{
	for (int i = 0; i < length; i++) arr[i] = other[i];
}

template<class T>
inline Vector<T>& Vector<T>::operator=(const Vector<T>& other)
{
	length = other.length;
	arr = new T[length];
	for (int i = 0; i < length; i++) arr[i] = other.arr[i];
	return *this;
}

template<class T>
inline T& Vector<T>::operator[](int idx) const
{
	return arr[idx];
}

template<class T>
inline Vector<T> Vector<T>::operator+(const Vector<T>& other) const
{
	int n = length > other.length ? length : other.length;
	Vector<T> res(n);
	if (n > other.length) {
		for (int i = 0; i < n; i++) {
			if (i >= other.length) {
				res[i] = arr[i];
			}
			else {
				res[i] = arr[i] + other.arr[i];
			}
		}
	}
	else {
		for (int i = 0; i < n; i++) {
			if (i >= length) {
				res[i] = other.arr[i];
			}
			else {
				res[i] = arr[i] + other.arr[i];
			}
		}
	}
	return res;
}

template<class T>
inline Vector<T> Vector<T>::operator*(const Vector<T>& other) const
{
	int n = length > other.length ? length : other.length;
	Vector<T> res(n);
	if (n > other.length) {
		for (int i = 0; i < n; i++) {
			if (i >= other.length) {
				res[i] = 0;
			}
			else {
				res[i] = arr[i] * other.arr[i];
			}
		}
	}
	else {
		for (int i = 0; i < n; i++) {
			if (i >= length) {
				res[i] = 0;
			}
			else {
				res[i] = arr[i] * other.arr[i];
			}
		}
	}
	return res;
}

template<class T>
inline std::istream& operator>>(std::istream& in, Vector<T>& V)
{
	for (int i = 0; i < V.length; i++) in >> V[i];
	return in;
}

template<class T>
inline std::ostream& operator<<(std::ostream& out, const Vector<T>& V)
{
	for (int i = 0; i < V.length; i++) out << V[i] << ' ';
	return out;
}
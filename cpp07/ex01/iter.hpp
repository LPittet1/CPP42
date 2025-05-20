#include <iostream>

template <typename T>
void iter(T* array, int len, void (*f)(T&))
{
	for (int i = 0; i < len; i++)
	{
		f(array[i]);
	}
}


template <typename T>
void iter(const T* array, int len, void (*f)(const T&))
{
	for (int i = 0; i < len; i++)
	{
		f(array[i]);
	}
}

template <typename T>
void doub(T& val)
{
	val += val;
}

template <typename T>
void print(const T& val)
{
	std::cout << val << std::endl;
}
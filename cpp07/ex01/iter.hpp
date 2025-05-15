template <typename T>
void iter(T* array, int len, T (*f)(T))
{
	for (int i = 0; i < len; i++)
	{
		array[i] = f(array[i]);
	}
}

template <typename T>
T doub(T val)
{
	return val + val;
}


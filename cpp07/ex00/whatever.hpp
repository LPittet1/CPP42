template <typename T>
void swap(T& a1, T& a2)
{
	T temp;
	temp = a1;
	a1 = a2;
	a2 = temp;
}

template <typename T>
T min(const T& t1, const T& t2)
{
	return t1 < t2 ? t1 : t2;
}

template <typename T>
T max(const T& t1, const T& t2)
{
	return t1 > t2 ? t1 : t2;
}
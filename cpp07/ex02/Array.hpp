#include <stdexcept>

template <class T>
class Array
{
private:
	T* content;
	unsigned int si;
public:
	Array(): content(0), si(0){};
	Array(unsigned int size): content(new T[size]), si(size) {};
	Array(const Array& cpy): si(cpy.si)
	{
		if (cpy.si > 0)
		{
			content = new T[cpy.si];
			for (unsigned int i = 0; i < si; i++)
			{
				content[i] = cpy.content[i];
			}
		}
	};

	Array& operator=(const Array& rhs)
	{
		if (this != &rhs)
		{
			si = rhs.si;
			if (content)
			{
				delete[] content;
			}
			content = new T[si];
			for (unsigned int i = 0; i < si; i++)
			{
				content[i] = rhs.content[i];
			}
		}
		return *this;
	};

	T& operator[](int pos)
	{
		if (pos < 0 || (unsigned int)pos >= si)
			throw std::out_of_range("Index out of range");
		return content[pos];
	};

	~Array()
	{
		if (content)
			delete[] content;
	};

	unsigned int size() const
	{
		return si;
	};
};




#ifndef SPAN_HPP
# define SPAN_HPP

# include <string>
# include <vector>

class Span
{
	private:
		unsigned int N;
		std::vector<int> cont;
	public:
		Span();
		Span(unsigned int N);
		Span(const Span& cpy);
		Span& operator=(const Span& rhs);
		~Span();
		int shortestSpan(void) const;
		int longestSpan(void) const;
		void addNumber(int val);
		unsigned int getN(void) const;
		std::vector<int> getCont(void) const;
		template <typename T>
		void addNumber(T begin,T end)
		{
			for (T it = begin; it != end; it++)
				addNumber(*it);
		}
};

std::ostream& operator<<(std::ostream& os, const Span& span);
#endif 
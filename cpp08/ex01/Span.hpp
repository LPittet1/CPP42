
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
		template <typename T>
		void addNumber(T vals)
		{
			for (typename T::iterator it = vals.begin(); it != vals.end(); it++)
				addNumber(*it);
		}
};

std::ostream& operator<<(std::ostream& os, const Span& span);
#endif 
#include <stack>
#include "RPN.hpp"

bool isOp(const std::string& str)
{
	return str == "+" || str == "-" || str == "*" || str == "/";
}

int doOp(int a, int b, std::string& op)
{
	if (op == "+")
		return a + b;
	if (op == "-")
		return a - b;
	if (op == "*")
		return a * b;
	if (op == "/")
		return a / b;
	return 0;
}

void RPN(std::stringstream& input)
{
	std::stack<int> st;
	std::string buf("init");
	int num1, num2;
	while (!input.eof())
	{
		input >> buf;
		if (buf.size() > 1)
		{
			std::cout << "Error: no space between 2 characters." << std::endl;
			return;
		}
		if (!std::isdigit(buf[0]) && !isOp(buf))
		{
			std::cout << "Error: invalid character." << std::endl;
			return;
		}
		if (std::isdigit(buf[0]))
			st.push(buf[0] - '0');
		if (isOp(buf))
		{
			if (st.size() < 2)
			{
				std::cout << "Error: Operation with less than 2 numbers." << std::endl;
				return;
			}
			num2 = st.top();
			st.pop();
			num1 = st.top();
			st.pop();
			if (num2 == 0 && buf == "/")
			{
				std::cout << "Error: cannot divide by 0.";
				return;
			}
			st.push(doOp(num1, num2, buf));
		}
	}
	if (st.size() == 1)
		std::cout << st.top() << std::endl;
	else
		std::cout << "Error: not enough operations." << std::endl;
}

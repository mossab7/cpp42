#include "RPN.hpp"

int evaluate(std::string &exp)
{
	std::stack<int> s;

	for (std::string::iterator it = exp.begin(); it != exp.end(); ++it)
	{
		if (std::isspace(*it))
			continue;

		if (std::isdigit(*it))
		{
			s.push(*it - '0');
		}
		else
		{
			if (s.size() < 2)
				throw (std::invalid_argument("Invalid expression: not enough operands"));
			int left = s.top();
			s.pop();
			int right = s.top();
			s.pop();

			switch (*it)
			{
			case '*':
				right *= left;
				break;
			case '-':
				right -= left;
				break;
			case '+':
				right += left;
				break;
			case '/':
				if (left == 0)
				{
					throw (std::invalid_argument("can't divide by 0"));
				}
				right /= left;
				break;
			default:
				throw (std::invalid_argument("Invalid operator"));
			}
			s.push(right);
		}
	}

	if (s.size() != 1)
	{
		throw (std::invalid_argument("Invalid expression\n"));
	}

	return s.top();
}

int main(int argc, char *argv[])
{
	if(argc != 2)
	{
		std::cerr << "ivalid arguments" << std::endl;
		return (0);
	}
	std::string exp = argv[1];
	if (exp.empty())
	{
		std::cerr << "Empty expression" << std::endl;
		return (0);
	}
	try {
		std::cout << evaluate(exp) << std::endl;
	}
	catch(std::exception &err)
	{
		std::cerr << err.what() << std::endl;
	}
}

#include <iostream>

void to_upper(std::string &str)
{
	for (std::string::size_type i = 0; i < str.size(); i++)
	{
		str[i] = toupper((str[i]));
	}
}

int main(int argc, char *argv[])
{
	if(argc == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return (0);
	}

	std::string temp;
	for (int i = 1; i < argc; i++)
	{
		temp = argv[i];
		to_upper(temp);
		std::cout << temp;
		if (i != argc - 1)
			std::cout << " ";
	}
	std::cout << std::endl;
}

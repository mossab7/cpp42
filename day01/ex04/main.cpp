#include <iostream>
#include <fstream>
#include <string>

std::string ManualReplace(std::string line, const std::string &target, const std::string &replacement)
{
	size_t pos = 0;
	while ((pos = line.find(target, pos)) != std::string::npos)
	{
		line = line.substr(0, pos) + replacement + line.substr(pos + target.size());
		pos += replacement.size();
	}
	return (line);
}

int main(int argc, char *argv[])
{
	if (argc != 4)
		return (1);

	const std::string filename = argv[1];
	const std::string target = argv[2];
	const std::string replacement = argv[3];
	std::string line;

	std::ifstream filein(filename.c_str());
	if (!filein.is_open())
	{
		std::cerr << "Unable to open input file\n";
		return (1);
	}

	std::ofstream fileout((filename + ".replace").c_str());
	if (!fileout.is_open())
	{
		std::cerr << "Unable to open output file\n";
		return (1);
	}

	while (std::getline(filein, line))
	{
		fileout << ManualReplace(line, target, replacement) << "\n";
	}

	return (0);
}

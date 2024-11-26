
#include <iostream>
#include <fstream>
#include <sstream>

int main(int argc, char **argv) {
	if (argc != 4)
	{
		std::cout << "Wrong number of arguments (<file> <to_replace> <to_replace_with>)\n";
		return (1);
	}

	std::string   file_name(argv[1]);
	std::string   from(argv[2]);
	std::string   to(argv[3]);
	std::ifstream infile;
	std::ofstream outfile;

	if (from.length() < 1)
	{
		std::cout << "Invalid second argument\n";
		return (1);
	}

	infile.open(file_name);
	if (!infile.is_open())
	{
		std::cout << "Couldn't open \'" << file_name << "\'\n";
		return (1);
	}
	
	outfile.open(file_name + ".replace");
	if (!outfile.is_open())
	{
		std::cout << "Couldn't open \'" << file_name << ".replace\'\n";
		return (1);
	}
	std::ostringstream ss;
	ss << infile.rdbuf();
	std::string content = ss.str();

	int index = 0;
	int new_index = 0;

	while (true) {
		new_index = content.find(from, index);
		if (new_index == -1)
			break ;
		outfile << content.substr(index, (new_index - index));
		outfile << to;
		index = new_index + from.size();
	}
	outfile << content.substr(index, (content.size() - index));
	return (0);
}
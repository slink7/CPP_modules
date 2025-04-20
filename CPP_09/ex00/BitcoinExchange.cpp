#include "BitcoinExchange.hpp"

std::string strTrim(const std::string &str, const std::string &set) {

	std::size_t begin = str.find_first_not_of(set);
	if (begin == std::string::npos)
		return (std::string(""));

	std::size_t end = str.find_last_not_of(set);
	if (end == std::string::npos)
		return (std::string(""));

	return (str.substr(begin, end - begin + 1));
}

void readFileContent(std::string& out, const std::ifstream& file) {
	std::stringstream ss;
	ss << file.rdbuf();
	out = ss.str();
}

int		isDash(int c) {
	return (c == '-');
}

bool	isDate(const std::string& str, std::size_t pos = 0) {
	int	(*array[])(int) = {
		isdigit, isdigit, isdigit, isdigit,
		isDash,
		isdigit, isdigit,
		isDash,
		isdigit, isdigit,
		0
	};

	for (int k = 0; array[k]; k++)
		if (!array[k](str[pos + k]))
			return (false);
	return (true);
}

bool loadDatabase(Database &out, const std::string &path) {
	std::ifstream file(path.c_str());
	if (!file.is_open())
		throw (std::invalid_argument("Path \"" + path + "\" couldn't be openned."));

	out.clear();

	std::string file_content;
	readFileContent(file_content, file);

	std::size_t line_start = 0ul;
	std::size_t comma = 0ul;
	std::size_t line_end = 0ul;

	line_start = file_content.find('\n', 0) + 1;
	comma = file_content.find(',', line_start);
	line_end = file_content.find('\n', line_start);
	do {
		std::string key = strTrim(file_content.substr(line_start, comma - line_start), " \t\n");
		if (!isDate(key))
			throw (std::invalid_argument("Key \"" + key + "\" is not a date\n"));
		float		value = ::atof(file_content.substr(comma + 1, line_end - (comma + 1)).c_str());
		out[key] = value;

		line_start = line_end + 1;
		comma = file_content.find(',', line_start);
		line_end = file_content.find('\n', line_start);
	} while (line_end != std::string::npos);
	
	file.close();
	return (true);
}
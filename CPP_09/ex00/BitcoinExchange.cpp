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

bool	isDateValid(int day, int month, int year) {
	int	maxDayByMonth[] = {
		31, 28 + (year % 4 == 0), 31, 30, 31, 30, 31, 31, 30, 31, 30, 31
	};
	return (month > 0 && month < 13 && day > 0 && day <= maxDayByMonth[month - 1]);
}

bool	isDateValid(const std::string& date) {
	int day = ::atoi(date.substr(date.find_last_of('-') + 1).c_str());
	int month = ::atoi(date.substr(date.find_first_of('-') + 1).c_str());
	int year = ::atoi(date.c_str());

	return (isDateValid(day, month, year));
}

bool	isValue(const std::string& str, std::size_t pos = 0) {
	return (
		str.find_first_not_of("0123456789.", pos) == std::string::npos &&
		str.find_first_of(".", pos) == str.find_last_of(".")
	);
}

void getValues(std::string& key, float& value, const std::string& file_content, std::size_t line_start, std::size_t sep, std::size_t line_end) {
	if (sep < line_start || sep > line_end || line_end < line_start)
		throw (std::invalid_argument("\e[1;31mWeird line formation \"" + file_content.substr(line_start, line_end - line_start) + "\""));
	key = strTrim(file_content.substr(line_start, sep - line_start), " \t\n");
	if (!isDate(key))
		throw (std::invalid_argument("\e[1;31mKey \"" + key + "\" is not a date"));
	if (!isDateValid(key))
		throw (std::invalid_argument("\e[1;31mDate \"" + key + "\" is not valid"));
	std::string valuestr = strTrim(file_content.substr(sep + 1, line_end - (sep + 1)), " \t\n");
	if (!isValue(valuestr))
		throw (std::invalid_argument("\e[1;31mValue \"" + valuestr + "\" is not a valid number"));
	value = ::atof(valuestr.c_str());
}

bool parseFile(Database &db, const std::string &path, void (*toDo)(Database&, std::string&, float&)) {
	std::ifstream file(path.c_str());
	if (!file.is_open())
		throw (std::invalid_argument("\e[1;31mPath \"" + path + "\" couldn't be openned."));

	std::string file_content;
	readFileContent(file_content, file);

	std::size_t line_start = 0ul;
	std::size_t sep = 0ul;
	std::size_t line_end = 0ul;

	std::string	key;
	float		value;

	line_start = file_content.find('\n', 0) + 1;
	sep = file_content.find_first_of(",|", line_start);
	line_end = file_content.find('\n', line_start);
	int k = 2;
	do {
		try {
			getValues(key, value, file_content, line_start, sep, line_end);
			toDo(db, key, value);
		} catch (std::exception& e) {
			std::cout << "\e[0;31mCaught an exception while parsing file (" << path << ":" << k << "): " << e.what() << "\n";
		}
		++k;
		line_start = line_end + 1;
		sep = file_content.find_first_of(",|", line_start);
		line_end = file_content.find('\n', line_start);
	} while (line_end != std::string::npos);
	
	try {
		getValues(key, value, file_content, line_start, sep, line_end);
		toDo(db, key, value);
	} catch (std::exception& e) {
		std::cout << "\e[0;31mCaught an exception while parsing file: " << e.what() << "\n";
	}

	file.close();
	return (true);
}

float lookupInDatabase(const Database &db, const std::string &date) {
	for (Database::const_reverse_iterator it = db.rbegin(); it != db.rend(); ++it) {
		if (it->first.compare(date) <= 0) {
			return (it->second);
		}
	}
	throw (std::invalid_argument("\e[1;31mNo entry could be found!"));
}

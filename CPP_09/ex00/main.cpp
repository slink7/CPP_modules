#include <iostream>

#include "BitcoinExchange.hpp"

void	saveToDatabase(Database &db, std::string &key, float &value) {
	db[key] = value;
}

void	printValue(Database &db, std::string &key, float &value) {
	if (value > 1000)
		throw (std::invalid_argument("\e[1;31mValue bigger than 1000"));
	std::cout << "\e[0;36m" << key << " => " << value << " = " << value * lookupInDatabase(db, key) << "\n";
}

int main(int argc, char **argv) {

	if (argc != 2) {
		std::cout << "Wrong argument count !\n";
		return (1);
	}

	(void) argv;

	std::string	file_path = "data.csv";
	Database	history;
	Database	data;

	try {
		std::cout << "\e[1;34mReading source...\n";
		parseFile(history, file_path, saveToDatabase);
		std::cout << "\e[1;34mOutput: \n";
		parseFile(history, argv[1], printValue);
		// parseFile(history, "This file doesn't exist", printValue);
	} catch (std::exception& e) {
		std::cout << "\e[0;31mCaught an Exception: " << e.what() << "\e[0m\n";		
	}
	return (0);
}
#include <iostream>

#include "BitcoinExchange.hpp"

void	saveToDatabase(Database &db, std::string &key, float &value) {
	db[key] = value;
}

void	printValue(Database &db, std::string &key, float &value) {
	if (value > 1000)
		throw (std::invalid_argument("Value bigger than 1000"));
	std::cout << key << " => " << value << " = " << value * lookupInDatabase(db, key) << "\n";
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
		parseFile(history, file_path, saveToDatabase);
		parseFile(history, argv[1], printValue);
		// parseFile(history, "This file doesn't exist", printValue);
	} catch (std::exception& e) {
		std::cout << "Caught an Exception: " << e.what() << "\n";		
	}
	return (0);
}
#include <iostream>

#include "BitcoinExchange.hpp"

int main() {
	std::string	file_path = "data.csv";
	Database	db;

	try {
		loadDatabase(db, file_path);
		

		
		Database::iterator it = db.begin();
		for (int k = 0; k < 10; k++) {
			std::cout << it->first << ": " << it->second << "\n";
			++it;
		}
	} catch (std::exception& e) {
		std::cout << "Caught an Exception: " << e.what() << "\n";		
	}
}
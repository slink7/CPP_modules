#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <string>
#include <fstream>
#include <sstream>
#include <map>
#include <stdexcept>
#include <iostream>

#include <cstdlib>

typedef std::map<std::string, float> Database;

bool	loadDatabase(Database& out, const std::string& path);
bool	lookupInDatabase(const Database& db, const std::string& date);

#endif
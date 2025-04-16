#include "Data.hpp"

std::ostream &operator<<(std::ostream &os, const Data &data) {
	return (os << "Data: " << data.integer << ", " << data.floating << ", " << data.character << "\n");
}
#include "Harl.hpp"

struct MapElement {
	std::string	key;
	void		(Harl::*value)(void) const;
};

void Harl::complain(const std::string& level) const {
	static MapElement map[] = {
		(MapElement) {"DEBUG", &Harl::debug},
		(MapElement) {"INFO", &Harl::info},
		(MapElement) {"WARNING", &Harl::warning},
		(MapElement) {"ERROR", &Harl::error}
	};

	for (MapElement& e : map) {
		if (!e.key.compare(level)) {
			(this->*e.value)();
			return ;
		}
	}
	std::cout << "\"" << level << "\" is nonsense ! Stop inventing levels !\n";
}

void Harl::debug(void) const {
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do !\n";
}

void Harl::info(void) const {
	std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger ! If you did, I wouldn’t be asking for more !\n";
}

void Harl::warning(void) const {
	std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month.\n";
}

void Harl::error(void) const {
	std::cout << "This is unacceptable ! I want to speak to the manager now.\n";
}

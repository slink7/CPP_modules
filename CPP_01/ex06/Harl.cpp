
#include "Harl.hpp"

void Harl::complain(const std::string& level) const {
	std::string	levels[] = {
		"DEBUG", "INFO", "WARNING", "ERROR"
	};

	int k;
	for (k = 0; k < 4; k++)
		if (!levels[k].compare(level))
			break ;
	
	switch (k)
	{
	case 0:
		this->debug();
		// fall through
	case 1:
		this->info();
		// fall through
	case 2:
		this->warning();
		// fall through
	case 3:
		this->error();
		// fall through
		break;
		
	default:
		std::cout << "[ Probably complaining about insignificant problems ]\n";
		break;
	}
}

void Harl::debug(void) const {
	std::cout << "[DEBUG] I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do !\n";
}

void Harl::info(void) const {
	std::cout << "[INFO] I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger ! If you did, I wouldn’t be asking for more !\n";
}

void Harl::warning(void) const {
	std::cout << "[WARNING] I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month.\n";
}

void Harl::error(void) const {
	std::cout << "[ERROR] This is unacceptable ! I want to speak to the manager now.\n";
}

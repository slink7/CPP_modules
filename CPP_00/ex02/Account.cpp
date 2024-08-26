#include <iostream>

#include "Account.hpp"

std::string get_date()
{
	return ("");
}

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

int	Account::getNbAccounts( void ) {
	return (_nbAccounts);
}

int	Account::getTotalAmount( void ) {
	return (_totalAmount);
}

int	Account::getNbDeposits( void ) {
	return (_totalNbDeposits);
}

int	Account::getNbWithdrawals( void ) {
	return (_totalNbWithdrawals);
}

void	Account::displayAccountsInfos( void ) {
	std::cout << "[" << get_date() << "] accounts:" << _nbAccounts << ";total:" << _totalAmount << ";deposits:" << _totalNbDeposits << ";withdrawals:" << _totalNbWithdrawals << "\n";
}

Account::Account( int initial_deposit ) {
	_accountIndex = _nbAccounts++;
	_amount = initial_deposit;
	_totalAmount += initial_deposit;
	std::cout << "[" << get_date() << "] index:" << _accountIndex << ";amount:" << _amount << ";created\n";
}
Account::~Account( void ) {
	std::cout << "[" << get_date() << "] index:" << _accountIndex << ";amount:" << _amount << ";closed\n";
}

void	Account::makeDeposit( int deposit ) {
	_totalAmount += deposit;
	_amount += deposit;
	_totalNbDeposits++;
	_nbDeposits++;
	std::cout << "[" << get_date() << "] index:" << _accountIndex << ";p_amount:" << _amount - deposit << ";deposit:" << deposit << ";amount:" << _amount << ";nb_deposits:" << _nbDeposits << "\n";
}

bool	Account::makeWithdrawal( int withdrawal ) {
	if (withdrawal > _amount) {
		std::cout << "[" << get_date() << "] index:" << _accountIndex << ";p_amount:" << _amount << ";withdrawal:refused\n";
		return (false);
	}
	_totalAmount -= withdrawal;
	_amount -= withdrawal;
	_totalNbWithdrawals++;
	_nbWithdrawals++;
	std::cout << "[" << get_date() << "] index:" << _accountIndex << ";p_amount:" << _amount + withdrawal << ";withdrawal:" << withdrawal << ";amount:" << _amount << ";nb_withdrawals:" << _nbWithdrawals << "\n";
	return (true);
}

int		Account::checkAmount( void ) const {
	return (_amount);
}

void	Account::displayStatus( void ) const {
	std::cout << "[" << get_date() << "] index:" << _accountIndex << ";amount:" << _amount << ";deposits:" << _nbDeposits << ";withdrawals:" << _nbWithdrawals << "\n";
}
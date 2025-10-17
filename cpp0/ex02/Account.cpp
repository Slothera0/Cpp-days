/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arvoyer <arvoyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 10:00:14 by arvoyer           #+#    #+#             */
/*   Updated: 2024/10/14 16:41:18 by arvoyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <ctime>
#include <iostream>

int	Account::_nbAccounts;
int	Account::_totalAmount;
int	Account::_totalNbDeposits;
int	Account::_totalNbWithdrawals;

Account::Account(void)
{
	this->_accountIndex = _nbAccounts;
	_nbAccounts++;

	this->_amount = 0;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex \
		<< ";amount:" << this->checkAmount() << ";created" << std::endl;
}

Account::Account(int initial_deposit)
{
	this->_accountIndex = _nbAccounts;
	_nbAccounts++;

	this->_amount = initial_deposit;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;
	_totalAmount += initial_deposit;
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex \
		<< ";amount:" << this->checkAmount() << ";created" << std::endl;
}

Account::~Account(void)
{
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex \
		<< ";amount:" << this->checkAmount() << ";closed" << std::endl;
}

int	Account::getNbAccounts()
{
	return (_nbAccounts);
}

int	Account::getTotalAmount()
{
	return (_totalAmount);
}

int	Account::getNbDeposits()
{
	return (_totalNbDeposits);
}

int	Account::getNbWithdrawals()
{
	return (_totalNbWithdrawals);
}

void	Account::_displayTimestamp()
{
	time_t	current_time;
	tm		*ltm;

	current_time = time(NULL);
	ltm = localtime(&current_time);
	std::cout << "[" << ltm->tm_year + 1900 << ltm->tm_mon + 1 << ltm->tm_mday \
		<< "_" << ltm->tm_hour << ltm->tm_min << ltm->tm_sec << "] ";
}

void	Account::displayAccountsInfos(void)
{
	_displayTimestamp();
	std::cout << "accounts:" << getNbAccounts() << ";total:" << getTotalAmount() \
		<< ";deposits:" << getNbDeposits() << ";withdrawals:" << getNbWithdrawals() << std::endl;
}

int		Account::checkAmount(void) const
{
	return (this->_amount);
}

void	Account::displayStatus(void) const
{
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";amount:" << this->checkAmount() << \
		";deposits:" << this->_nbDeposits << ";withdrawals:" << this->_nbWithdrawals << std::endl;
}

void	Account::makeDeposit( int deposit )
{
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";p_amount:" << this->checkAmount() << ";deposit:" << deposit \
		<< ";amount:" << this->checkAmount() + deposit << ";nb_deposits:" << this->_nbDeposits + 1 << std::endl;
	this->_amount += deposit;
	this->_nbDeposits += 1;
	_totalNbDeposits += 1;
	_totalAmount += deposit;
}

bool	Account::makeWithdrawal(int withdrawal)
{
	_displayTimestamp();
	if (this->_amount - withdrawal < 0)
	{
		std::cout << "index:" << this->_accountIndex << ";p_amount:" \
			<< this->checkAmount() << ";withdrawal:refused" << std::endl;
		return (false);
	}
	std::cout << "index:" << this->_accountIndex << ";p_amount:" << this->checkAmount() << ";withdrawal:" << withdrawal \
		<< ";amount:" << this->checkAmount() - withdrawal << ";nb_withdrawals:" << this->_nbWithdrawals + 1 << std::endl;
	this->_amount -= withdrawal;
	this->_nbWithdrawals += 1;
	_totalNbWithdrawals += 1;
	_totalAmount -= withdrawal;
	return (true);
}

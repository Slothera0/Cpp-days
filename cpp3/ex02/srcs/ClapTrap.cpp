/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arvoyer <arvoyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 15:58:17 by arvoyer           #+#    #+#             */
/*   Updated: 2024/11/27 05:07:19 by arvoyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.h"
#include <iostream>

ClapTrap::ClapTrap(void)
{
	_name = "\0";
	_Hit_points = 100;
	_Energy_points = 100;
	_Attack_damage = 30;

	std::cout << "A new ClapTrap has been created" << std::endl;
}

ClapTrap::ClapTrap(std::string name)
{
	_name = name;
	_Hit_points = 100;
	_Energy_points = 100;
	_Attack_damage = 30;

	std::cout << "The new ClapTrap " << name << " has been created" << std::endl;
}

ClapTrap::ClapTrap(ClapTrap &copy)
{
	this->_name = copy._name;
	this->_Hit_points = copy._Hit_points;
	this->_Energy_points = copy._Energy_points;
	this->_Attack_damage = copy._Attack_damage;
}

ClapTrap& ClapTrap::operator=(const ClapTrap &other)
{
	this->_name = other._name;
	this->_Hit_points = other._Hit_points;
	this->_Energy_points = other._Energy_points;
	this->_Attack_damage = other._Attack_damage;
	return (*this);
}

ClapTrap::~ClapTrap(void)
{
	if (_name != "\0")
		std::cout << "The ClapTrap " << _name << " has been destroyed"  << std::endl;
	else
		std::cout << "A ClapTrap has been destroyed" << std::endl;
}

//---------------------------------------------------------------------------------------------------//


void ClapTrap::attack(const std::string& target)
{
	if (_Hit_points <= 0)
		std::cout << "ClapTrap " << _name << " is too damaged to do anything" << std::endl;
	else if (_Energy_points <= 0)
		std::cout << "ClapTrap " << _name << " is too tired to do anything" << std::endl;
	else
	{
		std::cout << "ClapTrap " << _name << " attacks " << target << ", causing " << _Attack_damage << " points of damage!" << std::endl;
		_Energy_points--;
	}
}

void ClapTrap::takeDamage(unsigned int amount)
{
	std::cout << "ClapTrap " << _name << " is attacked and lose " << amount << " Hit points" << std::endl;
	_Hit_points -= amount;
	if (_Hit_points < 0)
		_Hit_points = 0;
	std::cout << "New Hit points : " << _Hit_points << std::endl;
	if (_Hit_points == 0)
		std::cout << "ClapTrap " << _name << " is dead" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (_Hit_points <= 0)
		std::cout << "ClapTrap " << _name << " is too damaged to do anything" << std::endl;
	else if (_Energy_points <= 0)
		std::cout << "ClapTrap " << _name << " is too tired to do anything" << std::endl;
	else
	{
		std::cout << "ClapTrap " << _name << " has recovered " << amount << " Hit points" << std::endl;
		_Hit_points += amount;
		std::cout << "New Hit points : " << _Hit_points << std::endl;
		_Energy_points--;
	}
}

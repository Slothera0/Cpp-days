/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arvoyer <arvoyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 04:38:37 by arvoyer           #+#    #+#             */
/*   Updated: 2024/11/27 04:57:16 by arvoyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.h"
#include <iostream>

ScavTrap::ScavTrap(void) : ClapTrap()
{
	std::cout << "A new ScavTrap has been created" << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	std::cout << "The new ScavTrap " << name << " has been created" << std::endl;
}

ScavTrap::ScavTrap(ScavTrap &copy) : ClapTrap(copy)
{
	
}

ScavTrap& ScavTrap::operator=(const ScavTrap &other)
{
	ClapTrap::operator=(other);
	return (*this);
}

ScavTrap::~ScavTrap(void)
{
	if (_name != "\0")
		std::cout << "The ScavTrap " << _name << " has been destroyed"  << std::endl;
	else
		std::cout << "A ScavTrap has been destroyed" << std::endl;
}

void ScavTrap::attack(const std::string& target)
{
	if (_Hit_points <= 0)
		std::cout << "ScavTrap " << _name << " is too damaged to do anything" << std::endl;
	else if (_Energy_points <= 0)
		std::cout << "ScavTrap " << _name << " is too tired to do anything" << std::endl;
	else
	{
		std::cout << "ScavTrap " << _name << " attacks " << target << ", causing " << _Attack_damage << " points of damage!" << std::endl;
		_Energy_points--;
	}
}

void ScavTrap::guardGate(void)
{
	std::cout << "ScavTrap " << _name << " is now in Gate keeper mode" << std::endl;
}
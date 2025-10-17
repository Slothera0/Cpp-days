/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arvoyer <arvoyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 04:38:37 by arvoyer           #+#    #+#             */
/*   Updated: 2024/11/27 05:06:56 by arvoyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.h"
#include <iostream>

FragTrap::FragTrap(void) : ClapTrap()
{
	std::cout << "A new FragTrap has been created" << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	std::cout << "The new FragTrap " << name << " has been created" << std::endl;
}

FragTrap::FragTrap(FragTrap &copy) : ClapTrap(copy)
{
	
}

FragTrap& FragTrap::operator=(const FragTrap &other)
{
	ClapTrap::operator=(other);
	return (*this);
}

FragTrap::~FragTrap(void)
{
	if (_name != "\0")
		std::cout << "The FragTrap " << _name << " has been destroyed"  << std::endl;
	else
		std::cout << "A FragTrap has been destroyed" << std::endl;
}

void FragTrap::attack(const std::string& target)
{
	if (_Hit_points <= 0)
		std::cout << "FragTrap " << _name << " is too damaged to do anything" << std::endl;
	else if (_Energy_points <= 0)
		std::cout << "FragTrap " << _name << " is too tired to do anything" << std::endl;
	else
	{
		std::cout << "FragTrap " << _name << " attacks " << target << ", causing " << _Attack_damage << " points of damage!" << std::endl;
		_Energy_points--;
	}
}

void FragTrap::highFivesGuys(void)
{
	std::cout << "High Five !!" << std::endl;
}

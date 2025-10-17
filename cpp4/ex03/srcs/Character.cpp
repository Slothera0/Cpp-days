/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arvoyer <arvoyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 11:13:37 by arvoyer           #+#    #+#             */
/*   Updated: 2024/12/10 14:37:21 by arvoyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.h"
#include <iostream>

Character::Character(void)
{
	_name = "Unknow";
	for (int i = 0; i < 4; i++)
		_inventory[i] = NULL;
	
	std::cout << "An unknow character has been created" << std::endl;
}

Character::Character(std::string name)
{
	_name = name;
	for (int i = 0; i < 4; i++)
		_inventory[i] = NULL;
	
	std::cout << "The character " << name << " has been created" << std::endl;
}

Character::Character(Character &copy)
{
	for (int i = 0; i < 4; i++)
		this->_inventory[i] = NULL;
	
	*this = copy;
	
	std::cout << "The character " << this->_name << " has been created" << std::endl;
}

Character& Character::operator=(const Character &other)
{
	this->_name = other._name;

	for (int i = 0; i < 4; i++)
	{
		if (this->_inventory[i] != NULL)
		{
			delete(this->_inventory[i]);
			this->_inventory[i] = NULL;
		}
		if (other._inventory[i] != NULL)
			this->_inventory[i] = other._inventory[i]->clone();
	}
	
	return (*this);
}

Character::~Character(void)
{
	for (int i = 0; i < 4; i++)
	{
		if (_inventory[i] != NULL)
			delete(_inventory[i]);
	}

	std::cout << "The character " << this->_name << " has been destroyed" << std::endl;
}

std::string const & Character::getName() const
{
	return (_name);
}

AMateria	*Character::getMateria(int idx)
{
	if (idx >= 0 && idx <= 3)
		return (_inventory[idx]);
	return (NULL);
}

void Character::equip(AMateria* m)
{
	for (int i = 0; i < 4; i++)
	{
		if (_inventory[i] == NULL)
		{
			_inventory[i] = m;
			return ;
		}
	}
}

void Character::unequip(int idx)
{
	if (idx >= 0 && idx <= 3)
		_inventory[idx] = NULL;
}

void Character::use(int idx, ICharacter& target)
{
	if ((idx >= 0 && idx <= 3) && _inventory[idx] != NULL)
		_inventory[idx]->use(target);
}

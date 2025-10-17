/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arvoyer <arvoyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 11:36:17 by arvoyer           #+#    #+#             */
/*   Updated: 2024/12/10 13:43:09 by arvoyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.h"
#include <iostream>

MateriaSource::MateriaSource(void)
{
	for (int i = 0; i < 4; i++)
		_inventory[i] = NULL;
	
	std::cout << "New MateriaSource created" << std::endl;
}

MateriaSource::MateriaSource(MateriaSource &copy)
{
	for (int i = 0; i < 4; i++)
		this->_inventory[i] = NULL;
	
	*this = copy;
	
	std::cout << "New MateriaSource created" << std::endl;
}

MateriaSource& MateriaSource::operator=(const MateriaSource &other)
{
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

MateriaSource::~MateriaSource(void)
{
	for (int i = 0; i < 4; i++)
	{
		if (_inventory[i] != NULL)
			delete(_inventory[i]);
	}

	std::cout << "A MateriaSource has been destroyed" << std::endl;
}

void		MateriaSource::learnMateria(AMateria * m)
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

AMateria*	MateriaSource::createMateria(std::string const & type)
{
	for ( int i = 0; i < 4; i++)
	{
		if (_inventory[i]->getType() == type)
			return ((_inventory[i])->clone());
	}
	return (NULL);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arvoyer <arvoyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 12:47:53 by arvoyer           #+#    #+#             */
/*   Updated: 2024/12/10 13:42:26 by arvoyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.h"
#include <iostream>

AMateria::AMateria(void)
{
	std::cout << "New materia created" << std::endl;
}

AMateria::AMateria(std::string const & type) : _type(type)
{
	std::cout << "New materia " << type << " created" << std::endl;
}

AMateria::AMateria(const AMateria &copy)
{
	this->_type = copy._type;

	std::cout << "New materia " << this->_type << " created" << std::endl;
}

AMateria& AMateria::operator=(const AMateria &other)
{
	(void)other;
	return (*this);
}

AMateria::~AMateria(void)
{
	if (_type != "\0")
		std::cout << "The materia " << _type << " has been destroyed" << std::endl;
	else
		std::cout << "A unreferenced materia has been destroyed" << std::endl;
}

std::string const & AMateria::getType() const
{
	return (_type);
}

void AMateria::use(ICharacter& target)
{
	if (_type != "\0")
		std::cout << "* " << _type << " is use on " << target.getName() << " *" << std::endl;
	else
		std::cout << "* Something is throw at " << target.getName() << " *" << std::endl;
}
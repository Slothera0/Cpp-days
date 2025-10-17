/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arvoyer <arvoyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 23:18:55 by arvoyer           #+#    #+#             */
/*   Updated: 2024/12/02 06:50:27 by arvoyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.h"
#include <iostream>

WrongAnimal::WrongAnimal(void) : _type("\0")
{
	std::cout << "A new wrong animal is coming !" << std::endl;
}

WrongAnimal::WrongAnimal(std::string type) : _type(type)
{
	std::cout << "A new wrong animal \"" << type << "\" is coming !" << std::endl;
}

WrongAnimal::WrongAnimal(WrongAnimal &copy) : _type(copy._type)
{
	std::cout << "A new wrong animal \"" << this->_type << "\" is coming !" << std::endl;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal &other)
{
	this->_type = other._type;
	return (*this);
}

WrongAnimal::~WrongAnimal(void)
{
	if (_type == "\0")
		std::cout << "A wrong animal has disappeared !" << std::endl;
	else
		std::cout << "The wrong animal \"" << this->_type << "\" has disappeared !" << std::endl;
}

void	WrongAnimal::setType(std::string type)
{
	_type = type;
}

std::string	WrongAnimal::getType(void)
{
	return (_type);
}

void	WrongAnimal::makeSound(void) const
{
	if (_type == "\0")
		std::cout << "*You hear an unrecognizable sound*" << std::endl;
	else
		std::cout << "*You hear the howl of a " << this->_type << "*" << std::endl;
}

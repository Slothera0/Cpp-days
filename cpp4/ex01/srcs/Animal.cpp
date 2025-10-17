/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arvoyer <arvoyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 23:18:55 by arvoyer           #+#    #+#             */
/*   Updated: 2024/12/02 06:50:11 by arvoyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.h"
#include <iostream>

Animal::Animal(void) : _type("\0")
{
	std::cout << "A new animal is coming !" << std::endl;
}

Animal::Animal(std::string type) : _type(type)
{
	std::cout << "A new animal \"" << type << "\" is coming !" << std::endl;
}

Animal::Animal(Animal &copy) : _type(copy._type)
{
	std::cout << "A new animal \"" << this->_type << "\" is coming !" << std::endl;
}

Animal& Animal::operator=(const Animal &other)
{
	this->_type = other._type;
	return (*this);
}

Animal::~Animal(void)
{
	if (_type == "\0")
		std::cout << "An animal has disappeared !" << std::endl;
	else
		std::cout << "The animal \"" << this->_type << "\" has disappeared !" << std::endl;
}

void	Animal::setType(std::string type)
{
	_type = type;
}

std::string	Animal::getType(void) const
{
	return (_type);
}

void	Animal::makeSound(void) const
{
	if (_type == "\0")
		std::cout << "*You hear an unrecognizable sound*" << std::endl;
	else
		std::cout << "*You hear the howl of a " << this->_type << "*" << std::endl;
}

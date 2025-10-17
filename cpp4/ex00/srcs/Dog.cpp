/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arvoyer <arvoyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 06:27:29 by arvoyer           #+#    #+#             */
/*   Updated: 2024/12/02 07:03:06 by arvoyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "Animal.h"
#include "Dog.h"

Dog::Dog(void) : Animal("Dog")
{
	std::cout << "A new dog is coming !" << std::endl;
}

Dog::Dog(Dog &copy) : Animal(copy._type)
{
	std::cout << "A new dog is coming !" << std::endl;
}

Dog& Dog::operator=(const Dog &other)
{
	if (this != &other)
	{
		Animal::operator=(other);
	}
	return (*this);
}

Dog::~Dog(void)
{
	std::cout << "A dog has runaway !" << std::endl;
}

void	Dog::setType(std::string type)
{
	std::cout << "A dog is just a dog, he can't be a \"" << type << "\"" << std::endl;
}

void	Dog::makeSound(void) const
{
	std::cout << "Waouf !!" << std::endl;
}

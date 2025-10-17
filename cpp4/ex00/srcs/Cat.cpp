/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arvoyer <arvoyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 06:19:57 by arvoyer           #+#    #+#             */
/*   Updated: 2024/12/02 07:02:53 by arvoyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "Animal.h"
#include "Cat.h"

Cat::Cat(void) : Animal("Cat")
{
	std::cout << "A new cat is coming !" << std::endl;
}

Cat::Cat(Cat &copy) : Animal(copy._type)
{
	std::cout << "A new cat is coming !" << std::endl;
}

Cat& Cat::operator=(const Cat &other)
{
	if (this != &other)
	{
		Animal::operator=(other);
	}
	return (*this);
}

Cat::~Cat(void)
{
	std::cout << "A cat has runaway !" << std::endl;
}

void	Cat::setType(std::string type)
{
	std::cout << "A cat is just a cat, he can't be a \"" << type << "\"" << std::endl;
}

void	Cat::makeSound(void) const
{
	std::cout << "Miaou !!" << std::endl;
}

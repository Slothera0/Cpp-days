/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arvoyer <arvoyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 06:19:57 by arvoyer           #+#    #+#             */
/*   Updated: 2024/12/11 11:59:08 by arvoyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "Animal.h"
#include "Cat.h"

Cat::Cat(void) : Animal("Cat")
{
	_brain = new Brain();
	std::cout << "A new cat is coming !" << std::endl;
}

Cat::Cat(Cat &copy) : Animal(copy._type)
{
	_brain = new Brain(*(copy._brain));
	std::cout << "A new cat is coming !" << std::endl;
}

Cat& Cat::operator=(const Cat &other)
{
	if (this != &other)
	{
		*this->_brain = *other._brain;
		Animal::operator=(other);
	}
	return (*this);
}

Cat::~Cat(void)
{
	delete(_brain);
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

void	Cat::add_idea(std::string std)
{
	_brain->add_idea(std);
}

void	Cat::show_ideas(void)
{
	_brain->show_brain();
}

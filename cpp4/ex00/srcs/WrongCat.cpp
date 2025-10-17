/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arvoyer <arvoyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 06:19:57 by arvoyer           #+#    #+#             */
/*   Updated: 2024/12/02 07:05:24 by arvoyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "WrongAnimal.h"
#include "WrongCat.h"

WrongCat::WrongCat(void) : WrongAnimal("Cat")
{
	std::cout << "A new wrong cat is coming !" << std::endl;
}

WrongCat::WrongCat(WrongCat &copy) : WrongAnimal(copy._type)
{
	std::cout << "A new wrong cat is coming !" << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat &other)
{
	WrongAnimal::operator=(other);
	return (*this);
}

WrongCat::~WrongCat(void)
{
	std::cout << "A wrong cat has runaway !" << std::endl;
}

void	WrongCat::setType(std::string type) 
{
	std::cout << "A wrong cat is just a wrong cat, he can't be a \"" << type << "\"" << std::endl;
}

void	WrongCat::makeSound(void) const
{
	std::cout << "Miaou !!" << std::endl;
}

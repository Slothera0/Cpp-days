/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arvoyer <arvoyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 11:11:39 by arvoyer           #+#    #+#             */
/*   Updated: 2024/12/10 13:41:33 by arvoyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.h"
#include "AMateria.h"
#include <iostream>

Ice::Ice(void) : AMateria("ice")
{
	std::cout << "New ice object created" << std::endl;
}

Ice::Ice(const Ice &copy) : AMateria(copy)
{
	std::cout << "New ice object created" << std::endl;
}

Ice& Ice::operator=(const Ice &other)
{
	(void)other;
	return (*this);
}

Ice::~Ice(void)
{
	std::cout << "A ice object has been destroyed" << std::endl;
}

AMateria* Ice::clone() const
{
	AMateria *clone = new Ice(*this);
	return (clone);
}

void Ice::use(ICharacter& target)
{
	std::cout <<  "* shoots an ice bolt at " << target.getName() << " *"  << std::endl;
}
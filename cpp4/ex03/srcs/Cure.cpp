/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arvoyer <arvoyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 10:46:59 by arvoyer           #+#    #+#             */
/*   Updated: 2024/12/10 13:41:42 by arvoyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.h"
#include "AMateria.h"
#include <iostream>

Cure::Cure(void) : AMateria("cure")
{
	std::cout << "New cure object created" << std::endl;
}

Cure::Cure(const Cure &copy) : AMateria(copy)
{
	std::cout << "New cure object created" << std::endl;
}

Cure& Cure::operator=(const Cure &other)
{
	(void)other;
	return (*this);
}

Cure::~Cure(void)
{
	std::cout << "A cure object has been destroyed" << std::endl;
}

AMateria* Cure::clone() const
{
	AMateria *clone = new Cure(*this);
	return (clone);
}

void Cure::use(ICharacter& target)
{
	std::cout <<  "* heals " << target.getName() << "’s wounds *"  << std::endl;
}
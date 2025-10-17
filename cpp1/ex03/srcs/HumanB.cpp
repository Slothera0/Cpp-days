/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arvoyer <arvoyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 19:58:45 by arvoyer           #+#    #+#             */
/*   Updated: 2024/10/19 20:01:05 by arvoyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.h"
#include <iostream>

HumanB::HumanB(std::string name)
	: _name(name)
{
	_weapon = NULL;
}
	
void	HumanB::attack(void)
{
	if (_weapon)
		std::cout << _name << " attacks with their " << _weapon->getType() << std::endl;
	else
		std::cout << _name << " attacks with their hands" << std::endl;
}

void	HumanB::setWeapon(Weapon &weapon)
{
	_weapon = &weapon;
}
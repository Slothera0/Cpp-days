/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arvoyer <arvoyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 19:56:02 by arvoyer           #+#    #+#             */
/*   Updated: 2024/10/19 20:05:24 by arvoyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.h"
#include <iostream>

HumanA::HumanA(std::string name, Weapon &weapon)
	: _name(name), _weapon(weapon)
{
}
	
void	HumanA::attack(void)
{
	std::cout << _name << " attacks with their " << _weapon.getType() << std::endl;
}
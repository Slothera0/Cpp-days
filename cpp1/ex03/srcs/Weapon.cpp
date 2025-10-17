/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arvoyer <arvoyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 17:38:11 by arvoyer           #+#    #+#             */
/*   Updated: 2024/10/19 20:03:44 by arvoyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.h"

Weapon::Weapon()
{
	_type = "\0";
}

Weapon::Weapon(std::string type)
{
	_type = type;
}

const std::string	&Weapon::getType()
{
	return (_type);
}

void	Weapon::setType(std::string type)
{
	_type = type;
}

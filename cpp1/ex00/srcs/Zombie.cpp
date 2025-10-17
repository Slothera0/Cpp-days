/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arvoyer <arvoyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 16:46:52 by arvoyer           #+#    #+#             */
/*   Updated: 2024/10/19 16:59:04 by arvoyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.h"
#include <iostream>

Zombie::Zombie()
{
	_name = "\0";
}

Zombie::Zombie(std::string name)
{
	_name = name;
}

Zombie::~Zombie()
{
	std::cout << "Zombie " << _name << " has been deleted" << std::endl;
}

void	Zombie::set_name(std::string name)
{
	_name = name;
}

void	Zombie::annonce(void)
{
	std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

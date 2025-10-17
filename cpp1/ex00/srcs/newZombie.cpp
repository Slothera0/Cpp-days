/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newZombie.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arvoyer <arvoyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 16:54:31 by arvoyer           #+#    #+#             */
/*   Updated: 2024/10/19 16:57:17 by arvoyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.h"

Zombie*	newZombie( std::string name )
{
	Zombie *newborn;
	newborn = new Zombie(name);
	return (newborn);
}

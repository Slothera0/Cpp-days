/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   randomChump.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arvoyer <arvoyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 16:54:29 by arvoyer           #+#    #+#             */
/*   Updated: 2024/10/19 17:00:52 by arvoyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.h"

void randomChump( std::string name )
{
	Zombie newborn(name);
	
	newborn.annonce();
}
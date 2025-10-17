/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arvoyer <arvoyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 18:37:09 by arvoyer           #+#    #+#             */
/*   Updated: 2024/10/20 18:37:21 by arvoyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.h"

Zombie* zombieHorde( int N, std::string name )
{
	Zombie	*newborn;
	
	newborn = new Zombie[N];
	for (int i = 0; i < N; i++)
	{
		newborn[i].set_name(name);
	}
	return (newborn);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arvoyer <arvoyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 16:55:15 by arvoyer           #+#    #+#             */
/*   Updated: 2024/10/20 18:37:43 by arvoyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.h"

Zombie*	zombieHorde( int N, std::string name );

int	main()
{
	Zombie	*Karen;

	Karen = zombieHorde(4, "Karen");
	for (int i = 0; i < 4; i++)
		Karen[i].annonce();
	
	delete[] Karen;
	
	return (0);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arvoyer <arvoyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 16:55:15 by arvoyer           #+#    #+#             */
/*   Updated: 2024/10/19 17:03:43 by arvoyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.h"

Zombie* newZombie( std::string name );
void randomChump( std::string name );

int	main()
{
	Zombie	*Brian;

	Brian = newZombie("Brian");
	Brian->annonce();
	delete Brian;
	
	randomChump("Peter");
	randomChump("Roberto");
	randomChump("Henri");
	return (0);
}
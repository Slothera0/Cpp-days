/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arvoyer <arvoyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 15:58:15 by arvoyer           #+#    #+#             */
/*   Updated: 2024/11/21 16:32:17 by arvoyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.h"

int	main()
{
	ClapTrap	Dave("Dave");
	
	Dave.attack("Jhon");
	Dave.takeDamage(9);
	Dave.beRepaired(9);
	
	for (int i = 0; i < 10; i++)
	{
		Dave.takeDamage(1);
		Dave.beRepaired(1);
	}

	Dave.takeDamage(99999);
	Dave.beRepaired(99999999);
	
	return (0);
}
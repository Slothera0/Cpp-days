/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arvoyer <arvoyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 15:58:15 by arvoyer           #+#    #+#             */
/*   Updated: 2024/11/27 05:00:48 by arvoyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.h"
#include "ScavTrap.h"

int	main()
{
	ScavTrap	Dave("Dave");
	
	Dave.attack("Jhon");
	Dave.takeDamage(9);
	Dave.beRepaired(9);

	Dave.takeDamage(99999);
	Dave.beRepaired(99999999);
	Dave.guardGate();
	
	return (0);
}
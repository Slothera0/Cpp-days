/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arvoyer <arvoyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 15:58:15 by arvoyer           #+#    #+#             */
/*   Updated: 2024/11/27 05:08:12 by arvoyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.h"
#include "FragTrap.h"

int	main()
{
	FragTrap	Dave("Dave");
	
	Dave.attack("Jhon");
	Dave.takeDamage(9);
	Dave.beRepaired(9);

	Dave.takeDamage(99999);
	Dave.beRepaired(99999999);
	Dave.highFivesGuys();
	
	return (0);
}
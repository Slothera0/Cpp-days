/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arvoyer <arvoyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 14:49:55 by arvoyer           #+#    #+#             */
/*   Updated: 2024/10/20 15:29:40 by arvoyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.h"

void Harl::complain( std::string level )
{
	std::string	strs[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	size_t		i = 0;
	
	for(int j = 0; j < 4; j++)
	{
		if (strs[j] == level)
			i = j + 1;
	}
	
	switch (i)
	{
		case 1:
			this->debug();
		case 2:
			this->info();
		case 3:
			this->warning();
		case 4:
			this->error();
			break ;
		default:
			std::cout << "your level didn't match with any enregistred level" << std::endl;
	}
}

void Harl::debug( void )
{
	std::cout << "[ DEBUG ]" << std::endl \
		<< "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!" << std::endl << std::endl;
}

void Harl::info( void )
{
	std::cout << "[ INFO ]" << std::endl \
		<< "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl << std::endl;
}

void Harl::warning( void )
{
	std::cout << "[ WARNING ]" << std::endl \
		<< "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << std::endl << std::endl;
}

void Harl::error( void )
{
	std::cout << "[ ERROR ]" << std::endl \
		<< "This is unacceptable! I want to speak to the manager now." << std::endl;
}

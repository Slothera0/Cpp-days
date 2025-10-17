/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arvoyer <arvoyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 14:49:55 by arvoyer           #+#    #+#             */
/*   Updated: 2024/10/20 15:16:54 by arvoyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.h"

void Harl::complain( std::string level )
{
	void		(Harl::*function[4])(void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	std::string	strs[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	for (int i = 0; i < 4; i++)
	{
		if (strs[i] == level)
		{
			(this->*function[i])();
			return ;
		}
	}
	std::cout << "your level didn't match with any enregistred level" << std::endl;
}

void Harl::debug( void )
{
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!" << std::endl;
}

void Harl::info( void )
{
	std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

void Harl::warning( void )
{
	std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << std::endl;
}

void Harl::error( void )
{
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

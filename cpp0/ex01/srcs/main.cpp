/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arvoyer <arvoyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 08:28:19 by arvoyer           #+#    #+#             */
/*   Updated: 2024/10/03 04:20:33 by arvoyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.h"
#include "Contact.h"
#include <iostream>
#include <cstdlib>

int main()
{
    bool    	stop;
	PhoneBook	book;
	std::string	input;
	int			nb_ctt;

    stop = false;
	nb_ctt = 0;
    while (stop == false)
    {
		std::cout << "Enter your order:";
		std::getline(std::cin, input);
		if (std::cin.eof())
			exit(0);
		if (input == "ADD")
		{
			book.add(nb_ctt);
			nb_ctt++;
			if (nb_ctt >= 8)
				nb_ctt = 0;
		}
		if (input == "SEARCH")
			book.search();
		if (input == "EXIT")
			stop = true;
    }
	return (0);
}

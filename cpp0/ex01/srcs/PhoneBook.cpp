/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arvoyer <arvoyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 08:33:39 by arvoyer           #+#    #+#             */
/*   Updated: 2024/10/14 16:34:56 by arvoyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.h"
#include <cstdlib>
#include <string>

void	PhoneBook::add(int nb_ctt)
{
	this->contact[nb_ctt].change_first_name(this->ask("Enter a name:\0"));
	this->contact[nb_ctt].change_last_name(this->ask("Enter a last name:"));
	this->contact[nb_ctt].change_nick_name(this->ask("Enter a nick name:"));
	this->contact[nb_ctt].change_phone_number(this->ask("Enter a phone number:"));
	this->contact[nb_ctt].change_darkest_secret(this->ask("Enter a darkest secret:"));
}

void	PhoneBook::search()
{
	this->print();
}

std::string	PhoneBook::ask(std::string question)
{
	std::string	temp;

	while (true)
	{
		std::cout << question;
		std::getline(std::cin, temp);
		if (std::cin.eof())
			exit(0);
		if (temp != "\0")
			break ;
	}
	return (temp);
}

void	PhoneBook::print()
{
	std::string	index;
	
	std::cout << "|     Index|First name| Last name| Nick name|" << std::endl;
	for (int i = 0; i < 8; i++)
	{
		std::cout << "|         " << i + 1 << "|";
		this->contact[i].print_first_name(10);
		std::cout << "|";
		this->contact[i].print_last_name(10);
		std::cout << "|";
		this->contact[i].print_nick_name(10);
		std::cout << "|" << std::endl;
	}
	index = this->ask("Which contact do you want to see?");
	if (index[0] < '0' || index[0] > '9' || atoi(index.c_str()) < 1 || atoi(index.c_str()) > 8)
		std::cout << "the string :'" << index << "' doesn't match with any contact index." << std::endl;
	else
		this->contact[atoi(index.c_str()) - 1].print();
}

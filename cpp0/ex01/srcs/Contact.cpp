/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arvoyer <arvoyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 08:02:58 by arvoyer           #+#    #+#             */
/*   Updated: 2024/10/14 16:27:45 by arvoyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.h"

Contact::Contact()
{
    this->first_name = "\0";
	this->last_name = "\0";
	this->nick_name = "\0";
	this->phone_number = "\0";
    this->darkest_secret = "\0";
}

void	Contact::change_first_name(std::string str)
{
	this->first_name = str;
}

void	Contact::change_last_name(std::string str)
{
	this->last_name = str;
}

void	Contact::change_nick_name(std::string str)
{
	this->nick_name = str;
}

void	Contact::change_phone_number(std::string str)
{
	this->phone_number = str;
}

void	Contact::change_darkest_secret(std::string str)
{
	this->darkest_secret = str;
}

void	Contact::print_first_name(int n)
{
	unsigned long	i;
	
	if (n == -1)
		n = this->first_name.length();
	for (i = 0; i + (unsigned long)n < 10 || i + this->first_name.length() < 10; i++)
		std::cout << " ";
	for (i = 0; i + 1 < (unsigned long)n && i + 1 < this->first_name.length(); i++)
		std::cout << this->first_name[i];
	if (this->first_name.length() > (unsigned long)n)
		std::cout << ".";
	else if (this->first_name.length() > 0)
		std::cout << this->first_name[this->first_name.length() - 1];
}

void	Contact::print_last_name(int n)
{
	unsigned long	i;
	
	if (n == -1)
		n = this->last_name.length();
	for (i = 0; i + (unsigned long)n < 10 || i + this->last_name.length() < 10; i++)
		std::cout << " ";
	for (i = 0; i + 1 < (unsigned long)n && i + 1 < this->last_name.length(); i++)
		std::cout << this->last_name[i];
	if (this->last_name.length() > (unsigned long)n)
		std::cout << ".";
	else if (this->last_name.length() > 0)
		std::cout << this->last_name[this->last_name.length() - 1];
}

void	Contact::print_nick_name(int n)
{
	unsigned long	i;
	
	if (n == -1)
		n = this->nick_name.length();
	for (i = 0; i + (unsigned long)n < 10 || i + this->nick_name.length() < 10; i++)
		std::cout << " ";
	for (i = 0; i + 1 < (unsigned long)n && i + 1 < this->nick_name.length(); i++)
		std::cout << this->nick_name[i];
	if (this->nick_name.length() > (unsigned long)n)
		std::cout << ".";
	else if (this->nick_name.length() > 0)
		std::cout << this->nick_name[this->nick_name.length() - 1];
}

void	Contact::print_phone_number(int n)
{
	unsigned long	i;
	
	if (n == -1)
		n = this->phone_number.length();
	for (i = 0; i + (unsigned long)n < 10 || i + this->phone_number.length() < 10; i++)
		std::cout << " ";
	for (i = 0; i + 1 < (unsigned long)n && i + 1 < this->phone_number.length(); i++)
		std::cout << this->phone_number[i];
	if (this->phone_number.length() > (unsigned long)n)
		std::cout << ".";
	else if (this->phone_number.length() > 0)
		std::cout << this->phone_number[this->phone_number.length() - 1];
}

void	Contact::print_darkest_secret(int n)
{
	unsigned long	i;
	
	if (n == -1)
		n = this->darkest_secret.length();
	for (i = 0; i + (unsigned long)n < 10 || i + this->darkest_secret.length() < 10; i++)
		std::cout << " ";
	for (i = 0; i + 1 < (unsigned long)n && i + 1 < this->darkest_secret.length(); i++)
		std::cout << this->darkest_secret[i];
	if (this->darkest_secret.length() > (unsigned long)n)
		std::cout << ".";
	else if (this->darkest_secret.length() > 0)
		std::cout << this->darkest_secret[this->darkest_secret.length() - 1];
}

void	Contact::print()
{
	std::cout << "|    First name|";
	this->print_first_name(-1);
	std::cout << std::endl << "|     Last name|";
	this->print_last_name(-1);
	std::cout << std::endl << "|     Nick name|";
	this->print_nick_name(-1);
	std::cout << std::endl << "|  Phone number|";
	this->print_phone_number(-1);
	std::cout << std::endl << "|Darkest secret|";
	this->print_darkest_secret(-1);
	std::cout << std::endl;
}

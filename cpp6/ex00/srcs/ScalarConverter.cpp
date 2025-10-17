/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arvoyer <arvoyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 10:48:24 by arvoyer           #+#    #+#             */
/*   Updated: 2025/01/22 03:23:33 by arvoyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <iostream>
#include <cstdlib>
#include <cctype>

void	print_char(double number, char *endptr);
void	print_int(double number, char *endptr);
void	print_float(double number, char *endptr);
void	print_double(double number, char *endptr);

ScalarConverter::ScalarConverter(void)
{
	
}

ScalarConverter::ScalarConverter(ScalarConverter &copy)
{
	*this = copy;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter &other)
{
	(void)other;
	return (*this);
}
		
ScalarConverter::~ScalarConverter(void)
{
	
}

void	ScalarConverter::convert(std::string s)
{
	double 	number;
	char	*endptr = NULL;

	if (s.length() == 1 && s[0] == '0')
		number = 0;
	if (s.length() == 1 && isprint(s[0]) && !isdigit(s[0]))
		number = s[0];
	else
		number = std::strtod(s.c_str(), &endptr);

	if (endptr && !endptr[0])
		endptr = NULL;
	//std::cout << static_cast<int>(number) << ";" << number << ";" << (static_cast<int>(number) == number) << (endptr == NULL) << std::endl;
	print_char(number, endptr);
	print_int(number, endptr);
	print_float(number, endptr);
	print_double(number, endptr);
}
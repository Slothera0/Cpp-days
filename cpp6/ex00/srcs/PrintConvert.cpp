/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PrintConvert.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arvoyer <arvoyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 00:50:29 by arvoyer           #+#    #+#             */
/*   Updated: 2025/01/22 10:28:19 by arvoyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits>
#include <cstdlib>
#include <iostream>
#include <limits>
#include <iomanip>
#include <cmath>

void	print_char(double number, char *endptr)
{
	std::cout << "char: ";	
	if (number == static_cast<int>(number) && !(endptr && !(endptr[0] == 'f' && !endptr[1])))
	{
		if (number > 0 && number < std::numeric_limits<char>::max() && isprint(number))
			std::cout << "'" << static_cast<char>(number) << "'";
		else
			std::cout << "Non displayable";
	}
	else
		std::cout << "impossible";
	std::cout << std::endl;

}

void	print_int(double number, char *endptr)
{
	std::cout << "int: ";
	if (number != static_cast<int>(number) || (endptr && !(endptr[0] == 'f' && !endptr[1])))
		std::cout << "impossible";
	else
		std::cout << static_cast<int>(number);
	std::cout << std::endl;
}

void	print_float(double number, char *endptr)
{
	std::cout << "float: ";
	if (endptr && !(endptr[0] == 'f' && !endptr[1]))
		std::cout << "impossible";
	else if (number == static_cast<int>(number) || std::fabs(number) < 1e6)
		std::cout << std::fixed << std::setprecision(1) << static_cast<float>(number) << "f";
	else
		std::cout << std::scientific << std::setprecision(5) << static_cast<float>(number) << "f";
	std::cout << std::endl;
}

void	print_double(double number, char *endptr)
{
	std::cout << "double: ";
	if (endptr && !(endptr[0] == 'f' && !endptr[1]))
		std::cout << "impossible";
	else if (number == static_cast<int>(number) || std::fabs(number) < 1e6)
		std::cout << std::fixed << std::setprecision(1) << number;
	else
		std::cout << std::scientific << std::setprecision(5) << number;
	std::cout << std::endl;
}
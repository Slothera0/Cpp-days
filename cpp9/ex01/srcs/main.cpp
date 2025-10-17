/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arvoyer <arvoyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 01:45:48 by arvoyer           #+#    #+#             */
/*   Updated: 2025/03/28 14:33:51 by arvoyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include <iostream>

int	main(int argc, char **argv)
{
	if (argc == 1)
		return (0);

	RPN a;
	try
	{
		std::cout << a.calculate(argv[1]) << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << "Error" << std::endl;
	}

	return (0);
}
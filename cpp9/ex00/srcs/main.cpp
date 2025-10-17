/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arvoyer <arvoyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 15:05:46 by arvoyer           #+#    #+#             */
/*   Updated: 2025/03/28 14:11:30 by arvoyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int	main(int argc, char **argv)
{
	if (argc == 1)
	{
		std::cerr << "Error: need a file" << std::endl;
		return (0);
	}
	
	try
	{
		BitcoinExchange	b;
		std::string DB(argv[1]);
		b.parseDB(DB);
	}
	catch(const std::exception& e)
	{
		std::cerr << "Error: can't open the file" << '\n';
	}
	
	return (0);
}

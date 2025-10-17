/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arvoyer <arvoyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 20:20:29 by arvoyer           #+#    #+#             */
/*   Updated: 2025/01/28 18:10:26 by arvoyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"
#include <exception>

int	main()
{
	Array<int>	a(5);

	for (int i = 0; i < 5; i++)
		a[i] = i;

	for (int i = 0; i < 5; i++)
		std::cout << a[i] << std::endl;

	std::cout << std::endl << a.size() << std::endl;
	
	try{
		std::cout << a[6];
	}
	catch (const std::exception& e)
	{
		std::cerr << "Out of range" << std::endl;
	}

	const Array<int> b(a);

	for (int i = 0; i < 5; i++)
		std::cout << b[i] << std::endl;
		
	std::cout << std::endl << b.size() << std::endl;
}
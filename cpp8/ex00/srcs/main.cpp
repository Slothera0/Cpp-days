/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arvoyer <arvoyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 17:52:05 by arvoyer           #+#    #+#             */
/*   Updated: 2025/02/18 12:43:57 by arvoyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <vector>
#include <deque>
#include <iostream>

int	main()
{
	std::vector<int> a;
	std::deque<int> b(1, 10);

	for (int i = 0; i < 10; i++)
	{
		a.push_back(i);
		b.push_back(i);
	}
	for (std::vector<int>::iterator i = a.begin(); i != a.end(); i++)
		std::cout << *i << " ";
	std::cout << std::endl;
	for (std::deque<int>::iterator i = b.begin(); i != b.end(); i++)
		std::cout << *i << " ";
	std::cout << std::endl;
	
	try
	{
		std::cout << easyfind(a, 5) << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << "Fail to find the value" << std::endl;
	}

	try
	{
		std::cout << easyfind(a, 55) << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << "Fail to find the value" << std::endl;
	}

	try
	{
		std::cout << easyfind(b, 5) << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << "Fail to find the value" << std::endl;
	}

	try
	{
		std::cout << easyfind(b, 55) << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << "Fail to find the value" << std::endl;
	}
	
}
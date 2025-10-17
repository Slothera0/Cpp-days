/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arvoyer <arvoyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 12:50:43 by arvoyer           #+#    #+#             */
/*   Updated: 2025/02/18 14:00:15 by arvoyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib>
#include "Span.hpp"

int main()
{
	Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << "Shortest span :" << sp.shortestSpan() << std::endl;
	std::cout << "Longest span :" << sp.longestSpan() << std::endl;

	std::vector<int> list;

	srand(time(NULL));
	for (int i = 0; i < 50000; i++)
	{
		list.push_back(rand() % 100000);
	}

	// for (std::vector<int>::iterator i = list.begin(); i != list.end(); i++)
	// {
	// 	std::cout << *i << " - " ;
	// }

	std::cout << std::endl;

	sp.addArray(list.begin(), list.end());

	std::cout << "Shortest span :" << sp.shortestSpan() << std::endl;
	std::cout << "Longest span :" << sp.longestSpan() << std::endl;
	std::cout << "Size :" << sp.size() << std::endl;
}
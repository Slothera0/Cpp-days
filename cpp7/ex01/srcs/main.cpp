/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arvoyer <arvoyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 15:35:34 by arvoyer           #+#    #+#             */
/*   Updated: 2025/01/23 15:47:44 by arvoyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"
#include <iostream>

void	print_int(int x);
void	print_c(char c);

int	main()
{
	int 		a[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	std::string	b = "Salut";

	iter(a, 10, &print_int);
	std::cout << std::endl;
	iter(b, 5, &print_c);
	std::cout << std::endl;
}

void	print_c(char c)
{
	std::cout << c << ";";
}

void	print_int(int x)
{
	std::cout << x << ",";
}
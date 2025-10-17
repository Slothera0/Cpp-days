/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arvoyer <arvoyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 04:18:32 by arvoyer           #+#    #+#             */
/*   Updated: 2025/03/27 12:49:02 by arvoyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <ctime>

int	main(int argc, char **argv)
{
	PmergeMe list;
	
	if (argc == 1)
		return (0);

	try
	{
		clock_t begin_v = std::clock();
		list.fill_vector(++argv);
		std::cout << "Before: ";
		list.show_vector();
		list.sort_vector(1);
		clock_t end_v = std::clock();
		std::cout << std::endl << "After: ";
		list.show_vector();
		clock_t begin_l = std::clock();
		list.fill_list(argv);
		std::cout << std::endl << "Before: ";
		list.show_list();
		list.sort_list(1);
		clock_t end_l = std::clock();
		std::cout << std::endl << "After: ";
		list.show_list();
		double duration_v = 1000.0 * (end_v - begin_v) / CLOCKS_PER_SEC;
		double duration_l = 1000.0 * (end_l - begin_l) / CLOCKS_PER_SEC;
		std::cout << "Time to process with std::vector: " << duration_v << " ms" << std::endl;
		std::cout << "Time to process with std::list: " << duration_l << " ms" << std::endl;
	}
	catch (std::exception & e)
	{
		std::cerr << e.what() << std::endl;
	}
}
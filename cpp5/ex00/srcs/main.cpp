/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arvoyer <arvoyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 15:06:28 by arvoyer           #+#    #+#             */
/*   Updated: 2025/01/07 02:59:36 by arvoyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <iostream>

int	main()
{
	Bureaucrat B;
	std::cout << B;

	try 
	{
		Bureaucrat Jhon("Jhon", 12);
		std::cout << Jhon;
	}
	catch (std::exception &e)
	{
		std::cout << "Error : " << e.what() << std::endl;
	}
	
	std::cout << std::endl << "-------------------------------------------" << std::endl << std::endl;

	try 
	{
		Bureaucrat Jhon("Jhon", 151);
		std::cout << Jhon;
	}
	catch (std::exception &e)
	{
		std::cout << "Error : " << e.what() << std::endl;
	}

	std::cout << std::endl << "-------------------------------------------" << std::endl << std::endl;

	try 
	{
		Bureaucrat Jhon("Jhon", 2);
		std::cout << Jhon;
		Jhon.increaseGrade();
		std::cout << Jhon;
		Jhon.increaseGrade();
	}
	catch (std::exception &e)
	{
		std::cout << "Error : " << e.what() << std::endl;
	}
}
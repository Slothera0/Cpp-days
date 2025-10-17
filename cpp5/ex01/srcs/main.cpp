/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arvoyer <arvoyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 15:06:28 by arvoyer           #+#    #+#             */
/*   Updated: 2025/01/10 05:21:17 by arvoyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int	main()
{
	Bureaucrat B;
	std::cout << B;

	std::cout << std::endl << "-------------------------------------------" << std::endl << std::endl;

	try 
	{
		Bureaucrat Jhon("Jhon", 12);
		std::cout << Jhon;
		Bureaucrat JhonBis(Jhon);
		std::cout << JhonBis;
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

	std::cout << std::endl << "-------------------------------------------" << std::endl << std::endl;

	Form f;
	std::cout << f;

	std::cout << std::endl << "-------------------------------------------" << std::endl << std::endl;

	try 
	{
		Form form("form A", 42, 42);
		std::cout << form;
		Form formBis(form);
		std::cout << formBis;
	}
	catch (std::exception &e)
	{
		std::cout << "Error : " << e.what() << std::endl;
	}

	std::cout << std::endl << "-------------------------------------------" << std::endl << std::endl;

	try 
	{
		Form form("form A", 151, 42);
		std::cout << form;
	}
	catch (std::exception &e)
	{
		std::cout << "Error : " << e.what() << std::endl;
	}

	std::cout << std::endl << "-------------------------------------------" << std::endl << std::endl;

	try 
	{
		Form form("form A", 42, 0);
		std::cout << form;
	}
	catch (std::exception &e)
	{
		std::cout << "Error : " << e.what() << std::endl;
	}

	std::cout << std::endl << "-------------------------------------------" << std::endl << std::endl;

	try 
	{
		Form form("form A", 42, 42);
		std::cout << form;
		Bureaucrat Jhon("Jhon", 2);
		std::cout << Jhon;
		Jhon.signForm(form);
		std::cout << form;
	}
	catch (std::exception &e)
	{
		std::cout << "Error : " << e.what() << std::endl;
	}

	std::cout << std::endl << "-------------------------------------------" << std::endl << std::endl;

	try 
	{
		Form form("form A", 42, 42);
		std::cout << form;
		Bureaucrat Jhon("Jhon", 43);
		std::cout << Jhon;
		Jhon.signForm(form);
		std::cout << form;
	}
	catch (std::exception &e)
	{
		std::cout << "Error : " << e.what() << std::endl;
	}
}
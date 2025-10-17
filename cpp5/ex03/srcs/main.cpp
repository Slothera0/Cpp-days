/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arvoyer <arvoyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 15:06:28 by arvoyer           #+#    #+#             */
/*   Updated: 2025/01/10 07:29:36 by arvoyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"
#include <iostream>

int	main()
{
	Bureaucrat Jhon("Jhon", 1);
	Bureaucrat Bob("Bob", 150);

	ShrubberyCreationForm S("home");
	PresidentialPardonForm P("Nobody");
	RobotomyRequestForm R("You");

	Jhon.executeForm(S);
	Jhon.signForm(S);
	Jhon.executeForm(S);

	Jhon.signForm(P);
	Jhon.signForm(R);
	
	Jhon.executeForm(P);
	Jhon.executeForm(R);
	Bob.executeForm(P);

	std::cout << std::endl << "-------------------------------------------" << std::endl << std::endl;

	Intern Timothe;
	AForm *F = Timothe.makeForm("robotomy request", "You");

	Jhon.signForm(*F);
	Jhon.executeForm(*F);

	delete F;
}
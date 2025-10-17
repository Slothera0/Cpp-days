/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arvoyer <arvoyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 07:12:33 by arvoyer           #+#    #+#             */
/*   Updated: 2025/01/22 10:22:26 by arvoyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern(void)
{
	
}

Intern::Intern(Intern &copy)
{
	*this = copy;
}

Intern& Intern::operator=(const Intern &other)
{
	(void)other;
	return (*this);
}

Intern::~Intern(void)
{
	
}

AForm *Intern::makeForm(std::string FormName, std::string target)
{
	AForm *newForm;

	std::string	strs[3] = {"robotomy request", "shrubbery creation", "presidential pardon"};
	size_t		i = 0;
		
	for(int j = 0; j < 3; j++)
	{
	if (strs[j] == FormName)
			i = j + 1;
	}
	
	newForm = NULL;
	switch (i)
	{
		case 1:
			newForm = new RobotomyRequestForm(target);
			break ;
		case 2:
			newForm = new ShrubberyCreationForm(target);
			break ;
		case 3:
			newForm = new PresidentialPardonForm(target);
			break ;
		default:
			std::cout << "This Form doesn't exist !" << std::endl;
	}

	if (newForm != NULL)
		std::cout << "Intern create " << newForm->getName() << std::endl;

	return (newForm);
}
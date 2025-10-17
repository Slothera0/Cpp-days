/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arvoyer <arvoyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 06:04:11 by arvoyer           #+#    #+#             */
/*   Updated: 2025/01/10 07:09:14 by arvoyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include <cstdlib>

RobotomyRequestForm::RobotomyRequestForm(void) : AForm("RobotomyRequestForm", 72, 45), _target("none")
{

}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", 72, 45), _target(target)
{

}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm &copy) : AForm(copy), _target(copy._target)
{
	
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
	if (this != &other)
	{
		AForm::operator=(other);
	}
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm(void)
{
	
}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	if (executor.getGrade() > this->getGradeToExecute())
		throw AForm::GradeTooLowException();
	if (this->getIsSigned() == false)
		throw AForm::NotSignedException();

	srand(time(0));
	if (rand() % 2 == 0)
		std::cout << this->_target << " has been robotomized" << std::endl;
	else
		std::cout << "The robotomy failed" << std::endl;
}
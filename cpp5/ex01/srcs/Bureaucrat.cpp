/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arvoyer <arvoyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 15:06:08 by arvoyer           #+#    #+#             */
/*   Updated: 2025/01/10 05:18:53 by arvoyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

Bureaucrat::Bureaucrat(void) : _name("Unknown"), _grade(MIN_GRADE)
{
	
}

Bureaucrat::Bureaucrat(Bureaucrat &copy) : _name(copy._name), _grade(copy._grade)
{
	
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name)
{
	if (grade > MIN_GRADE)
		throw Bureaucrat::GradeTooLowException();
	if (grade < MAX_GRADE)
		throw Bureaucrat::GradeTooHighException();
	_grade = grade;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat &other)
{
	if (this != &other)
		this->_grade = other._grade;
	return (*this);
}

Bureaucrat::~Bureaucrat(void)
{
	
}

const std::string Bureaucrat::getName() const
{
	return (_name);
}

int Bureaucrat::getGrade() const
{
	return (_grade);
}

void	Bureaucrat::increaseGrade()
{
	if (_grade == MAX_GRADE)
		throw Bureaucrat::GradeTooHighException();
	_grade--;
}

void	Bureaucrat::decreaseGrade()
{
	if (_grade == MIN_GRADE)
		throw Bureaucrat::GradeTooLowException();
	_grade++;
}

void	Bureaucrat::signForm(Form& f)
{
	try
	{
		f.beSigned(*this);
		std::cout << this->_name << " signed " << f.getName() << std::endl;
	}
	catch (std::exception & e)
	{
		std::cout << this->_name << " couldn’t sign " << f.getName() << " because " << e.what() << std::endl;
	}
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Grade too low");
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Grade too high");
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b)
{
	os << b.getName() << ", bureaucrat grade " << b.getGrade() << "." << std::endl;
	return (os);
}
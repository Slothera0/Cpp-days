/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arvoyer <arvoyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 03:22:13 by arvoyer           #+#    #+#             */
/*   Updated: 2025/01/10 05:18:16 by arvoyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(void) : _name("Unnamed"), _isSigned(false), _gradeToSign(MIN_GRADE), _gradeToExecute(MAX_GRADE)
{
	
}

Form::Form(Form &copy) : _name(copy._name), _isSigned(copy._isSigned), _gradeToSign(copy._gradeToSign), _gradeToExecute(copy._gradeToExecute)
{
	
}

Form::Form(std::string name, int gradeToSign, int gradeToExecute) : _name(name), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
	if (gradeToSign < MAX_GRADE || gradeToExecute < MAX_GRADE)
		throw Form::GradeTooHighException();
	if (gradeToSign > MIN_GRADE || gradeToExecute > MIN_GRADE)
		throw Form::GradeTooLowException();
}

Form& Form::operator=(const Form &other)
{
	if (this != &other)
	{
		this->_isSigned = other._isSigned;
	}
	return (*this);
}

Form::~Form(void)
{
	
}

std::string	Form::getName() const
{
	return (_name);
}

bool Form::getIsSigned() const
{
	return (_isSigned);
}

int	Form::getGradeoSign() const
{
	return (_gradeToSign);
}

int Form::getGradeToExecute() const
{
	return (_gradeToExecute);
}

void	Form::beSigned(const Bureaucrat b)
{
	if (b.getGrade() > this->_gradeToSign)
		throw Form::GradeTooLowException();
	this->_isSigned = true;
}

const char *Form::GradeTooLowException::what() const throw()
{
	return ("Grade too low");
}

const char *Form::GradeTooHighException::what() const throw()
{
	return ("Grade too high");
}

std::ostream& operator<<(std::ostream& os, const Form& f)
{
	os << f.getName() << ", form is signed " << f.getIsSigned() <<", form grade to sign " << f.getGradeoSign()\
		<< ", form grade to execute " << f.getGradeToExecute() << "." << std::endl;
	return (os);
}
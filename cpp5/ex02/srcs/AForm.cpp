/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arvoyer <arvoyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 03:22:13 by arvoyer           #+#    #+#             */
/*   Updated: 2025/01/10 07:00:51 by arvoyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm(void) : _name("Unnamed"), _isSigned(false), _gradeToSign(MIN_GRADE), _gradeToExecute(MAX_GRADE)
{
	
}

AForm::AForm(AForm &copy) : _name(copy._name), _isSigned(copy._isSigned), _gradeToSign(copy._gradeToSign), _gradeToExecute(copy._gradeToExecute)
{
	
}

AForm::AForm(std::string name, int gradeToSign, int gradeToExecute) : _name(name), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
	if (gradeToSign < MAX_GRADE || gradeToExecute < MAX_GRADE)
		throw AForm::GradeTooHighException();
	if (gradeToSign > MIN_GRADE || gradeToExecute > MIN_GRADE)
		throw AForm::GradeTooLowException();
}

AForm& AForm::operator=(const AForm &other)
{
	if (this != &other)
	{
		this->_isSigned = other._isSigned;
	}
	return (*this);
}

AForm::~AForm(void)
{
	
}

std::string	AForm::getName() const
{
	return (_name);
}

bool AForm::getIsSigned() const
{
	return (_isSigned);
}

int	AForm::getGradeoSign() const
{
	return (_gradeToSign);
}

int AForm::getGradeToExecute() const
{
	return (_gradeToExecute);
}

void	AForm::beSigned(const Bureaucrat b)
{
	if (b.getGrade() > this->_gradeToSign)
		throw AForm::GradeTooLowException();
	this->_isSigned = true;
}

const char *AForm::GradeTooLowException::what() const throw()
{
	return ("Grade too low");
}

const char *AForm::GradeTooHighException::what() const throw()
{
	return ("Grade too high");
}

const char *AForm::NotSignedException::what() const throw()
{
	return ("Form not signed");
}

std::ostream& operator<<(std::ostream& os, const AForm& f)
{
	os << f.getName() << ", form is signed " << f.getIsSigned() <<", form grade to sign " << f.getGradeoSign()\
		<< ", form grade to execute " << f.getGradeToExecute() << "." << std::endl;
	return (os);
}
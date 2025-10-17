/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arvoyer <arvoyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 03:12:58 by arvoyer           #+#    #+#             */
/*   Updated: 2025/01/10 06:22:50 by arvoyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

#include "Bureaucrat.hpp"
#include <exception>
#include <iostream>
#include <string>

class AForm
{
	public:
		AForm(void);
		AForm(AForm &copy);
		AForm(std::string name, int gradeToSign, int gradeToExecute);
		AForm& operator=(const AForm &other);
		virtual ~AForm(void);

		std::string	getName() const;
		bool		getIsSigned() const;
		int			getGradeoSign() const;
		int			getGradeToExecute() const;
		void		beSigned(const Bureaucrat b);

		virtual void execute(Bureaucrat const & executor) const = 0;
	private:
		const std::string 	_name;
		bool				_isSigned;
		const int			_gradeToSign;
		const int			_gradeToExecute;
	
	protected:
		class GradeTooHighException: public std::exception
		{
				virtual const char* what(void) const throw();
		};
		class GradeTooLowException: public std::exception
		{
				virtual const char* what(void) const throw();
		};
		class NotSignedException: public std::exception
		{
				virtual const char* what(void) const throw();
		};
};

std::ostream& operator<<(std::ostream& os, const AForm& f);

#endif
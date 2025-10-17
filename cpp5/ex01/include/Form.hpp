/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arvoyer <arvoyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 03:12:58 by arvoyer           #+#    #+#             */
/*   Updated: 2025/01/10 05:18:21 by arvoyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

#include <exception>
#include <iostream>
#include <string>
#include "Bureaucrat.hpp"

class Form
{
	public:
		Form(void);
		Form(Form &copy);
		Form(std::string name, int gradeToSign, int gradeToExecute);
		Form& operator=(const Form &other);
		~Form(void);

		std::string	getName() const;
		bool		getIsSigned() const;
		int			getGradeoSign() const;
		int			getGradeToExecute() const;

		void	beSigned(const Bureaucrat b);
	private:
		const std::string 	_name;
		bool				_isSigned;
		const int			_gradeToSign;
		const int			_gradeToExecute;
	
		class GradeTooHighException: public std::exception
		{
				virtual const char* what(void) const throw();
		};
		class GradeTooLowException: public std::exception
		{
				virtual const char* what(void) const throw();
		};
};

std::ostream& operator<<(std::ostream& os, const Form& f);

#endif
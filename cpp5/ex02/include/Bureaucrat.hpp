/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arvoyer <arvoyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 15:06:11 by arvoyer           #+#    #+#             */
/*   Updated: 2025/01/10 07:06:59 by arvoyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <exception>
#include <iostream>
#include <string>

#define MAX_GRADE 1
#define MIN_GRADE 150

class AForm;

class Bureaucrat
{
	public:
		Bureaucrat(void);
		Bureaucrat(Bureaucrat &copy);
		Bureaucrat(std::string name, int grade);
		Bureaucrat& operator=(const Bureaucrat &other);
		~Bureaucrat(void);

		const std::string	getName() const;
		int			 		getGrade() const;
		void				increaseGrade();
		void				decreaseGrade();
		
		void				signForm(AForm& f);
		void				executeForm(AForm const & form) const;
		
	private:
		const std::string	_name;
		int					_grade;

		class GradeTooHighException: public std::exception
		{
				virtual const char* what(void) const throw();
		};
		class GradeTooLowException: public std::exception
		{
				virtual const char* what(void) const throw();
		};
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b);

#endif
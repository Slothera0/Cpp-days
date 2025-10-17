/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arvoyer <arvoyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 12:50:55 by arvoyer           #+#    #+#             */
/*   Updated: 2025/02/18 13:58:07 by arvoyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

#include <vector>
#include <exception>
#include <algorithm>
#include <iostream>

class Span
{
	public:
		Span(void);
		Span(unsigned int N);
		Span(const Span &copy);
		Span& operator=(const Span &other);
		~Span(void);

		void	addNumber(int x);
		void	addArray(std::vector<int>::iterator first, std::vector<int>::iterator last);
		int		shortestSpan();
		int		longestSpan();
		int		size();

	private:
		unsigned int _len;
		std::vector<int> _list;

		class SpanFull: public std::exception
		{
			virtual const char* what(void) const throw();
		};

		class NotEnoughNumbers: public std::exception
		{
			virtual const char* what(void) const throw();
		};
};

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arvoyer <arvoyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 12:50:48 by arvoyer           #+#    #+#             */
/*   Updated: 2025/02/18 13:58:42 by arvoyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(void)
{
	_len = 10;
}

Span::Span(unsigned int N)
{
	_len = N;
}

Span::Span(const Span &copy)
{
	*this = copy;
}

Span& Span::operator=(const Span &other)
{
	this->_list = other._list;
	this->_len = other._len;
	return (*this);
}

Span::~Span(void) {}

void Span::addNumber(int x)
{
	if (_list.size() == _len)
		throw SpanFull();
	_list.push_back(x);
}

int Span::shortestSpan()
{
	if (_list.size() <= 1)
		throw NotEnoughNumbers();
	std::vector<int> temp = _list;
	std::sort(temp.begin(), temp.end());
	
	int	shortest = temp[1] - temp[0];
	for (std::vector<int>::iterator i = temp.begin() + 2; i != temp.end(); i++)
	{
		if (*i - *(i - 1) < shortest)
			shortest = *i - *(i - 1);
	}

	return (shortest);
}

int Span::longestSpan()
{
	if (_list.size() <= 1)
		throw NotEnoughNumbers();
	return (*std::max_element(_list.begin(), _list.end()) - *std::min_element(_list.begin(), _list.end()));
}

void	Span::addArray(std::vector<int>::iterator first, std::vector<int>::iterator last)
{
	_list.insert(_list.end(), first, last);
}

int	Span::size()
{
	return (_list.size());
}

const char* Span::SpanFull::what() const throw()
{
	return ("Span is full");
}

const char* Span::NotEnoughNumbers::what() const throw()
{
	return ("Not enough numbers to compare");
}

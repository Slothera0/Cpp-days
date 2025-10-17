/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arvoyer <arvoyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 04:19:06 by arvoyer           #+#    #+#             */
/*   Updated: 2025/03/26 19:07:56 by arvoyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe(void) {}

PmergeMe::PmergeMe(PmergeMe &copy)
{
	*this = copy;	
}

PmergeMe& PmergeMe::operator=(const PmergeMe &other)
{
	if (this != &other)
	{
		this->_vector = other._vector;
		this->_list = other._list;
	}
	return (*this);
}

PmergeMe::~PmergeMe(void) {}

const char *PmergeMe::InvalidInput::what() const throw()
{
	return ("Not a valid input");
}

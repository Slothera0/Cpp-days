/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arvoyer <arvoyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 20:13:28 by arvoyer           #+#    #+#             */
/*   Updated: 2024/11/19 15:10:54 by arvoyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.h"
#include <iostream>
#include <cmath>

Fixed::Fixed(void)
{
	std::cout << "Default constructor called" << std::endl;
	
	_RawBits = 0;
}

Fixed::Fixed(const Fixed &copy)
{
	std::cout << "Copy constructor called" << std::endl;

	this->_RawBits = copy.getRawBits();
}

Fixed::Fixed(const int nb)
{
	std::cout << "Int constructor called" << std::endl;
	
	_RawBits = nb << _fractionalBits;
}

Fixed::Fixed(const float nb)
{
	std::cout << "Float constructor called" << std::endl;
	
	_RawBits = roundf(nb * (1 << _fractionalBits));
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
}

Fixed& Fixed::operator=(const Fixed &other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	
	if (this != &other)
		this->_RawBits = other.getRawBits();
	return (*this);
}

int	Fixed::getRawBits( void ) const
{
	std::cout << "getRawBits member function called" << std::endl;
	
	return (_RawBits);
}

void	Fixed::setRawBits( int const raw )
{
	std::cout << "setRawBits member function called" << std::endl;
	
	_RawBits = raw;
}

float	Fixed::toFloat( void ) const
{
	return ((float)(_RawBits) / (1 << _fractionalBits));
}

int		Fixed::toInt( void ) const
{
	return (_RawBits >> _fractionalBits);
}

std::ostream& operator<<(std::ostream& os, const Fixed& nb)
{
	os << nb.toFloat();
	return (os);
}

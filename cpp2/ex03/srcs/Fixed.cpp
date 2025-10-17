/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arvoyer <arvoyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 20:13:28 by arvoyer           #+#    #+#             */
/*   Updated: 2024/11/19 17:21:45 by arvoyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.h"
#include <iostream>
#include <cmath>

//-------------------------Constructors&Destructor----------------------------//

Fixed::Fixed(void)
{
	_RawBits = 0;
}

Fixed::Fixed(const Fixed &copy)
{
	this->_RawBits = copy.getRawBits();
}

Fixed::Fixed(const int nb)
{
	_RawBits = nb << _fractionalBits;
}

Fixed::Fixed(const float nb)
{
	_RawBits = roundf(nb * (1 << _fractionalBits));
}

Fixed::~Fixed(void)
{
}

//-----------------------------Operators--------------------------------------//

Fixed& Fixed::operator=(const Fixed &other)
{
	if (this != &other)
		this->_RawBits = other.getRawBits();
	return (*this);
}

bool	Fixed::operator>(const Fixed &other)
{	
	return (this->_RawBits > other._RawBits);
}

bool	Fixed::operator<(const Fixed &other)
{
	return (this->_RawBits < other._RawBits);
}

bool	Fixed::operator>=(const Fixed &other)
{
	return (this->_RawBits >= other._RawBits);
}

bool	Fixed::operator<=(const Fixed &other)
{
	return (this->_RawBits <= other._RawBits);
}

bool	Fixed::operator==(const Fixed &other)
{
	return (this->_RawBits == other._RawBits);
}

bool	Fixed::operator!=(const Fixed &other)
{
	return (this->_RawBits != other._RawBits);
}

Fixed Fixed::operator+(const Fixed &other)
{
	Fixed	temp;
	
	temp.setRawBits(this->getRawBits() + other.getRawBits());
	return (temp);
}

Fixed Fixed::operator-(const Fixed &other)
{
	Fixed	temp;
	
	temp.setRawBits(this->getRawBits() - other.getRawBits());
	return (temp);
}

Fixed Fixed::operator*(const Fixed &other)
{
	Fixed	temp;
	
	temp.setRawBits(this->getRawBits() * (other.getRawBits() >> _fractionalBits));
	return (temp);
}

Fixed Fixed::operator/(const Fixed &other)
{
	Fixed	temp;
	
	if (other.getRawBits() == 0)
	{
		std::cout << "Can't divide by 0" << std::endl;
		return (*this);
	}
	temp.setRawBits((this->getRawBits() << _fractionalBits) / other.getRawBits());
	return (temp);
}

Fixed	Fixed::operator++(int)
{
	Fixed	temp(*this);

	this->_RawBits += 1;
	return (temp);
}

Fixed	Fixed::operator--(int)
{
	Fixed	temp(*this);

	this->_RawBits -= 1;
	return (temp);
}

Fixed&	Fixed::operator++()
{
	this->_RawBits += 1;
	return (*this);
}

Fixed&	Fixed::operator--()
{
	this->_RawBits -= 1;
	return (*this);
}

//----------------------------------------------------------------------------//

Fixed& Fixed::min(Fixed &f1, Fixed &f2)
{
	if (f1.getRawBits() < f2.getRawBits())
		return (f1);
	return (f2);
}

const Fixed& Fixed::min(const Fixed &f1, const Fixed &f2)
{
	if (f1.getRawBits() < f2.getRawBits())
		return (f1);
	return (f2);
}

Fixed& Fixed::max(Fixed &f1, Fixed &f2)
{
	if (f1.getRawBits() > f2.getRawBits())
		return (f1);
	return (f2);
}

const Fixed& Fixed::max(const Fixed &f1, const Fixed &f2)
{
	if (f1.getRawBits() > f2.getRawBits())
		return (f1);
	return (f2);	
}

//----------------------------------------------------------------------------//

int	Fixed::getRawBits( void ) const
{
	return (_RawBits);
}

void	Fixed::setRawBits( int const raw )
{
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

//---------------------------------------------------------------------------//

std::ostream& operator<<(std::ostream& os, const Fixed& nb)
{
	os << nb.toFloat();
	return (os);
}

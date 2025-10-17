/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arvoyer <arvoyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 16:35:27 by arvoyer           #+#    #+#             */
/*   Updated: 2024/11/19 17:21:50 by arvoyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.h"

Point::Point(void) : _x(0), _y(0)
{
	
}

Point::Point(const Point &copy) : _x(copy._x), _y(copy._y)
{
	
}

Point::Point(const float x, const float y) : _x(x), _y(y)
{
	
}

Point::~Point(void)
{
}

Point& 	Point::operator=(const Point &other)
{
	(void)other;
	return (*this);
}

float	Point::getX(void) const
{
	return (this->_x.toFloat());
}

float	Point::getY(void) const
{
	return (this->_y.toFloat());
}
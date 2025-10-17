/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arvoyer <arvoyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 16:55:46 by arvoyer           #+#    #+#             */
/*   Updated: 2024/11/19 17:22:56 by arvoyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.h"
#include <cmath>

float triangle_area(Point const a, Point const b, Point const c);

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
	float	areaABC = triangle_area(a, b, c);

	float	areaABP = triangle_area(a, b, point);
	float	areaBCP = triangle_area(b, c, point);
	float	areaCAD = triangle_area(c, a, point);

	if (areaABC == areaABP + areaBCP + areaCAD)
		return (true);
	return (false);
}

float triangle_area(Point const a, Point const b, Point const c)
{
	return (0.5 * (std::abs(a.getX() * (b.getY() - c.getY()) + b.getX() * (c.getY() - a.getY()) + c.getX() * (a.getY() - b.getY()))));
}
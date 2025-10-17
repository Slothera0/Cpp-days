/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arvoyer <arvoyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 16:33:57 by arvoyer           #+#    #+#             */
/*   Updated: 2024/11/19 17:09:02 by arvoyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_H
# define POINT_H

#include "Fixed.h"

class Point
{
	public:
		Point(void);
		Point(const Point &copy);
		Point(const float x, const float y);
		~Point(void);

		Point& 	operator=(const Point &other);

		float	getX(void) const;
		float	getY(void) const;
	private:
		const Fixed	_x;
		const Fixed	_y;
};

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arvoyer <arvoyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 16:56:22 by arvoyer           #+#    #+#             */
/*   Updated: 2024/11/19 17:29:48 by arvoyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.h"
#include <iostream>

bool bsp( Point const a, Point const b, Point const c, Point const point);

int	main()
{
	Point a(10, 5);
	Point b(0, 0);
	Point c(10, 0);
	Point point1(1, 0);
	Point point2(0, 0);
	Point point3(1, 1);
	Point point4(0.01, 0);
	Point point5(0, 0.01);
	Point point6(10, 0);
	Point point7(10, 5);
	std::cout << bsp(a,b,c, point1) << std::endl;
	std::cout << bsp(a,b,c, point2) << std::endl;
	std::cout << bsp(a,b,c, point3) << std::endl;
	std::cout << bsp(a,b,c, point4) << std::endl;
	std::cout << bsp(a,b,c, point5) << std::endl;
	std::cout << bsp(a,b,c, point6) << std::endl;
	std::cout << bsp(a,b,c, point7) << std::endl;
	return (0);
}
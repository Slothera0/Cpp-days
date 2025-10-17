/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arvoyer <arvoyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 05:09:21 by arvoyer           #+#    #+#             */
/*   Updated: 2025/01/22 10:22:04 by arvoyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>

Base * generate(void);
void identify(Base* p);
void identify(Base& p);

int	main()
{
	Base 	*base;
	A		a;
	B		b;
	C		c;	

	std::srand(std::time(NULL));

	identify(a);
	std::cout << ";";
	identify(&a);
	std::cout << std::endl;

	identify(b);
	std::cout << ";";
	identify(&b);
	std::cout << std::endl;

	identify(c);
	std::cout << ";";
	identify(&c);
	std::cout << std::endl << std::endl;

	for (int i = 0; i < 10; i++)
	{
		base = generate();
		identify(base);
		std::cout << ";";
		identify(*base);
		std::cout << std::endl;
		
		delete base;
	}
	
}

Base * generate(void)
{
	int	random = std::rand() % 3;
	switch (random)
	{
		case 0:
			return (new A);
		case 1:
			return (new B);
		default:
			return (new C);
	}
		
}

void identify(Base* p)
{
	if (dynamic_cast<A*>(p) != NULL)
		std::cout << "A";
	else if (dynamic_cast<B*>(p) != NULL)
		std::cout << "B";
	else if (dynamic_cast<C*>(p) != NULL)
		std::cout << "C";
}

void identify(Base& p)
{
	try
	{
		static_cast<void>(dynamic_cast<const A&>(p));
		std::cout << "A";
		return;
	}
	catch (const std::exception& error) {}
	try
	{
		static_cast<void>(dynamic_cast<const B&>(p));
		std::cout << "B";
		return;
	}
	catch (const std::exception& error) {}
	try
	{
		static_cast<void>(dynamic_cast<const C&>(p));
		std::cout << "C";
		return;
	}
	catch (const std::exception& error) {}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arvoyer <arvoyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 06:18:00 by arvoyer           #+#    #+#             */
/*   Updated: 2024/12/10 16:14:10 by arvoyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "Animal.h"
#include "Cat.h"
#include "Dog.h"

int	main()
{
	Animal	*Zoo[10];

	for (int i = 0; i < 5; i++)
	{
		Zoo[i] = new Dog();
	}
	for (int i = 5; i < 10; i++)
	{
		Zoo[i] = new Cat();
	}
	for (int i = 0; i < 10; i++)
	{
		Zoo[i]->makeSound();
	}

	for (int i = 0; i < 10; i++)
	{
		delete(Zoo[i]);
	}

	std::cout << std::endl;

	Dog dog;
	Dog copy;
	
	dog.add_idea("Manger");
	dog.show_ideas();
	
	for (int i = 0; i < 100; i++)
	{
		dog.add_idea("Manger");
	}

	std::cout << std::endl;

	copy = dog;

	dog.show_ideas();
	copy.show_ideas();
}

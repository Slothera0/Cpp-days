/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arvoyer <arvoyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 09:55:46 by arvoyer           #+#    #+#             */
/*   Updated: 2024/12/10 16:10:40 by arvoyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "Brain.h"

Brain::Brain(void)
{
	std::cout << "A new Brain is created" << std::endl;
}

Brain::Brain(Brain &copy)
{
	for (size_t i = 0; i < 100; i++)
	{
		this->_ideas[i] = copy._ideas[i];
	}
	std::cout << "A new Brain is created" << std::endl;
}

Brain& Brain::operator=(const Brain &other)
{
	if (this != &other)
	{
		for (size_t i = 0; i < 100; i++)
		{
			this->_ideas[i] = other._ideas[i];
		}
	}
	return (*this);
}

Brain::~Brain(void)
{
	std::cout << "A Brain was destroyed" << std::endl;
}

void Brain::add_idea(std::string std)
{
	int	i;

	i = 0;
	while (i < 100 && _ideas[i] != "\0")
		i++;
	if (i < 100)
		_ideas[i] = std;
	else
		std::cout << "This brain is already full" << std::endl;
}

void Brain::show_brain(void)
{
	std::cout << "Brain content:" << std::endl;
	for (int i = 0; i < 100; i++)
	{
		std::cout << _ideas[i] << std::endl;
	}
	std::cout << "End of the brain" << std::endl;
}

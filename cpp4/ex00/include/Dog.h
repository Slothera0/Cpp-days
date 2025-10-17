/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arvoyer <arvoyer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 23:21:45 by arvoyer           #+#    #+#             */
/*   Updated: 2024/12/02 06:58:28 by arvoyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_H
# define DOG_H

#include "Animal.h"

class Dog : virtual public Animal
{
	public:
		Dog(void);
		Dog(Dog &copy);
		Dog& operator=(const Dog &other);
		~Dog(void);

		void	setType(std::string type);
		void	makeSound(void) const;
};

#endif